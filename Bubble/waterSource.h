#pragma once
#include "singleton.h"
// 定数 ----------------------------------------------------------------
#define SOURCE_MAX (5)

// クラス --------------------------------------------------------------
class WaterObj
{
public:
    void init(WaterObj* obj, float posX, float posY, float rel_posX, float rel_posY);

    vec2f   pos;
    vec2f   rel_pos;
    bool    exist = false;
};

#define M_WaterSource WaterSource::getInstance()
class WaterSource :public Singleton<WaterSource>
{
public:
    void init(void);
    void update(void);
    void draw(void);
    void end(void);

private:
    int handle;
};