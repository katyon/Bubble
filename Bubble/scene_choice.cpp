// インクルード ----------------------------------------------------------------------------------
#include "DxLib.h"

#include "common.h"
#include "input.h"
#include "main.h"
#include "scene_choice.h"

// 関数 ----------------------------------------------------------------------------------------
void Choice_Bg::init(void)
{
    this->handle = LoadGraph("Data\\Images\\Bg\\Choice_Bg.png");
}

void Choice_Bg::update(void)
{

}

void Choice_Bg::draw(void)
{
    DrawGraphF(this->pos.x, this->pos.y, this->handle, true);
}

void Choice_Bg::end(void)
{
    DeleteGraph(this->handle);
}

void Choice_Debug::update(void)
{
    if (INPUT->GetKeyDown(KEY_INPUT_1)) USABLE.changeSceneStateInit(State_Title);
    if (INPUT->GetKeyDown(KEY_INPUT_2)) USABLE.changeSceneStateInit(State_Choice);
    if (INPUT->GetKeyDown(KEY_INPUT_3)) USABLE.changeSceneStateInit(State_Game);
}