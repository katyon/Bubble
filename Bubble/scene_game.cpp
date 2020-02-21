// インクルード ----------------------------------------------------------------------------------
#include "DxLib.h"

#include "common.h"
#include "input.h"
#include "main.h"
#include "scene_game.h"
#include "singleton.h"

// 関数 ----------------------------------------------------------------------------------------
void Game_Bg::init(void)
{
    this->handle = LoadGraph("Data\\Images\\Bg\\Game_Bg.png");
}

void Game_Bg::update(void)
{

}

void Game_Bg::draw(void)
{
    DrawGraphF(this->pos.x, this->pos.y, this->handle, true);
}

void Game_Bg::end(void)
{
    DeleteGraph(this->handle);
}

void Game_Debug::update(void)
{
    if (INPUT->GetKeyDown(KEY_INPUT_1)) USABLE.changeSceneStateInit(State_Title);
    if (INPUT->GetKeyDown(KEY_INPUT_2)) USABLE.changeSceneStateInit(State_Choice);
    if (INPUT->GetKeyDown(KEY_INPUT_3)) USABLE.changeSceneStateInit(State_Game);
}