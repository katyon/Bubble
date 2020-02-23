// インクルード ----------------------------------------------------------------------------------
#include "DxLib.h"

#include "common.h"
#include "bg.h"

// 関数 ----------------------------------------------------------------------------------------
// Title
void Title_Bg::init(void)
{
    this->handle = LoadGraph("Data\\Images\\Bg\\Title_Bg.png");
}

void Title_Bg::update(void)
{

}

void Title_Bg::draw(void)
{
    DrawGraphF(this->pos.x, this->pos.y, this->handle, true);
}

void Title_Bg::end(void)
{
    DeleteGraph(this->handle);
}

// Choice
void Choice_Bg::init(void)
{
    this->handle = LoadGraph("Data\\Images\\Bg\\Choice_Bg.png");
}

void Choice_Bg::update(void)
{

}

void Choice_Bg::draw(void)
{
    DrawGraphF(this->pos.x, this->pos.y, this->handle, true);
}

void Choice_Bg::end(void)
{
    DeleteGraph(this->handle);
}

// Game
void Game_Bg::init(void)
{
    this->handle = LoadGraph("Data\\Images\\Bg\\Game_Bg.png");
}

void Game_Bg::update(void)
{

}

void Game_Bg::draw(void)
{
    DrawGraphF(this->pos.x, this->pos.y, this->handle, true);
}

void Game_Bg::end(void)
{
    DeleteGraph(this->handle);
}