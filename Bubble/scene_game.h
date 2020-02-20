#pragma once
// インクルード ---------------------------------------------------------


// 定数 ----------------------------------------------------------------

// クラス --------------------------------------------------------------
#define GAME_BG (Game_Bg::getInstance())
class Game_Bg : public Sprite
{
public:
	Game_Bg(const Game_Bg&) = delete;
	Game_Bg& operator=(const Game_Bg&) = delete;
	Game_Bg(Game_Bg&&) = delete;
	Game_Bg& operator=(Game_Bg&&) = delete;
	static Game_Bg& getInstance()
	{
		static Game_Bg instance;
		return instance;
	}

    void init(void);
    void update(void);
    void draw(void);
    void end(void);

private:
	Game_Bg() = default;
	~Game_Bg() = default;

};

#define GAME_DEBUG (Game_Debug::getInstance())
class Game_Debug
{
public:
	Game_Debug(const Game_Debug&) = delete;
	Game_Debug& operator=(const Game_Debug&) = delete;
	Game_Debug(Game_Debug&&) = delete;
	Game_Debug& operator=(Game_Debug&&) = delete;
	static Game_Debug& getInstance()
	{
		static Game_Debug instance;
		return instance;
	}

	void update(void);

private:
	Game_Debug() = default;
	~Game_Debug() = default;

};