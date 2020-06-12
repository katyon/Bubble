// インクルード ----------------------------------------------------------------------------------
#include "DxLib.h"

#include "bg.h"
#include "bubble.h"
#include "goals.h"
#include "input.h"
#include "manage.h"
#include "map.h"
#include "main.h"
#include "system.h"
#include "water_current.h"
#include "waterSource.h"

// 関数 ----------------------------------------------------------------------------------------
// Title
void TitleManager::init(void)
{
    change = false;
}

void TitleManager::update(void)
{
    if (M_Input->GetKeyDown(KEY_INPUT_SPACE))
    {
        change = true;
    }
    if (change)
    {
        M_System.changeSceneStateInit(State_Choice);
    }
}

void TitleManager::draw(void)
{

}

void TitleManager::end(void)
{

}
// Select
void SelectManager::init(void)
{
    change = false;
    cr = GetColor(0, 0, 0);
}

void SelectManager::update(void)
{
    if (change)
    {
        M_System.changeSceneStateInit(State_Game);
    }
    if (M_Input->GetKeyDown(KEY_INPUT_BACK))
    {
        M_System.changeSceneStateInit(State_Title);
    }
}

void SelectManager::draw(void)
{
    SetFontSize(50);
    DrawFormatString(1350, 1020, cr, "タイトルへ：BackSpace");
}

void SelectManager::end(void)
{

}
// Game
void GameManager::init(void)
{
    change = false;
    clear = false;
    cr = GetColor(0, 0, 0);
}

void GameManager::update(void)
{
    if (M_Input->GetKeyDown(KEY_INPUT_BACK))
    {
        M_System.changeSceneStateInit(State_Choice);
    }
    if (M_Input->GetKeyDown(KEY_INPUT_R))
    {
        M_GameBg.init();
        M_Water_Current.init();
        M_Bubble.init();
        M_MapData.init();
        M_WaterSource.init();
        M_Goals.init();
        M_GameManager.init();
    }
    if (clear == true)
    {
        M_System.changeSceneStateInit(State_Title);
    }
}

void GameManager::draw(void)
{
    SetFontSize(50);

    DrawFormatString(1580, 970, cr, "リトライ：R");
    DrawFormatString(1220, 1030, cr, "ステージ選択へ：BackSpace");
}

void GameManager::end(void)
{

}