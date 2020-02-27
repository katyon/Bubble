#include "main.h"
#include "DxLib.h"

#include "bg.h"
#include "bubble.h"
#include "common.h"
#include "input.h"
#include "map.h"
#include "system.h"
#include "UI.h"

//////////////////////////////////////////////////////////////////////////
//	�e�Q�[���Ŏg�p����N���X�C���X�^���X��O���[�o���ϐ��͂����ɋL�q
//

BubbleObj I_BubbleObj[BUBBLE_MAX];

//
// ��`�����܂�
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
//	��������^�C�g���̏���
//

// �^�C�g������������
void Scene_Title::init(void)
{
    M_TitleBg.init();
}

// �^�C�g���X�V����
void Scene_Title::update(void)
{
    M_TitleBg.update();
}

// �^�C�g���`�揈��
void Scene_Title::draw(void)
{
    M_TitleBg.draw();
}

// �^�C�g���I������
void Scene_Title::end(void)
{
    M_TitleBg.end();
}

//
//	�^�C�g���̏��������܂�
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
//	��������X�e�[�W�I���̏���
//

// �X�e�[�W�I������������
void Scene_Choice::init(void)
{
    M_ChoiceBg.init();
}

// �X�e�[�W�I���X�V����
void Scene_Choice::update(void)
{
    M_ChoiceBg.update();
}

// �X�e�[�W�I��`�揈��
void Scene_Choice::draw(void)
{
    M_ChoiceBg.draw();
}

// �X�e�[�W�I���I������
void Scene_Choice::end(void)
{
    M_ChoiceBg.end();
}

//
//	�X�e�[�W�I���̏��������܂�
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
//	��������Q�[���̏���
//

// �Q�[������������
void Scene_Game::init(void)
{
    M_MapData.init();
    M_GameBg.init();
    M_Bubble.init();
    M_UI.init();
}

// �Q�[���X�V����
void Scene_Game::update(void)
{
    M_MapData.update();
    M_GameBg.update();
    M_Bubble.update();
    M_UI.update();
}

// �Q�[���`�揈��
void Scene_Game::draw(void)
{
    M_GameBg.draw();
    M_MapData.draw();
    M_Bubble.draw();
    M_UI.draw();
}

// �Q�[���I������
void Scene_Game::end(void)
{
    M_MapData.end();
    M_GameBg.end();
    M_Bubble.end();
    M_UI.end();
}

//
//	�Q�[���̏��������܂�
//////////////////////////////////////////////////////////////////////////

// DirectX�������O����
void Usable::BeforeInit(void)
{
    //int mbResult;
    int win_mode = TRUE;
    //
    //// �t���X�N���[���ɂ��邩�I������
    //mbResult = MessageBox(NULL, STR_MSG_ASKFS, STR_MSGTTL_ASKFS, MB_YESNO);
    //if (mbResult == IDYES) win_mode = FALSE;
    ChangeWindowMode(win_mode);
    // �E�B���h�E�^�C�g����ݒ肷��
    SetMainWindowText(STR_WINTTL);
}

// �Q�[���J�n�O����
void Usable::AfterInit(void)
{
    // InputClass
    Input::Create();
    Input::GetInstance()->Init();

    sceneState = State_Title;
    M_SceneTitle.init();
}

// �Q�[���I���㏈��
void Usable::End(void)
{
    // InputClass�̏I������
    Input::Destroy();
    // �S�O���t�B�b�N�̍폜
    DxLib::InitGraph();
    // �S���f�[�^�̍폜
    InitSoundMem();
}

// �Q�[�����C�����[�v
void Usable::MainLoop(void)
{
    M_Usable.AfterInit();    // �Q�[���J�n�O����

    while (ProcessMessage() == 0)		    // ProcessMessage������ɏ�������Ă���Ԃ̓��[�v
    {
        ClearDrawScreen();  				// ����ʂ��폜
        Input::GetInstance()->Updata();     // ���͏�Ԃ̍X�V����

        switch (sceneState)
        {
        case State_Title:
            M_SceneTitle.update();         // �^�C�g���X�V����
            M_SceneTitle.draw();           // �^�C�g���`�揈��
            break;
        case State_Choice:
            M_SceneChoice.update();        // �X�e�[�W�I���X�V����
            M_SceneChoice.draw();          // �X�e�[�W�I��`�揈��
            
            break;
        case State_Game:
            M_SceneGame.update();          // �Q�[���X�V����
            M_SceneGame.draw();            // �Q�[���`�揈��
            break;
        }

        M_System.inputDebugKey();   // debug
        M_System.drawDebugString(); // debug
        ScreenFlip();   // VSYNC��҂�

        // ESC�L�[�����͏�ɊĎ��B�����ꂽ�璼���ɏI��
        int stick = CheckHitKey(KEY_INPUT_ESCAPE);
        if (stick == 1) break;
        M_Usable.countGameTime();   // �Q�[���J�E���^��i�߂�
    }
}

// WinMain�֐�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
    LPSTR lpCmdLine, int nCmdShow)
{
    M_Usable.BeforeInit();                // DirectX�������O����
    if (DxLib_Init() == -1) return -1;  // �G���[���N�����璼���ɏI��

    SetGraphMode(GAME_SCREEN_WIDTH, GAME_SCREEN_HEIGHT, 32);
    SetDrawScreen(DX_SCREEN_BACK);      // �`��X�N���[���𗠑��Ɏw��
    SetWaitVSyncFlag(TRUE);             // VSYNC��L���ɂ���
    M_Usable.AfterInit();                 // DirectX�������㏈��
    M_Usable.MainLoop();                  // �Q�[���{��(���C�����[�v)
    M_Usable.End();                       // �Q�[���I���㏈��
    DxLib_End();                        // �c�w���C�u�����g�p�̏I������
    return 0;                           // �\�t�g�̏I��
}
