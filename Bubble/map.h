#pragma once
#include "common.h"
#include "singleton.h"
// íËêî ----------------------------------------------------------------
#define		MAPCHIP_H_MAX		(60)
#define		MAPCHIP_V_MAX		(34)
//[Ver][Hor]

// ÉNÉâÉX --------------------------------------------------------------
#define M_Map Map::getInstance()
class Map :public Singleton<Map>
{
public:
    void setMapData(void);
    int mapData[MAPCHIP_H_MAX][MAPCHIP_V_MAX];
};

#define M_MAPChip MapChip::getInstance()
class MapChip :public Sprite, public Singleton<MapChip>
{
public:
    void init(void);
    void update(void);
    void draw(void);
    void end(void);
};