// インクルード ----------------------------------------------------------------------------------
#include "DxLib.h"

#include "common.h"
#include "input.h"
#include "main.h"
#include "map.h"

// 関数 ----------------------------------------------------------------------------------------
void Map::setMapData(void)
{
	for (int Ver = 0; Ver < MAPCHIP_V_MAX; Ver++)
	{
		for (int Hor = 0; Hor < MAPCHIP_H_MAX; Hor++)
		{
			this->mapData[Ver][Hor] = 0;
		}
	}
}

void MapChip::init(void)
{
    this->handle = LoadGraph("Data\\Images\\Sprite\\MapChip.png");
}

void MapChip::update(void)
{
	
}

void MapChip::draw(void)
{

}

void MapChip::end(void)
{
    DeleteGraph(this->handle);
}