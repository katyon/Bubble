// インクルード ----------------------------------------------------------------------------------
#include "DxLib.h"

#include "input.h"
#include "manage.h"
#include "main.h"
#include "system.h"

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
}

void SelectManager::update(void)
{
    if (change)
    {
        M_System.changeSceneStateInit(State_Game);
    }

}

void SelectManager::draw(void)
{

}

void SelectManager::end(void)
{

}
// Game
void GameManager::init(void)
{
    change = false;
    clear = false;
}

void GameManager::update(void)
{
    if (clear == true)
    {

    }
}

void GameManager::draw(void)
{

}

void GameManager::end(void)
{

}