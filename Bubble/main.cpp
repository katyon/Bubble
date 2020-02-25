#include "main.h"
#include "DxLib.h"

#include "common.h"
#include "input.h"
#include "scene_choice.h"
#include "scene_game.h"
#include "scene_title.h"
#include "system.h"

//////////////////////////////////////////////////////////////////////////
//	�e�Q�[���Ŏg�p����N���X�C���X�^���X��O���[�o���ϐ��͂����ɋL�q
//

Scene_Title     title;
Scene_Choice    choice;
Scene_Game      game;

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
    TITLE_BG.init();
}

// �^�C�g���X�V����
void Scene_Title::update(int GameTime)
{
    TITLE_BG.update();
    TITLE_DEBUG.update();
}

// �^�C�g���`�揈��
void Scene_Title::draw(int GameTime)
{
    TITLE_BG.draw();
}

// �^�C�g���I������
void Scene_Title::end(void)
{
    TITLE_BG.end();
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
    CHOICE_BG.init();
}

// �X�e�[�W�I���X�V����
void Scene_Choice::update(int GameTime)
{
    CHOICE_BG.update();
    CHOICE_DEBUG.update();
}

// �X�e�[�W�I��`�揈��
void Scene_Choice::draw(int GameTime)
{
    CHOICE_BG.draw();
}

// �X�e�[�W�I���I������
void Scene_Choice::end(void)
{
    CHOICE_BG.end();
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
    GAME_BG.init();
}

// �Q�[���X�V����
void Scene_Game::update(int GameTime)
{
    GAME_BG.update();
    GAME_DEBUG.update();
}

// �Q�[���`�揈��
void Scene_Game::draw(int GameTime)
{
    GAME_BG.draw();
}

// �Q�[���I������
void Scene_Game::end(void)
{
    GAME_BG.end();
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

    state = State_Title;
    title.init();
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
    case State_Title:
        title.end();
        break;
    case State_Choice:
        choice.end();
        break;
    case State_Game:
        game.end();
        break;
    }

    // �V�[���J�ڎ��ɏ�����
    switch (next_num)
    {
    case State_Title:
        title.init();
        break;
    case State_Choice:
        choice.init();
        break;
    case State_Game:
        game.init();
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

    USABLE.AfterInit();    // �Q�[���J�n�O����

    while (ProcessMessage() == 0)		    // ProcessMessage������ɏ�������Ă���Ԃ̓��[�v
    {
        ClearDrawScreen();  				// ����ʂ��폜
        Input::GetInstance()->Updata();     // ���͏�Ԃ̍X�V����

        switch (state)
        {
        case State_Title:
            title.update(gameTime);         // �^�C�g���X�V����
            title.draw(gameTime);           // �^�C�g���`�揈��
            break;
        case State_Choice:
            choice.update(gameTime);        // �X�e�[�W�I���X�V����
            choice.draw(gameTime);          // �X�e�[�W�I��`�揈��
            break;
        case State_Game:
            game.update(gameTime);          // �Q�[���X�V����
            game.draw(gameTime);            // �Q�[���`�揈��
            break;
        }
        System::getInstance().drawDebugString(); // debug
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
    USABLE.BeforeInit();                // DirectX�������O����
    if (DxLib_Init() == -1) return -1;  // �G���[���N�����璼���ɏI��

    SetGraphMode(GAME_SCREEN_WIDTH, GAME_SCREEN_HEIGHT, 32);
    SetDrawScreen(DX_SCREEN_BACK);      // �`��X�N���[���𗠑��Ɏw��
    SetWaitVSyncFlag(TRUE);             // VSYNC��L���ɂ���
    USABLE.AfterInit();                 // DirectX�������㏈��
    USABLE.MainLoop();                  // �Q�[���{��(���C�����[�v)
    USABLE.End();                       // �Q�[���I���㏈��
    DxLib_End();                        // �c�w���C�u�����g�p�̏I������
    return 0;                           // �\�t�g�̏I��
}
