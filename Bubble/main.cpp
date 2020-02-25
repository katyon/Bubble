#include "main.h"
#include "DxLib.h"

#include "common.h"
#include "input.h"
#include "scene_choice.h"
#include "scene_game.h"
#include "scene_title.h"
#include "system.h"

//////////////////////////////////////////////////////////////////////////
//	各ゲームで使用するクラスインスタンスやグローバル変数はここに記述
//

Scene_Title     title;
Scene_Choice    choice;
Scene_Game      game;

Scene_State     state;

//
// 定義ここまで
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
//	ここからタイトルの処理
//

// タイトル初期化処理
void Scene_Title::init(void)
{
    TITLE_BG.init();
}

// タイトル更新処理
void Scene_Title::update(int GameTime)
{
    TITLE_BG.update();
    TITLE_DEBUG.update();
}

// タイトル描画処理
void Scene_Title::draw(int GameTime)
{
    TITLE_BG.draw();
}

// タイトル終了処理
void Scene_Title::end(void)
{
    TITLE_BG.end();
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
    CHOICE_BG.init();
}

// ステージ選択更新処理
void Scene_Choice::update(int GameTime)
{
    CHOICE_BG.update();
    CHOICE_DEBUG.update();
}

// ステージ選択描画処理
void Scene_Choice::draw(int GameTime)
{
    CHOICE_BG.draw();
}

// ステージ選択終了処理
void Scene_Choice::end(void)
{
    CHOICE_BG.end();
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
    GAME_BG.init();
}

// ゲーム更新処理
void Scene_Game::update(int GameTime)
{
    GAME_BG.update();
    GAME_DEBUG.update();
}

// ゲーム描画処理
void Scene_Game::draw(int GameTime)
{
    GAME_BG.draw();
}

// ゲーム終了処理
void Scene_Game::end(void)
{
    GAME_BG.end();
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

    state = State_Title;
    title.init();
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

// シーン遷移処理
void Usable::changeSceneStateInit(Scene_State next_num)
{
    // 現在のシーンの終了処理
    switch (state)
    {
    case State_Title:
        title.end();
        break;
    case State_Choice:
        choice.end();
        break;
    case State_Game:
        game.end();
        break;
    }

    // シーン遷移時に初期化
    switch (next_num)
    {
    case State_Title:
        title.init();
        break;
    case State_Choice:
        choice.init();
        break;
    case State_Game:
        game.init();
        break;
    }

    state = next_num;
}

int test_handle;
int mask_handle;


// ゲームメインループ
void Usable::MainLoop(void)
{
    unsigned int gameTime = 0;			// グローバルゲームカウンタ

    USABLE.AfterInit();    // ゲーム開始前処理

    while (ProcessMessage() == 0)		    // ProcessMessageが正常に処理されている間はループ
    {
        ClearDrawScreen();  				// 裏画面を削除
        Input::GetInstance()->Updata();     // 入力状態の更新処理

        switch (state)
        {
        case State_Title:
            title.update(gameTime);         // タイトル更新処理
            title.draw(gameTime);           // タイトル描画処理
            break;
        case State_Choice:
            choice.update(gameTime);        // ステージ選択更新処理
            choice.draw(gameTime);          // ステージ選択描画処理
            break;
        case State_Game:
            game.update(gameTime);          // ゲーム更新処理
            game.draw(gameTime);            // ゲーム描画処理
            break;
        }
        System::getInstance().drawDebugString(); // debug
        ScreenFlip();   // VSYNCを待つ

        // ESCキーだけは常に監視。押されたら直ちに終了
        int stick = CheckHitKey(KEY_INPUT_ESCAPE);
        if (stick == 1) break;
        gameTime++;						// ゲームカウンタを進める
    }
}

// WinMain関数
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
    LPSTR lpCmdLine, int nCmdShow)
{
    USABLE.BeforeInit();                // DirectX初期化前処理
    if (DxLib_Init() == -1) return -1;  // エラーが起きたら直ちに終了

    SetGraphMode(GAME_SCREEN_WIDTH, GAME_SCREEN_HEIGHT, 32);
    SetDrawScreen(DX_SCREEN_BACK);      // 描画スクリーンを裏側に指定
    SetWaitVSyncFlag(TRUE);             // VSYNCを有効にする
    USABLE.AfterInit();                 // DirectX初期化後処理
    USABLE.MainLoop();                  // ゲーム本体(メインループ)
    USABLE.End();                       // ゲーム終了後処理
    DxLib_End();                        // ＤＸライブラリ使用の終了処理
    return 0;                           // ソフトの終了
}
