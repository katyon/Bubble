// インクルード ----------------------------------------------------------------------------------
#include "DxLib.h"

#include "common.h"
#include "input.h"
#include "main.h"
#include "bg.h"

// 関数 ----------------------------------------------------------------------------------------
// Title
void Title_Bg::init(void)
{
    handle = LoadGraph("Data\\Images\\Bg\\Game_Bg.png");
    string = LoadGraph("Data\\Images\\Bg\\Title_Bg.png");
    pos.set(0, 0);
    src.set(0, 0);
    num = 0;
}

void Title_Bg::update(void)
{
    num = M_Usable.getGameTime() / 40 % 2;
    if (num < 0) num = 0;
    if (num > 1) num = 1;
    switch (num)
    {
    case 0:
        src.set(0, 0);
        break;
    case 1:
        src.set(1920, 0);
        break;
    default: break;
    }
}

void Title_Bg::draw(void)
{
    DrawGraphF(0, 0, handle, true);
    DrawRectGraphF(pos.x, pos.y, src.x, src.y, 1920, 1080, string, true, false, false);
}

void Title_Bg::end(void)
{
    DeleteGraph(handle);
    DeleteGraph(string);
}

// Choice
void Choice_Bg::init(void)
{
    handle = LoadGraph("Data\\Images\\Bg\\Game_Bg.png");
}

void Choice_Bg::update(void)
{

}

void Choice_Bg::draw(void)
{
    DrawGraphF(pos.x, pos.y, handle, true);
}

void Choice_Bg::end(void)
{
    DeleteGraph(handle);
}

// Game
void Game_Bg::init(void)
{
    handle = LoadGraph("Data\\Images\\Bg\\Game_Bg.png");
}

void Game_Bg::update(void)
{

}

void Game_Bg::draw(void)
{
    DrawGraphF(pos.x, pos.y, handle, true);
}

void Game_Bg::end(void)
{
    DeleteGraph(handle);
}