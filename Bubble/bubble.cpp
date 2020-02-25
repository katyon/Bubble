// インクルード ----------------------------------------------------------------------------------
#include "DxLib.h"

#include "bubble.h"
#include "common.h"
#include "input.h"
#include "main.h"

// extern宣言,static初期化 ----------------------------------------------------------------------
extern BubbleObj I_BubbleObj[BUBBLE_MAX];

// 関数 ----------------------------------------------------------------------------------------
void Bubble::init(void)
{
    handle = LoadGraph("Data\\Images\\Sprite\\bubble.png");
    for (int i = 0; i < BUBBLE_MAX; i++)
    {
        I_BubbleObj[i].init(&I_BubbleObj[i]);
    }
}

void Bubble::update(void)
{
    for (int i = 0; i < BUBBLE_MAX; i++)
    {
        if (I_BubbleObj[i].exist == false) continue;

        M_Bubble.inputDebugKey(&I_BubbleObj[i]);
        M_Bubble.fix(&I_BubbleObj[i]);
    }
}

void Bubble::draw(void)
{
    for (int i = 0; i < BUBBLE_MAX; i++)
    {
        if (I_BubbleObj[i].exist == false) continue;

        DrawExtendGraphF(I_BubbleObj[i].pos.x, I_BubbleObj[i].pos.y, I_BubbleObj[i].rel_pos.x, I_BubbleObj[i].rel_pos.y, handle, true);
    }
}

void Bubble::end(void)
{
    DeleteGraph(handle);
}

void Bubble::fix(BubbleObj* obj)
{
    obj->rel_pos.set(obj->pos.x + BUBBLE_SIZE, obj->pos.y + BUBBLE_SIZE);
}

void Bubble::inputDebugKey(BubbleObj* obj)
{
    if (M_Input->GetKey(KEY_INPUT_LEFT))    obj->pos.x -= BUBBLE_SPEED_X;
    if (M_Input->GetKey(KEY_INPUT_RIGHT))   obj->pos.x += BUBBLE_SPEED_X;
    if (M_Input->GetKey(KEY_INPUT_UP))      obj->pos.y -= BUBBLE_SPEED_Y;
    if (M_Input->GetKey(KEY_INPUT_DOWN))    obj->pos.y += BUBBLE_SPEED_Y;
}

void BubbleObj::init(BubbleObj* obj)
{
    obj->pos.set(0, 0);
    obj->rel_pos.set(0, 0);
    obj->state = Stop;
    obj->exist = false;
}