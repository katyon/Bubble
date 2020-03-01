#pragma once
#include "singleton.h"
// �萔 ----------------------------------------------------------------

// �N���X --------------------------------------------------------------
#define M_GameManager GameManager::getInstance()
class GameManager : public Singleton<GameManager>
{
public:
    void init(void);
    void update(void);
    void draw(void);
    void end(void);

    bool clear = false;
private:
};