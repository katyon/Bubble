#pragma once
#include "singleton.h"
// íËêî ----------------------------------------------------------------

// ÉNÉâÉX --------------------------------------------------------------
#define M_TitleManager TitleManager::getInstance()
class TitleManager : public Singleton<TitleManager>
{
public:
    void init(void);
    void update(void);
    void draw(void);
    void end(void);

    bool change = false;
private:
};

#define M_SelectManager SelectManager::getInstance()
class SelectManager : public Singleton<SelectManager>
{
public:
    void init(void);
    void update(void);
    void draw(void);
    void end(void);

    bool change = false;
private:
};

#define M_GameManager GameManager::getInstance()
class GameManager : public Singleton<GameManager>
{
public:
    void init(void);
    void update(void);
    void draw(void);
    void end(void);

    bool change = false;
    bool clear = false;
    int handle;
private:
};