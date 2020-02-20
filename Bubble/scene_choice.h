#pragma once
// インクルード ---------------------------------------------------------


// 定数 ----------------------------------------------------------------

// クラス --------------------------------------------------------------
#define CHOICE_BG (Choice_Bg::getInstance())
class Choice_Bg : public Sprite
{
public:
	Choice_Bg(const Choice_Bg&) = delete;
	Choice_Bg& operator=(const Choice_Bg&) = delete;
	Choice_Bg(Choice_Bg&&) = delete;
	Choice_Bg& operator=(Choice_Bg&&) = delete;
	static Choice_Bg& getInstance()
	{
		static Choice_Bg instance;
		return instance;
	}

    void init(void);
    void update(void);
    void draw(void);
    void end(void);

private:
	Choice_Bg() = default;
	~Choice_Bg() = default;
};

#define CHOICE_DEBUG (Choice_Debug::getInstance())
class Choice_Debug
{
public:
	Choice_Debug(const Choice_Debug&) = delete;
	Choice_Debug& operator=(const Choice_Debug&) = delete;
	Choice_Debug(Choice_Debug&&) = delete;
	Choice_Debug& operator=(Choice_Debug&&) = delete;
	static Choice_Debug& getInstance()
	{
		static Choice_Debug instance;
		return instance;
	}

	void update(void);

private:
	Choice_Debug() = default;
	~Choice_Debug() = default;
};