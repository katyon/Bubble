#pragma once
// íËêî ----------------------------------------------------------------

// ÉNÉâÉX --------------------------------------------------------------
#define CHOICE_BG Choice_Bg::getInstance()
class Choice_Bg :public Sprite, public Singleton<Choice_Bg>
{
public:
    void init(void);
    void update(void);
    void draw(void);
    void end(void);
};

#define CHOICE_DEBUG Choice_Debug::getInstance()
class Choice_Debug:public Singleton<Choice_Debug>
{
public:
    void update(void);
};