#pragma once
#include "vec2.h"

// �萔��`
#define GAME_SCREEN_WIDTH	(1920)      // �Q�[����ʂ̕�
#define GAME_SCREEN_HEIGHT	(1080)      // �Q�[����ʂ̍���
#define PI          (3.1415926535f)     // �~����
#define ROOT2       (1.41421356f)       // ��2
#define ROOT5       (2.2360679f)        // ��5

class Sprite
{
public:
    virtual void init(void) {};
    virtual void update(void) {};
    virtual void draw(void) {};
    virtual void end(void) {};

    virtual float getPosX() { return pos.x; }
    virtual float getPosY() { return pos.y; }
    virtual float getRelPosX() { return rel_pos.x; }
    virtual float getRelPosY() { return rel_pos.y; }
    virtual void setRelPosX(float x) { rel_pos.x = x; }
    virtual void setRelPosY(float y) { rel_pos.y = y; }
protected:
    vec2f pos;
    vec2f rel_pos;
    int width = 0;
    int height = 0;
    int handle = 0;
};