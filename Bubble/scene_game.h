#pragma once
// íËêî ----------------------------------------------------------------

// ÉNÉâÉX --------------------------------------------------------------
#define GAME_BG Game_Bg::getInstance()
class Game_Bg :public Sprite, public Singleton<Game_Bg>
{
public:
    void init(void);
    void update(void);
    void draw(void);
    void end(void);
};

#define GAME_DEBUG Game_Debug::getInstance()
class Game_Debug :public Singleton<Game_Debug>
{
public:
    void update(void);
};