// インクルード ----------------------------------------------------------------------------------
#include "DxLib.h"

#include "bubble.h"
#include "common.h"
#include "input.h"
#include "main.h"
#include "system.h"

// extern宣言,static初期化 ----------------------------------------------------------------------
extern BubbleObj I_BubbleObj[BUBBLE_MAX];

// 関数 ----------------------------------------------------------------------------------------
void BubbleObj::init(BubbleObj* obj, vec2f pos)
{
    obj->pos.set(pos.x, pos.y);
    obj->rel_pos.set(0, 0);
    obj->speed.set(0, 0);
    obj->state = Stop;
    obj->level = 0;
    obj->exist = false;
    obj->touchFloor = false;
    obj->touchBubble = false;
}

void Bubble::init(void)
{
    vec2f debugPos;
    debugPos.set(0, GAME_SCREEN_HEIGHT);
    handle = LoadGraph("Data\\Images\\Sprite\\bubble.png");
    for (int i = 0; i < BUBBLE_MAX; i++)
    {
        I_BubbleObj[i].init(&I_BubbleObj[i], debugPos);
    }
    I_BubbleObj[0].exist = true;//debug
    I_BubbleObj[1].exist = true;//debug
}

void Bubble::update(void)
{
    for (int i = 0; i < BUBBLE_MAX; i++)
    {
        if (I_BubbleObj[i].exist == false) continue;

        M_Bubble.inputDebugKey(&I_BubbleObj[i]);
        M_Bubble.move(&I_BubbleObj[i]);
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

void Bubble::move(BubbleObj* obj)
{
    // 浮力
    obj->speed.y -= BUOYANCY;
    // 減速
    if (obj->speed.x > 0.2) obj->speed.x -= BUBBLE_DECEL;
    if (obj->speed.x < -0.2) obj->speed.x += BUBBLE_DECEL;
    if (obj->speed.y > 0.2) obj->speed.y -= BUBBLE_DECEL;
    if (obj->speed.y < -0.2) obj->speed.y += BUBBLE_DECEL;
    if (obj->speed.x < 0.2 && obj->speed.x > -0.2) obj->speed.x = 0;
    if (obj->speed.y < 0.2 && obj->speed.y > -0.2) obj->speed.y = 0;
}

void Bubble::fix(BubbleObj* obj)
{
    // 速度制限
    if (obj->speed.x > BUBBLE_SPEED_MAX) obj->speed.x = BUBBLE_SPEED_MAX;
    if (obj->speed.x < -BUBBLE_SPEED_MAX) obj->speed.x = -BUBBLE_SPEED_MAX;
    if (obj->speed.y > BUBBLE_SPEED_MAX) obj->speed.y = BUBBLE_SPEED_MAX;
    if (obj->speed.y < -BUBBLE_SPEED_MAX) obj->speed.y = -BUBBLE_SPEED_MAX;
    // 座標変換
    obj->pos.x += obj->speed.x;
    obj->pos.y += obj->speed.y;
    obj->rel_pos.set(obj->pos.x + BUBBLE_SIZE, obj->pos.y + BUBBLE_SIZE);
}

void Bubble::collAnotherBubble(void)
{
    for (int i = 0; i < BUBBLE_MAX; i++)
    {
        if (I_BubbleObj[i].exist == false) continue;

        for (int j = 0; j < BUBBLE_MAX; j++)
        {
            if (I_BubbleObj[j].exist == false) continue;
            if (i = j) continue;

            if (M_System.isCollRect(I_BubbleObj[i].pos, I_BubbleObj[i].rel_pos, I_BubbleObj[j].pos, I_BubbleObj[j].rel_pos))
            {
                I_BubbleObj[i].touchBubble = true;
                I_BubbleObj[j].touchBubble = true;
            }
            else
            {
                //I_BubbleObj[i].touchBubble = false;
                //I_BubbleObj[j].touchBubble = false;
            }
        }
    }
}

void Bubble::inputDebugKey(BubbleObj* obj)
{
    if (M_Input->GetKey(KEY_INPUT_LEFT))    obj->speed.x -= BUBBLE_ACCEL;
    if (M_Input->GetKey(KEY_INPUT_RIGHT))   obj->speed.x += BUBBLE_ACCEL;
    if (M_Input->GetKey(KEY_INPUT_UP))      obj->speed.y -= BUBBLE_ACCEL;
    if (M_Input->GetKey(KEY_INPUT_DOWN))    obj->speed.y += BUBBLE_ACCEL;
}