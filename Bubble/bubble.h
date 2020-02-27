#pragma once
#include "singleton.h"
#include "vec2.h"
// íËêî ----------------------------------------------------------------
#define BUBBLE_MAX      (64)
#define BUBBLE_ACCEL    (0.5f)
#define BUBBLE_DECEL    (0.2f)
#define BUBBLE_SPEED_MAX    (10.0f)
#define BUOYANCY        (0.3f)

enum BubbleState { Stop, Move, Hover, Drift, };
// ÉNÉâÉX --------------------------------------------------------------
class BubbleObj
{
public:
    void init(BubbleObj* obj, float posX,float posY);

    vec2f   pos;
    vec2f   rel_pos;
    vec2f   center;
    vec2f   speed;
    int     radius = 0;
    int     state = 0;
    int     level = 0;
    bool    exist = false;
    bool    touchFloor = false;
    bool    touchBubble = false;
};

#define M_Bubble Bubble::getInstance()
class Bubble :public Singleton<Bubble>
{
public:
    void init(void);
    void update(void);
    void draw(void);
    void end(void);
    void move(BubbleObj* obj);
    void fix(BubbleObj* obj);
    void collAnotherBubble(void);
    void inputDebugKey(void);

private:
    int handle;
};