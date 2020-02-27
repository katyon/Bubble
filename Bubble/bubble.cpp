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
    obj->level = 1;
    obj->size = 0;
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
    I_BubbleObj[0].pos.set(100, 600);//debug
    I_BubbleObj[1].pos.set(200, 600);//debug
    I_BubbleObj[2].pos.set(300, 600);//debug
    I_BubbleObj[3].pos.set(400, 600);//debug

    I_BubbleObj[0].exist = true;//debug
    I_BubbleObj[1].exist = true;//debug
    I_BubbleObj[2].exist = true;//debug
    I_BubbleObj[3].exist = true;//debug
}

void Bubble::update(void)
{
    M_Bubble.collAnotherBubble();
    M_Bubble.inputDebugKey();
    for (int i = 0; i < BUBBLE_MAX; i++)
    {
        if (I_BubbleObj[i].exist == false) continue;

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
    //obj->speed.y -= BUOYANCY;
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
    // サイズ変換
    obj->size = obj->level * 16 + 16;
    // 座標変換
    obj->pos.x += obj->speed.x;
    obj->pos.y += obj->speed.y;
    obj->rel_pos.set(obj->pos.x + obj->size, obj->pos.y + obj->size);
}

void Bubble::collAnotherBubble(void)
{
    for (int i = 0; i < BUBBLE_MAX; i++)
    {
        if (I_BubbleObj[i].exist == false) continue;

        I_BubbleObj[i].touchBubble = false;
    }

    for (int i = 0; i < BUBBLE_MAX; i++)
    {
        if (I_BubbleObj[i].exist == false) continue;

        for (int j = i + 1; j < BUBBLE_MAX; j++)
        {
            if (I_BubbleObj[j].exist == false) continue;

            if (M_System.isCollRect(I_BubbleObj[i].pos, I_BubbleObj[i].rel_pos, I_BubbleObj[j].pos, I_BubbleObj[j].rel_pos))
            {
                I_BubbleObj[i].touchBubble = true;
                I_BubbleObj[i].level += I_BubbleObj[j].level;
                I_BubbleObj[j].exist = false;
            }
        }
    }
}

void Bubble::inputDebugKey(void)
{
    if (M_Input->GetKey(KEY_INPUT_Z))   I_BubbleObj[0].exist = true;
    if (M_Input->GetKey(KEY_INPUT_X))   I_BubbleObj[1].exist = true;
    if (M_Input->GetKey(KEY_INPUT_C))   I_BubbleObj[2].exist = true;
    if (M_Input->GetKey(KEY_INPUT_V))   I_BubbleObj[3].exist = true;

    if (M_Input->GetKey(KEY_INPUT_LEFT))    I_BubbleObj[0].speed.x -= BUBBLE_ACCEL;
    if (M_Input->GetKey(KEY_INPUT_RIGHT))   I_BubbleObj[0].speed.x += BUBBLE_ACCEL;
    if (M_Input->GetKey(KEY_INPUT_UP))      I_BubbleObj[0].speed.y -= BUBBLE_ACCEL;
    if (M_Input->GetKey(KEY_INPUT_DOWN))    I_BubbleObj[0].speed.y += BUBBLE_ACCEL;

    if (M_Input->GetKey(KEY_INPUT_A))   I_BubbleObj[1].speed.x -= BUBBLE_ACCEL;
    if (M_Input->GetKey(KEY_INPUT_D))   I_BubbleObj[1].speed.x += BUBBLE_ACCEL;
    if (M_Input->GetKey(KEY_INPUT_W))   I_BubbleObj[1].speed.y -= BUBBLE_ACCEL;
    if (M_Input->GetKey(KEY_INPUT_S))   I_BubbleObj[1].speed.y += BUBBLE_ACCEL;

    if (M_Input->GetKey(KEY_INPUT_F))   I_BubbleObj[2].speed.x -= BUBBLE_ACCEL;
    if (M_Input->GetKey(KEY_INPUT_H))   I_BubbleObj[2].speed.x += BUBBLE_ACCEL;
    if (M_Input->GetKey(KEY_INPUT_T))   I_BubbleObj[2].speed.y -= BUBBLE_ACCEL;
    if (M_Input->GetKey(KEY_INPUT_G))   I_BubbleObj[2].speed.y += BUBBLE_ACCEL;

    if (M_Input->GetKey(KEY_INPUT_J))   I_BubbleObj[3].speed.x -= BUBBLE_ACCEL;
    if (M_Input->GetKey(KEY_INPUT_L))   I_BubbleObj[3].speed.x += BUBBLE_ACCEL;
    if (M_Input->GetKey(KEY_INPUT_I))   I_BubbleObj[3].speed.y -= BUBBLE_ACCEL;
    if (M_Input->GetKey(KEY_INPUT_K))   I_BubbleObj[3].speed.y += BUBBLE_ACCEL;
}