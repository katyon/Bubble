#include "main.h"
#include "DxLib.h"

#include "common.h"
#include "input.h"
#include "system.h"

//////////////////////////////////////////////////////////////////////////
//	�e�Q�[���Ŏg�p����N���X�C���X�^���X��O���[�o���ϐ��͂����ɋL�q
//

Usable          usable;
System          sys;

Scene_State     state;

//
// ��`�����܂�
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
//	��������^�C�g���̏���
//

// �^�C�g������������
void Scene_Title::init(void)
{
}

// �^�C�g���X�V����
void Scene_Title::update(int GameTime)
{
}

// �^�C�g���`�揈��
void Scene_Title::draw(int GameTime)
{
}

// �^�C�g���I������
void Scene_Title::end(void)
{
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
}

// �X�e�[�W�I���X�V����
void Scene_Choice::update(int GameTime)
{
}

// �X�e�[�W�I��`�揈��
void Scene_Choice::draw(int GameTime)
{
}

// �X�e�[�W�I���I������
void Scene_Choice::end(void)
{
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
}

// �Q�[���X�V����
void Scene_Game::update(int GameTime)
{
}

// �Q�[���`�揈��
void Scene_Game::draw(int GameTime)
{
}

// �Q�[���I������
void Scene_Game::end(void)
{
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

    state = Title;
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

// �V�[���J�ڏ���
void Usable::changeSceneStateInit(Scene_State next_num)
{
    // ���݂̃V�[���̏I������
    switch (state)
    {
    case Title:
        break;
    case Choice:
        break;
    case Game:
        break;
    }

    // �V�[���J�ڎ��ɏ�����
    switch (next_num)
    {
    case Title:
        break;
    case Choice:
        break;
    case Game:
        break;
    }

    state = next_num;
}

int test_handle;
int mask_handle;


// �Q�[�����C�����[�v
void Usable::MainLoop(void)
{
    unsigned int gameTime = 0;			// �O���[�o���Q�[���J�E���^

    usable.AfterInit();    // �Q�[���J�n�O����

    while (ProcessMessage() == 0)		    // ProcessMessage������ɏ�������Ă���Ԃ̓��[�v
    {
        ClearDrawScreen();  				// ����ʂ��폜
        Input::GetInstance()->Updata();     // ���͏�Ԃ̍X�V����

        switch (state)
        {
        case Title:
            break;
        case Choice:
            break;
        case Game:
            break;
        }
        ScreenFlip();   // VSYNC��҂�

        // ESC�L�[�����͏�ɊĎ��B�����ꂽ�璼���ɏI��
        int stick = CheckHitKey(KEY_INPUT_ESCAPE);
        if (stick == 1) break;
        gameTime++;						// �Q�[���J�E���^��i�߂�
    }
}

// WinMain�֐�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
    LPSTR lpCmdLine, int nCmdShow)
{
    usable.BeforeInit();                // DirectX�������O����
    if (DxLib_Init() == -1) return -1;  // �G���[���N�����璼���ɏI��

    SetGraphMode(GAME_SCREEN_WIDTH, GAME_SCREEN_HEIGHT, 32);
    SetDrawScreen(DX_SCREEN_BACK);      // �`��X�N���[���𗠑��Ɏw��
    SetWaitVSyncFlag(TRUE);             // VSYNC��L���ɂ���
    usable.AfterInit();                 // DirectX�������㏈��
    usable.MainLoop();                  // �Q�[���{��(���C�����[�v)
    usable.End();                       // �Q�[���I���㏈��
    DxLib_End();                        // �c�w���C�u�����g�p�̏I������
    return 0;                           // �\�t�g�̏I��
}
