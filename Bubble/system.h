#pragma once
// �萔 ----------------------------------------------------------------

// �N���X --------------------------------------------------------------
#define M_System (System::getInstance())
class System : public Singleton<System>
{
public:
    void    drawDebugString(void);
    void    inputDebugKey(void);
    void    changeSceneStateInit(int next_scene);    // �V�[���J�ڏ���

private:
    unsigned int cr = 0;
};