// �C���N���[�h ----------------------------------------------------------------------------------
#include "DxLib.h"

#include "common.h"
#include "file.h"
#include "input.h"
#include "main.h"
#include "manage.h"
#include "map.h"
#include "system.h"

// extern�錾,static������ ----------------------------------------------------------------------
extern PlBubbleObj I_PlBubbleObj[PL_BUBBLE_MAX];

// �֐� ----------------------------------------------------------------------------------------
void MapData::init(void)
{
    pos.set(0, 0);
    rel_pos.set(0, 0);
    src.set(0, 0);
    width = 130;
    height = 130;
    handle = LoadGraph("Data\\Images\\Sprite\\MapChip.png");
    M_MapData.setMapData();
    M_MapData.spawnBubble();
}

void MapData::update(void)
{
    for (int i = 0; i < PL_BUBBLE_MAX; i++)
    {
        if (I_PlBubbleObj[i].exist == false) continue;

        M_MapData.collMapChipWithBubble(&I_PlBubbleObj[i]);
    }
}

void MapData::draw(void)
{
    for (int Ver = 0; Ver < MAPCHIP_V_MAX; Ver++)
    {
        for (int Hor = 0; Hor < MAPCHIP_H_MAX; Hor++)
        {
            switch (mapData[Ver][Hor])
            {
            case Void:          src.set(130 * 0, 130 * 0);  break;
            case LFloor:        src.set(130 * 1, 130 * 0);  break;
            case Floor:         src.set(130 * 2, 130 * 0);  break;
            case RFloor:        src.set(130 * 3, 130 * 0);  break;
            case Wall:          src.set(130 * 0, 130 * 1);  break;
            case Lift:          src.set(130 * 1, 130 * 1);  break;
            case Needle:        src.set(130 * 2, 130 * 1);  break;
            case Splitter:      src.set(130 * 3, 130 * 1);  break;
            case BubbleSpawner: src.set(130 * 0, 130 * 2);  break;
            case GoalSpawner:   src.set(130 * 1, 130 * 2);  break;
            case StartSource:   src.set(130 * 2, 130 * 2);  break;
            case EndSource:     src.set(130 * 3, 130 * 2);  break;
            default: src.set(0, 0);  break;
            }
            DrawRectExtendGraph(MAPCHIP_SIZE * Hor, MAPCHIP_SIZE * Ver, MAPCHIP_SIZE * Hor + MAPCHIP_SIZE, MAPCHIP_SIZE * Ver + MAPCHIP_SIZE, src.x, src.y, width, height, handle, true);
        }
    }
}

void MapData::end(void)
{
    DeleteGraph(handle);
}

void MapData::setMapData(void)
{
    M_File.loadMap();
}

void MapData::spawnBubble(void)
{
    for (int Ver = 0; Ver < MAPCHIP_V_MAX; Ver++)
    {
        for (int Hor = 0; Hor < MAPCHIP_H_MAX; Hor++)
        {
            if (mapData[Ver][Hor] == BubbleSpawner)
            {
                for (int i = 0; i < PL_BUBBLE_MAX; i++)
                {
                    if (I_PlBubbleObj[i].exist == true) continue;
                    I_PlBubbleObj[i].init(&I_PlBubbleObj[i], MAPCHIP_SIZE * Hor + MAPCHIP_SIZE / 2 - I_PlBubbleObj[i].radius, MAPCHIP_SIZE * Ver - I_PlBubbleObj[i].radius * 2);
                    I_PlBubbleObj[i].exist = true;
                    break;
                }
            }
        }
    }
}

void MapData::collMapChipWithBubble(PlBubbleObj* obj)
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
            pos.set(MAPCHIP_SIZE * Hor, MAPCHIP_SIZE * Ver);
            rel_pos.set(pos.x + MAPCHIP_SIZE, pos.y + MAPCHIP_SIZE);

            // �����o������
            if (mapData[Ver][Hor] > 0)
            {
                //�}�b�v�`�b�v4�_���W
                chipLeft = Hor * MAPCHIP_SIZE;
                chipRight = (Hor + 1) * MAPCHIP_SIZE;
                chipTop = Ver * MAPCHIP_SIZE;
                chipBottom = (Ver + 1) * MAPCHIP_SIZE;
                //�A�����蔻�蕔4�_���W
                bubbleCollLeft = obj->pos.x;
                bubbleCollRight = obj->pos.x + obj->radius * 2;
                bubbleCollTop = obj->pos.y;
                bubbleCollBottom = obj->pos.y + obj->radius * 2;

                if (bubbleCollLeft + 5 < chipRight && bubbleCollRight - 5 > chipLeft&& bubbleCollTop < chipBottom && bubbleCollBottom > chipTop)
                {
                    //�c�����̉����߂�
                    if (obj->speed.y != 0)
                    {
                        if (obj->speed.y > 0)
                        {
                            if (bubbleCollLeft + 15 < chipRight && bubbleCollRight - 15 > chipLeft&& bubbleCollTop + 15 < chipBottom && bubbleCollBottom > chipTop)
                            {
                                //����̂������`�b�v�̏�����Ƀ`�b�v�����݂��Ȃ���Ώ������s��
                                if (mapData[Ver - 1][Hor] == 0 && Ver != 0)
                                {
                                    obj->pos.y = chipTop - obj->radius * 2;
                                    obj->speed.y = 0;
                                }
                            }
                        }
                        if (obj->speed.y < 0)
                        {
                            if (bubbleCollLeft + 15 < chipRight && bubbleCollRight - 15 > chipLeft&& bubbleCollTop < chipBottom && bubbleCollBottom - 15 > chipTop)
                            {
                                //����̂������`�b�v�̉������Ƀ`�b�v�����݂��Ȃ���Ώ������s��
                                if (mapData[Ver + 1][Hor] == 0 && Ver != (MAPCHIP_V_MAX - 1))
                                {
                                    obj->pos.y = chipBottom;
                                    obj->speed.y = 0;
                                }
                            }
                        }
                    }
                }
                //�����߂���̖A���W���Ď擾
                bubbleCollLeft = obj->pos.x;
                bubbleCollRight = obj->pos.x + obj->radius * 2;
                bubbleCollTop = obj->pos.y;
                bubbleCollBottom = obj->pos.y + obj->radius * 2;

                if (bubbleCollLeft < chipRight && bubbleCollRight > chipLeft&& bubbleCollTop + 15 < chipBottom && bubbleCollBottom - 15 > chipTop)
                {
                    //�������̉����߂�����
                    if (obj->speed.x != 0)
                    {
                        if (obj->speed.x > 0)
                        {
                            //����̂������`�b�v�̍������Ƀ`�b�v�����݂��Ȃ���Ώ������s��
                            if (mapData[Ver][Hor - 1] == 0 && Hor != 0)
                            {
                                obj->pos.x = chipLeft - obj->radius * 2;
                            }
                        }
                        if (obj->speed.x < 0)
                        {
                            //����̂������`�b�v�̉E�����Ƀ`�b�v�����݂��Ȃ���Ώ������s��
                            if (mapData[Ver][Hor + 1] == 0 && Hor != (MAPCHIP_H_MAX - 1))
                            {
                                obj->pos.x = chipRight;
                            }
                        }
                    }
                }
                //�����߂���̖A���W���Ď擾
                bubbleCollLeft = obj->pos.x;
                bubbleCollRight = obj->pos.x + obj->radius * 2;
                bubbleCollTop = obj->pos.y;
                bubbleCollBottom = obj->pos.y + obj->radius * 2;

                //�ڒn����
                if (bubbleCollBottom == chipTop && bubbleCollRight > chipLeft&& bubbleCollLeft < chipRight)
                {
                    obj->touchFloor = true;
                }
            }
            if (M_System.isCollCircleWithRect(obj->center, obj->radius, pos, rel_pos))
            {
                switch (mapData[Ver][Hor])
                {
                    // �j
                case Needle:
                    obj->exist = false;
                    break;
                    // ����
                case Splitter:
                    obj->pos.x -= MAPCHIP_SIZE / 2 - 10;
                    obj->pos.y -= MAPCHIP_SIZE + obj->radius * 3;
                    obj->speed.x = -2;
                    if (obj->level > 1)
                    {
                        obj->level -= 1;
                        for (int i = 0; i < PL_BUBBLE_MAX; i++)
                        {
                            if (I_PlBubbleObj[i].exist == true) continue;
                            I_PlBubbleObj[i].init(&I_PlBubbleObj[i], obj->pos.x + MAPCHIP_SIZE * 2, obj->pos.y);
                            I_PlBubbleObj[i].speed.x = 2;
                            I_PlBubbleObj[i].exist = true;
                            I_PlBubbleObj[i].level = obj->level;
                            break;
                        }
                    }
                    break;
                    // �S�[��
                case GoalSpawner:
                    M_GameManager.clear = true;
                    break;
                default:
                    break;
                }
            }
            // ����
            if (mapData[Ver][Hor] == StartSource)
            {

            }
        }
    }
}