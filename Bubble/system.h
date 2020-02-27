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
    bool    isCollRect(vec2f a, vec2f rel_a, vec2f b, vec2f rel_b);

private:
    unsigned int cr = 0;
};