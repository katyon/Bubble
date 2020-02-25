// インクルード ----------------------------------------------------------------------------------
#include "DxLib.h"

#include "bubble.h"
#include "common.h"
#include "input.h"
#include "main.h"

// static変数初期化 -----------------------------------------------------------------------------
int Bubble::handle;

// 関数 ----------------------------------------------------------------------------------------
void Bubble::init(Bubble* obj)
{
    obj->pos.set(0, 0);
    obj->rel_pos.set(0, 0);
    obj->state = Stop;
    obj->exist = false;
}

void Bubble::update(Bubble* obj)
{
    obj->inputDebugKey();
    obj->fix(obj);
}

void Bubble::draw(Bubble* obj)
{
    DrawExtendGraphF(obj->pos.x, obj->pos.y, obj->rel_pos.x, obj->rel_pos.y, Bubble::handle, true);
}

void Bubble::end(void)
{
    DeleteGraph(Bubble::handle);
}

void Bubble::fix(Bubble* obj)
{
    obj->rel_pos.set(obj->pos.x + BUBBLE_SIZE, obj->pos.y + BUBBLE_SIZE);
}

void Bubble::loadGraph(void)
{
    Bubble::handle = LoadGraph("Data\\Images\\Sprite\\bubble.png");
}

void Bubble::inputDebugKey(void)
{
    if (M_Input->GetKey(KEY_INPUT_LEFT))    pos.x -= BUBBLE_SPEED_X;
    if (M_Input->GetKey(KEY_INPUT_RIGHT))   pos.x += BUBBLE_SPEED_X;
    if (M_Input->GetKey(KEY_INPUT_UP))      pos.y -= BUBBLE_SPEED_Y;
    if (M_Input->GetKey(KEY_INPUT_DOWN))    pos.y += BUBBLE_SPEED_Y;
}