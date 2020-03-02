// インクルード --------------------------------------------------------}--------------------------
#include "DxLib.h"

#include "bubble.h"
#include "input.h"
#include "goals.h"
#include "manage.h"
#include "stage_select.h"
#include "system.h"

// extern宣言,static初期化 ----------------------------------------------------------------------
extern PlBubbleObj I_PlBubbleObj[PL_BUBBLE_MAX];
extern GoalsObj    I_GoalsObj[GOALS_MAX];

// 関数 ----------------------------------------------------------------------------------------
void GoalsObj::init(GoalsObj* obj, float posX, float posY, int Num)
{
    obj->pos.set(posX, posY);
    obj->num = Num;
    obj->rel_pos.set(posX + 32, posY + 32);
    obj->src.set(0, 0);
    obj->exist = false;
    obj->clear = false;
}

void Goals::init(void)
{
    for (int i = 0; i < GOALS_MAX; i++)
    {
        I_GoalsObj[i].init(&I_GoalsObj[i], 0, 0, 0);
    }
    switch (M_Stage_Select.select)
    {
    case 1:
        maxNum = 2;
        I_GoalsObj[0].init(&I_GoalsObj[0], 10 * 64, 64 * 1, 4);
        I_GoalsObj[1].init(&I_GoalsObj[1], 16 * 64, 64 ,3);
        break;
    case 2:
        maxNum = 2;
        I_GoalsObj[0].init(&I_GoalsObj[0], 2 * 64, 64 * 1, 6);
        I_GoalsObj[1].init(&I_GoalsObj[1], 26 * 64, 64, 5);
        break;
    case 3:
        maxNum = 1;
        I_GoalsObj[0].init(&I_GoalsObj[0], 24 * 64, 64 * 1, 12);
        break;
    case 4:
        maxNum = 3;
        I_GoalsObj[0].init(&I_GoalsObj[0], 6 * 64, 64 * 1, 3);
        I_GoalsObj[1].init(&I_GoalsObj[1], 14 * 64, 64, 3);
        I_GoalsObj[2].init(&I_GoalsObj[0], 24 * 64, 64 * 1, 4);
        break;
    case 5:
        maxNum = 3;
        break;
    default:
        maxNum = 1;
        break;
    }
    for (int i = 0; i < maxNum; i++)
    {
        I_GoalsObj[i].exist = true;
    }
    handle = LoadGraph("Data\\Images\\Sprite\\goals.png");
}

void Goals::update(void)
{
    switch (I_GoalsObj[0].num)
    {
    case 1:
        I_GoalsObj[0].src.set(0, 0);
        break;
    case 2:
        I_GoalsObj[0].src.set(300, 0);
        break;
    case 3:
        I_GoalsObj[0].src.set(600, 0);
        break;
    default:
        break;
    }
    switch (I_GoalsObj[1].num)
    {
    case 1:
        I_GoalsObj[1].src.set(0, 0);
        break;
    case 2:
        I_GoalsObj[1].src.set(300, 0);
        break;
    case 3:
        I_GoalsObj[1].src.set(600, 0);
        break;
    default:
        break;
    }
    switch (I_GoalsObj[2].num)
    {
    case 1:
        I_GoalsObj[2].src.set(0, 0);
        break;
    case 2:
        I_GoalsObj[2].src.set(300, 0);
        break;
    case 3:
        I_GoalsObj[2].src.set(600, 0);
        break;
    default:
        break;
    }

    for (int i = 0; i < PL_BUBBLE_MAX; i++)
    {
        if (I_PlBubbleObj[i].exist == false) continue;
        for (int j = 0; j < GOALS_MAX; j++)
        {
            if (I_GoalsObj[j].exist == false) continue;
            if (M_System.isCollCircleWithRect(I_PlBubbleObj[i].center, I_PlBubbleObj[i].radius, I_GoalsObj[j].pos, I_GoalsObj[j].rel_pos))
            {
                if (I_PlBubbleObj[i].level == I_GoalsObj[j].num) I_GoalsObj[j].clear = true;
            }
        }
    }
    switch (maxNum)
    {
    case 1:
        if (I_GoalsObj[0].clear) M_GameManager.clear = true;
        break;
    case 2:
        if (I_GoalsObj[0].clear) M_GameManager.clear = true;
        if (I_GoalsObj[1].clear) M_GameManager.clear = true;
        break;
    case 3:
        if (I_GoalsObj[0].clear) M_GameManager.clear = true;
        if (I_GoalsObj[1].clear) M_GameManager.clear = true;
        if (I_GoalsObj[2].clear) M_GameManager.clear = true;
        break;
    default:
        break;
    }
}

void Goals::draw(void)
{
    switch (maxNum)
    {
    case 1:
        DrawRectExtendGraphF(I_GoalsObj[0].pos.x, I_GoalsObj[0].pos.y, I_GoalsObj[0].rel_pos.x, I_GoalsObj[0].rel_pos.x, I_GoalsObj[0].src.x, I_GoalsObj[0].src.y, 300, 300, handle, true);
        break;
    case 2:
        DrawRectExtendGraphF(I_GoalsObj[0].pos.x, I_GoalsObj[0].pos.y, I_GoalsObj[0].rel_pos.x, I_GoalsObj[0].rel_pos.x, I_GoalsObj[0].src.x, I_GoalsObj[0].src.y, 300, 300, handle, true);
        DrawRectExtendGraphF(I_GoalsObj[1].pos.x, I_GoalsObj[1].pos.y, I_GoalsObj[1].rel_pos.x, I_GoalsObj[1].rel_pos.x, I_GoalsObj[1].src.x, I_GoalsObj[1].src.y, 300, 300, handle, true);
        break;
    case 3:
        DrawRectExtendGraphF(I_GoalsObj[0].pos.x, I_GoalsObj[0].pos.y, I_GoalsObj[0].rel_pos.x, I_GoalsObj[0].rel_pos.x, I_GoalsObj[0].src.x, I_GoalsObj[0].src.y, 300, 300, handle, true);
        DrawRectExtendGraphF(I_GoalsObj[1].pos.x, I_GoalsObj[1].pos.y, I_GoalsObj[1].rel_pos.x, I_GoalsObj[1].rel_pos.x, I_GoalsObj[1].src.x, I_GoalsObj[1].src.y, 300, 300, handle, true);
        DrawRectExtendGraphF(I_GoalsObj[2].pos.x, I_GoalsObj[2].pos.y, I_GoalsObj[2].rel_pos.x, I_GoalsObj[2].rel_pos.x, I_GoalsObj[2].src.x, I_GoalsObj[2].src.y, 300, 300, handle, true);
        break;
    }
}

void Goals::end(void)
{
    DeleteGraph(handle);
}