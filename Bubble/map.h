#pragma once
#include "common.h"
#include "singleton.h"
// 定数 ----------------------------------------------------------------
#define		MAPCHIP_H_MAX		(30)
#define		MAPCHIP_V_MAX		(17)
#define		MAPCHIP_SIZE		(64)
//[Ver][Hor]

// クラス --------------------------------------------------------------
#define M_MapData MapData::getInstance()
class MapData :public Sprite, public Singleton<MapData>
{
public:
    void init(void);
    void update(void);
    void draw(void);
    void end(void);
    void setMapData(void);
    void collMapChipWithBubble(void);

private:
    enum ChipData { Void, Floor, BubbleSpawner, GoalSpawner };
    int mapData[MAPCHIP_H_MAX][MAPCHIP_V_MAX];

};