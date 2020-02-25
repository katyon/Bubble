#pragma once
#include "common.h"
#include "singleton.h"
// 定数 ----------------------------------------------------------------

// クラス --------------------------------------------------------------
#define M_Bubble Bubble::getInstance()
class Bubble :public Sprite, public Singleton<Bubble>
{
public:
    void init(void);
    void update(void);
    void draw(void);
    void end(void);
};