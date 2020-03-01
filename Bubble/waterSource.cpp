// インクルード ----------------------------------------------------------------------------------
#include "DxLib.h"

#include "bubble.h"
#include "waterSource.h"
#include "system.h"

// extern宣言,static初期化 ----------------------------------------------------------------------
extern WaterObj I_WatereObj[SOURCE_MAX];

// 関数 ----------------------------------------------------------------------------------------
void WaterObj::init(WaterObj* obj, float posX, float posY, float rel_posX, float rel_posY)
{
    obj->pos.set(posX, posY);
    obj->rel_pos.set(rel_posX, rel_posY);
    obj->exist = false;
}

void WaterSource::init(void)
{    

}
     
void WaterSource::update(void)
{   
    //if(M_System.isCollCircleWithRect())
}
    
void WaterSource::draw(void)
{    
     
}    
     
void WaterSource::end(void)
{

}