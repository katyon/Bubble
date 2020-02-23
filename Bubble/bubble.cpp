// �C���N���[�h ----------------------------------------------------------------------------------
#include "DxLib.h"

#include "common.h"
#include "input.h"
#include "main.h"
#include "bubble.h"
#include "singleton.h"

// �֐� ----------------------------------------------------------------------------------------
void Bubble::init(void)
{
    this->handle = LoadGraph("Data\\Images\\Sprite\\bubble.png");
}

void Bubble::update(void)
{

}

void Bubble::draw(void)
{
    DrawGraphF(this->pos.x, this->pos.y, this->handle, true);
}

void Bubble::end(void)
{
    DeleteGraph(this->handle);
}