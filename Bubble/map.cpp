// �C���N���[�h ----------------------------------------------------------------------------------
#include "DxLib.h"

#include "bubble.h"
#include "common.h"
#include "input.h"
#include "main.h"
#include "map.h"

// �֐� ----------------------------------------------------------------------------------------
static int test_mapData[MAPCHIP_V_MAX][MAPCHIP_H_MAX] = //debug
{
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
    1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
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
    //for (int Ver = 0; Ver < MAPCHIP_V_MAX; Ver++)
    //{
    //	for (int Hor = 0; Hor < MAPCHIP_H_MAX; Hor++)
    //	{
    //		mapData[Ver][Hor] = 0;
    //	}
    //}
}

void MapData::collMapChipWithBubble(BubbleObj* obj)
{
    //�`�b�v�����蔻�菈��
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
                //�}�b�v�`�b�v4�_���W
                chipLeft = Hor * MAPCHIP_SIZE;
                chipRight = (Hor + 1) * MAPCHIP_SIZE;
                chipTop = Ver * MAPCHIP_SIZE;
                chipBottom = (Ver + 1) * MAPCHIP_SIZE;
                //�v���C���[�����蔻�蕔4�_���W
                bubbleCollLeft = obj->pos.x;
                bubbleCollRight = obj->pos.x + BUBBLE_SIZE;
                bubbleCollTop = obj->pos.y;
                bubbleCollBottom = obj->pos.y + BUBBLE_SIZE;

                if (bubbleCollLeft + 15 < chipRight && bubbleCollRight - 15 > chipLeft&& bubbleCollTop < chipBottom && bubbleCollBottom > chipTop)
                {
                    //�c�����̉����߂�
                    if (obj->speed.y != 0)
                    {
                        if (obj->speed.y > 0)
                        {
                            if (bubbleCollLeft + 15 < chipRight && bubbleCollRight - 15 > chipLeft&& bubbleCollTop + 199 < chipBottom && bubbleCollBottom > chipTop)
                            {
                                //����̂������`�b�v�̏�����Ƀ`�b�v�����݂��Ȃ���Ώ������s��
                                if ((test_mapData[Ver - 1][Hor] == 0 || test_mapData[Ver - 1][Hor] == 3 || test_mapData[Ver - 1][Hor] == 4 || test_mapData[Ver - 1][Hor] == 5) && Ver != 0)
                                {
                                    obj->pos.y = chipTop - BUBBLE_SIZE;
                                    obj->speed.y = 0;
                                }
                            }
                        }
                        if (obj->speed.y < 0)
                        {
                            if (bubbleCollLeft + 15 < chipRight && bubbleCollRight - 15 > chipLeft&& bubbleCollTop < chipBottom && bubbleCollBottom - 195 > chipTop)
                            {
                                //����̂������`�b�v�̉������Ƀ`�b�v�����݂��Ȃ���Ώ������s��
                                if ((test_mapData[Ver + 1][Hor] == 0 || test_mapData[Ver + 1][Hor] == 3 || test_mapData[Ver + 1][Hor] == 4 || test_mapData[Ver + 1][Hor] == 5) && Ver != (MAPCHIP_V_MAX - 1))
                                {
                                    obj->pos.y=chipBottom;
                                    obj->speed.y=0;
                                }
                            }
                        }
                    }
                }
                //�����߂���̃v���C���[���W���Ď擾
                bubbleCollLeft = obj->pos.x;
                bubbleCollRight = obj->pos.x + BUBBLE_SIZE;
                bubbleCollTop = obj->pos.y;
                bubbleCollBottom = obj->pos.y + BUBBLE_SIZE;

                if (bubbleCollLeft < chipRight && bubbleCollRight > chipLeft&& bubbleCollTop + 15 < chipBottom && bubbleCollBottom - 15 > chipTop)
                {
                    //�������̉����߂�����
                    if (obj->speed.x != 0)
                    {
                        if (obj->speed.x > 0)
                        {
                            //����̂������`�b�v�̍������Ƀ`�b�v�����݂��Ȃ���Ώ������s��
                            if ((test_mapData[Ver][Hor - 1] == 0 || test_mapData[Ver][Hor - 1] == 3 || test_mapData[Ver][Hor - 1] == 4 || test_mapData[Ver][Hor - 1] == 5) && Hor != 0)
                            {
                                obj->pos.x=chipLeft - BUBBLE_SIZE;
                            }
                        }
                        if (obj->speed.x < 0)
                        {
                            //����̂������`�b�v�̉E�����Ƀ`�b�v�����݂��Ȃ���Ώ������s��
                            if ((test_mapData[Ver][Hor + 1] == 0 || test_mapData[Ver][Hor + 1] == 3 || test_mapData[Ver][Hor + 1] == 4 || test_mapData[Ver][Hor + 1] == 5) && Hor != (MAPCHIP_H_MAX - 1))
                            {
                                obj->pos.x=chipRight;
                            }
                        }
                    }
                }
                //�����߂���̃v���C���[���W���Ď擾
                bubbleCollLeft = obj->pos.x;
                bubbleCollRight = obj->pos.x + BUBBLE_SIZE;
                bubbleCollTop = obj->pos.y;
                bubbleCollBottom = obj->pos.y + BUBBLE_SIZE;

                //�ڒn����
                if (bubbleCollBottom == chipTop && bubbleCollRight > chipLeft&& bubbleCollLeft < chipRight)
                {
                    obj->touchFloor=true;
                }
            }
        }
    }
}