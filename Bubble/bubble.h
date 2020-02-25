#pragma once
#include "singleton.h"
#include "vec2.h"
// íËêî ----------------------------------------------------------------
#define BUBBLE_MAX      (64)
#define BUBBLE_SIZE     (32)
#define BUBBLE_SPEED_X  (5)
#define BUBBLE_SPEED_Y  (5)

enum BubbleState { Stop, Move, Hover, Drift, };
// ÉNÉâÉX --------------------------------------------------------------
class BubbleObj
{
public:
    void init(BubbleObj* obj);

    vec2f   pos;
    vec2f   rel_pos;
    int     state = 0;
    bool    exist = false;
};

#define M_Bubble Bubble::getInstance()
class Bubble :public Singleton<Bubble>
{
public:
    void init(void);
    void update(void);
    void draw(void);
    void end(void);
    void fix(BubbleObj* obj);
    void inputDebugKey(BubbleObj* obj);
private:
    int handle;
};