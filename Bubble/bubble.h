#pragma once
#include "vec2.h"
// ’è” ----------------------------------------------------------------
#define BUBBLE_MAX      (64)
#define BUBBLE_SIZE     (32)
#define BUBBLE_SPEED_X  (5)
#define BUBBLE_SPEED_Y  (5)

enum BubbleState { Stop, Move, Hover, Drift, };
// ƒNƒ‰ƒX --------------------------------------------------------------
class Bubble
{
public:
    void init(Bubble* obj);
    void update(Bubble* obj);
    void draw(Bubble* obj);
    void end(void);
    void fix(Bubble* obj);
    void loadGraph(void);
    void inputDebugKey(void);

    int  getState(Bubble* obj) { return obj->state; }
    void setState(Bubble* obj,int bubbleState) { obj->state = bubbleState; }

private:
    vec2f   pos;
    vec2f   rel_pos;
    int     state = 0;
    bool    exist = false;

    static int handle;
};