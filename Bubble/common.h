#pragma once
#include "vec2.h"

// ’è”’è‹`
#define GAME_SCREEN_WIDTH	(1920)      // ƒQ[ƒ€‰æ–Ê‚Ì•
#define GAME_SCREEN_HEIGHT	(1080)      // ƒQ[ƒ€‰æ–Ê‚Ì‚‚³
#define PI          (3.1415926535f)     // ‰~ü—¦
#define ROOT2       (1.41421356f)       // ã2
#define ROOT5       (2.2360679f)        // ã5

class Sprite
{
public:
    virtual void init(void) {};
    virtual void update(void) {};
    virtual void draw(void) {};
    virtual void end(void) {};

    virtual float getPosX() { return posX; }
    virtual float getPosY() { return posY; }
    virtual float getRelPosX() { return rel_posX; }
    virtual float getRelPosY() { return rel_posY; }
    virtual void setRelPosX(float x) { rel_posX = x; }
    virtual void setRelPosY(float y) { rel_posY = y; }
protected:
    vec2<float> vec;
    float posX = 0;
    float posY = 0;
    float rel_posX = 0;
    float rel_posY = 0;
    int width = 0;
    int height = 0;
    int handle = 0;
};