#pragma once

// �C���N���[�h
#include <windows.h>
#include <DxLib.h>

// �萔 ----------------------------------------------------
#define STR_WINTTL				"Brightless"    // �E�B���h�E�^�C�g���i�C�ӂɐݒ�j
#define STR_MSGTTL_ASKFS		"�N������"
#define STR_MSG_ASKFS			"�t���X�N���[���ŋN�����܂����H"

enum Scene_State { State_Title, State_Choice, State_Game };

// �N���X --------------------------------------------------
#define USABLE (Usable::getInstance())
class Usable
{
public:
    Usable(const Usable&) = delete;
    Usable& operator=(const Usable&) = delete;
    Usable(Usable&&) = delete;
    Usable& operator=(Usable&&) = delete;
    static Usable& getInstance()
    {
        static Usable instance;
        return instance;
    }

    void BeforeInit(void);  // DirectX�������O����
    void AfterInit(void);   // �Q�[���J�n�O����
    void MainLoop(void);    // �Q�[�����C�����[�v
    void End(void);         // �Q�[���I���㏈��
    void changeSceneStateInit(Scene_State next_num);    // �V�[���J�ڏ���

private:
    Usable() = default;
    ~Usable() = default;
};

// ���C�����[�v�p�̐e�N���X
class Scene
{
public:
    virtual void init(void) = 0;
    virtual void update(int GameTime) = 0;
    virtual void draw(int GameTime) = 0;
    virtual void end(void) = 0;
};

class Scene_Title :public Scene
{
public:
    void init(void);
    void update(int GameTime);
    void draw(int GameTime);
    void end(void);
private:

};

class Scene_Choice :public Scene
{
public:
    void init(void);
    void update(int GameTime);
    void draw(int GameTime);
    void end(void);
private:

};

class Scene_Game :public Scene
{
public:
    void init(void);
    void update(int GameTime);
    void draw(int GameTime);
    void end(void);
private:

};