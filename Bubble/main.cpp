#include "main.h"
#include "DxLib.h"

#include "bg.h"
#include "bubble.h"
#include "common.h"
#include "input.h"
#include "map.h"
#include "system.h"
#include "UI.h"

//////////////////////////////////////////////////////////////////////////
//	各ゲームで使用するクラスインスタンスやグローバル変数はここに記述
//

BubbleObj I_BubbleObj[BUBBLE_MAX];

//
// 定義ここまで
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
//	ここからタイトルの処理
//

// タイトル初期化処理
void Scene_Title::init(void)
{
    M_TitleBg.init();
}

// タイトル更新処理
void Scene_Title::update(void)
{
    M_TitleBg.update();
}

// タイトル描画処理
void Scene_Title::draw(void)
{
    M_TitleBg.draw();
}

// タイトル終了処理
void Scene_Title::end(void)
{
    M_TitleBg.end();
}

//
//	タイトルの処理ここまで
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
//	ここからステージ選択の処理
//

// ステージ選択初期化処理
void Scene_Choice::init(void)
{
    M_ChoiceBg.init();
}

// ステージ選択更新処理
void Scene_Choice::update(void)
{
    M_ChoiceBg.update();
}

// ステージ選択描画処理
void Scene_Choice::draw(void)
{
    M_ChoiceBg.draw();
}

// ステージ選択終了処理
void Scene_Choice::end(void)
{
    M_ChoiceBg.end();
}

//
//	ステージ選択の処理ここまで
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
//	ここからゲームの処理
//

// ゲーム初期化処理
void Scene_Game::init(void)
{
    M_MapData.init();
    M_GameBg.init();
    M_Bubble.init();
    M_UI.init();
}

// ゲーム更新処理
void Scene_Game::update(void)
{
    M_MapData.update();
    M_GameBg.update();
    M_Bubble.update();
    M_UI.update();
}

// ゲーム描画処理
void Scene_Game::draw(void)
{
    M_GameBg.draw();
    M_MapData.draw();
    M_Bubble.draw();
    M_UI.draw();
}

// ゲーム終了処理
void Scene_Game::end(void)
{
    M_MapData.end();
    M_GameBg.end();
    M_Bubble.end();
    M_UI.end();
}

//
//	ゲームの処理ここまで
//////////////////////////////////////////////////////////////////////////

// DirectX初期化前処理
void Usable::BeforeInit(void)
{
    //int mbResult;
    int win_mode = TRUE;
    //
    //// フルスクリーンにするか選択する
    //mbResult = MessageBox(NULL, STR_MSG_ASKFS, STR_MSGTTL_ASKFS, MB_YESNO);
    //if (mbResult == IDYES) win_mode = FALSE;
    ChangeWindowMode(win_mode);
    // ウィンドウタイトルを設定する
    SetMainWindowText(STR_WINTTL);
}

// ゲーム開始前処理
void Usable::AfterInit(void)
{
    // InputClass
    Input::Create();
    Input::GetInstance()->Init();

    sceneState = State_Title;
    M_SceneTitle.init();
}

// ゲーム終了後処理
void Usable::End(void)
{
    // InputClassの終了処理
    Input::Destroy();
    // 全グラフィックの削除
    DxLib::InitGraph();
    // 全音データの削除
    InitSoundMem();
}

// ゲームメインループ
void Usable::MainLoop(void)
{
    M_Usable.AfterInit();    // ゲーム開始前処理

    while (ProcessMessage() == 0)		    // ProcessMessageが正常に処理されている間はループ
    {
        ClearDrawScreen();  				// 裏画面を削除
        Input::GetInstance()->Updata();     // 入力状態の更新処理

        switch (sceneState)
        {
        case State_Title:
            M_SceneTitle.update();         // タイトル更新処理
            M_SceneTitle.draw();           // タイトル描画処理
            break;
        case State_Choice:
            M_SceneChoice.update();        // ステージ選択更新処理
            M_SceneChoice.draw();          // ステージ選択描画処理
            
            break;
        case State_Game:
            M_SceneGame.update();          // ゲーム更新処理
            M_SceneGame.draw();            // ゲーム描画処理
            break;
        }

        M_System.inputDebugKey();   // debug
        M_System.drawDebugString(); // debug
        ScreenFlip();   // VSYNCを待つ

        // ESCキーだけは常に監視。押されたら直ちに終了
        int stick = CheckHitKey(KEY_INPUT_ESCAPE);
        if (stick == 1) break;
        M_Usable.countGameTime();   // ゲームカウンタを進める
    }
}

// WinMain関数
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
    LPSTR lpCmdLine, int nCmdShow)
{
    M_Usable.BeforeInit();                // DirectX初期化前処理
    if (DxLib_Init() == -1) return -1;  // エラーが起きたら直ちに終了

    SetGraphMode(GAME_SCREEN_WIDTH, GAME_SCREEN_HEIGHT, 32);
    SetDrawScreen(DX_SCREEN_BACK);      // 描画スクリーンを裏側に指定
    SetWaitVSyncFlag(TRUE);             // VSYNCを有効にする
    M_Usable.AfterInit();                 // DirectX初期化後処理
    M_Usable.MainLoop();                  // ゲーム本体(メインループ)
    M_Usable.End();                       // ゲーム終了後処理
    DxLib_End();                        // ＤＸライブラリ使用の終了処理
    return 0;                           // ソフトの終了
}
