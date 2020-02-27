// インクルード ----------------------------------------------------------------------------------
#include "DxLib.h"

#include "bubble.h"
#include "common.h"
#include "input.h"
#include "main.h"
#include "map.h"

// extern宣言,static初期化 ----------------------------------------------------------------------
extern BubbleObj I_BubbleObj[BUBBLE_MAX];

// 関数 ----------------------------------------------------------------------------------------
static int test_mapData[MAPCHIP_V_MAX][MAPCHIP_H_MAX] = //debug
{
    1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
    1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
};

void MapData::init(void)
{
    pos.set(MAPCHIP_SIZE, MAPCHIP_SIZE);
    src.set(MAPCHIP_SIZE, 0);
    width = MAPCHIP_SIZE;
    height = MAPCHIP_SIZE;
    handle = LoadGraph("Data\\Images\\Sprite\\MapChip.png");
}

void MapData::update(void)
{
    M_MapData.collMapChipWithBubble(&I_BubbleObj[0]);
    M_MapData.collMapChipWithBubble(&I_BubbleObj[1]);
}

void MapData::draw(void)
{
    for (int Ver = 0; Ver < MAPCHIP_V_MAX; Ver++)
    {
        for (int Hor = 0; Hor < MAPCHIP_H_MAX; Hor++)
        {
            DrawRectGraphF(pos.x * Hor, pos.y * Ver, src.x * test_mapData[Ver][Hor], src.y, width, height, handle, true, false, false);
        }
    }
}

void MapData::end(void)
{
    DeleteGraph(handle);
}

void MapData::setMapData(void)
{
    //for (int Ver = 0; Ver < MAPCHIP_V_MAX; Ver++
    //{
    //	for (int Hor = 0; Hor < MAPCHIP_H_MAX; Hor++)
    //	{
    //		mapData[Ver][Hor] = 0;
    //	}
    //}
}

void MapData::collMapChipWithBubble(BubbleObj* obj)
{
    //チップ当たり判定処理
    for (int Ver = 0; Ver < MAPCHIP_V_MAX; Ver++)
    {
        for (int Hor = 0; Hor < MAPCHIP_H_MAX; Hor++)
        {
            int chipLeft;
            int chipRight;
            int chipTop;
            int chipBottom;
            int bubbleCollLeft;
            int bubbleCollRight;
            int bubbleCollTop;
            int bubbleCollBottom;

            if (test_mapData[Ver][Hor] > 0)
            {
                //マップチップ4点座標
                chipLeft = Hor * MAPCHIP_SIZE;
                chipRight = (Hor + 1) * MAPCHIP_SIZE;
                chipTop = Ver * MAPCHIP_SIZE;
                chipBottom = (Ver + 1) * MAPCHIP_SIZE;
                //プレイヤー当たり判定部4点座標
                bubbleCollLeft = obj->pos.x;
                bubbleCollRight = obj->pos.x + obj->size;
                bubbleCollTop = obj->pos.y;
                bubbleCollBottom = obj->pos.y + obj->size;

                if (bubbleCollLeft + 5 < chipRight && bubbleCollRight - 5 > chipLeft&& bubbleCollTop < chipBottom && bubbleCollBottom > chipTop)
                {
                    //縦方向の押し戻し
                    if (obj->speed.y != 0)
                    {
                        if (obj->speed.y > 0)
                        {
                            if (bubbleCollLeft + 15 < chipRight && bubbleCollRight - 15 > chipLeft&& bubbleCollTop + 15 < chipBottom && bubbleCollBottom > chipTop)
                            {
                                //判定のあったチップの上方向にチップが存在しなければ処理を行う
                                if (test_mapData[Ver - 1][Hor] == 0 && Ver != 0)
                                {
                                    obj->pos.y = chipTop - obj->size;
                                    obj->speed.y = 0;
                                }
                            }
                        }
                        if (obj->speed.y < 0)
                        {
                            if (bubbleCollLeft + 15 < chipRight && bubbleCollRight - 15 > chipLeft&& bubbleCollTop < chipBottom && bubbleCollBottom - 15 > chipTop)
                            {
                                //判定のあったチップの下方向にチップが存在しなければ処理を行う
                                if (test_mapData[Ver + 1][Hor] == 0 && Ver != (MAPCHIP_V_MAX - 1))
                                {
                                    obj->pos.y = chipBottom;
                                    obj->speed.y = 0;
                                }
                            }
                        }
                    }
                }
                //押し戻し後のプレイヤー座標を再取得
                bubbleCollLeft = obj->pos.x;
                bubbleCollRight = obj->pos.x + obj->size;
                bubbleCollTop = obj->pos.y;
                bubbleCollBottom = obj->pos.y + obj->size;

                if (bubbleCollLeft < chipRight && bubbleCollRight > chipLeft&& bubbleCollTop + 15 < chipBottom && bubbleCollBottom - 15 > chipTop)
                {
                    //横方向の押し戻し処理
                    if (obj->speed.x != 0)
                    {
                        if (obj->speed.x > 0)
                        {
                            //判定のあったチップの左方向にチップが存在しなければ処理を行う
                            if (test_mapData[Ver][Hor - 1] == 0 && Hor != 0)
                            {
                                obj->pos.x = chipLeft - obj->size;
                            }
                        }
                        if (obj->speed.x < 0)
                        {
                            //判定のあったチップの右方向にチップが存在しなければ処理を行う
                            if (test_mapData[Ver][Hor + 1] == 0 && Hor != (MAPCHIP_H_MAX - 1))
                            {
                                obj->pos.x = chipRight;
                            }
                        }
                    }
                }
                //押し戻し後のプレイヤー座標を再取得
                bubbleCollLeft = obj->pos.x;
                bubbleCollRight = obj->pos.x + obj->size;
                bubbleCollTop = obj->pos.y;
                bubbleCollBottom = obj->pos.y + obj->size;

                //接地判定
                if (bubbleCollBottom == chipTop && bubbleCollRight > chipLeft&& bubbleCollLeft < chipRight)
                {
                    obj->touchFloor = true;
                }
            }
        }
    }
}