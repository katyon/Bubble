#pragma once
// �萔 ----------------------------------------------------------------

// �N���X --------------------------------------------------------------
#define M_bubble Bubble::getInstance()
class Bubble :public Sprite, public Singleton<Bubble>
{
public:
    void init(void);
    void update(void);
    void draw(void);
    void end(void);
};