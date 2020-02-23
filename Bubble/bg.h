#pragma once
// íËêî ----------------------------------------------------------------
#include "singleton.h"
#include "vec2.h"

// ÉNÉâÉX --------------------------------------------------------------
class Bg
{
public:
    virtual void init(void) = 0;
    virtual void update(void) = 0;
    virtual void draw(void) = 0;
    virtual void end(void) = 0;
protected:
    vec2f   pos;
    int     handle = 0;
};

#define M_TitleBg Title_Bg::getInstance()
class Title_Bg :public Bg,public Singleton<Title_Bg>
{
public:
    void init(void);
    void update(void);
    void draw(void);
    void end(void);
};

#define M_ChoiceBg Choice_Bg::getInstance()
class Choice_Bg :public Bg, public Singleton<Choice_Bg>
{
public:
    void init(void);
    void update(void);
    void draw(void);
    void end(void);
};

#define M_GameBg Game_Bg::getInstance()
class Game_Bg :public Bg, public Singleton<Game_Bg>
{
public:
    void init(void);
    void update(void);
    void draw(void);
    void end(void);
};