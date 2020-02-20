// インクルード ----------------------------------------------------------------------------------
#include "DxLib.h"

#include "common.h"
#include "input.h"
#include "main.h"
#include "scene_title.h"

// 関数 ----------------------------------------------------------------------------------------
void Title_Bg::init(void)
{
    this->handle = LoadGraph("Data\\Images\\Bg\\Title_Bg.png");
}

void Title_Bg::update(void)
{

}

void Title_Bg::draw(void)
{
    DrawGraphF(this->pos.x, this->pos.y, this->handle, true);
}

void Title_Bg::end(void)
{
    DeleteGraph(this->handle);
}

void Title_Debug::update(void)
{
    if (INPUT->GetKeyDown(KEY_INPUT_1)) USABLE.changeSceneStateInit(State_Title);
    if (INPUT->GetKeyDown(KEY_INPUT_2)) USABLE.changeSceneStateInit(State_Choice);
    if (INPUT->GetKeyDown(KEY_INPUT_3)) USABLE.changeSceneStateInit(State_Game);
}