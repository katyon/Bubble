#pragma once
// インクルード ---------------------------------------------------------


// 定数 ----------------------------------------------------------------

// クラス --------------------------------------------------------------
#define TITLE_BG (Title_Bg::getInstance())
class Title_Bg : public Sprite
{
public:
	Title_Bg(const Title_Bg&) = delete;
	Title_Bg& operator=(const Title_Bg&) = delete;
	Title_Bg(Title_Bg&&) = delete;
	Title_Bg& operator=(Title_Bg&&) = delete;
	static Title_Bg& getInstance()
	{
		static Title_Bg instance;
		return instance;
	}

    void init(void);
    void update(void);
    void draw(void);
    void end(void);

private:
	Title_Bg() = default;
	~Title_Bg() = default;

};

#define TITLE_DEBUG (Title_Debug::getInstance())
class Title_Debug
{
public:
	Title_Debug(const Title_Debug&) = delete;
	Title_Debug& operator=(const Title_Debug&) = delete;
	Title_Debug(Title_Debug&&) = delete;
	Title_Debug& operator=(Title_Debug&&) = delete;
	static Title_Debug& getInstance()
	{
		static Title_Debug instance;
		return instance;
	}

	void update(void);

private:
	Title_Debug() = default;
	~Title_Debug() = default;

};