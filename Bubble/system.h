#pragma once
// 定数 ----------------------------------------------------------------

// クラス --------------------------------------------------------------
#define M_System (System::getInstance())
class System : public Singleton<System>
{
public:
    void    drawDebugString(void);
    void    inputDebugKey(void);
    void    changeSceneStateInit(int next_scene);    // シーン遷移処理

private:
    unsigned int cr = 0;
};