#pragma once
// íËêî ----------------------------------------------------------------

// ÉNÉâÉX --------------------------------------------------------------
#define TITLE_BG Title_Bg::getInstance()
class Title_Bg :public Sprite, public Singleton<Title_Bg>
{
public:
    void init(void);
    void update(void);
    void draw(void);
    void end(void);
};

#define TITLE_DEBUG Title_Debug::getInstance()
class Title_Debug :public Singleton<Title_Debug>
{
public:
    void update(void);
};