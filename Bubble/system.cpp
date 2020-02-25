// �C���N���[�h -------------------------------------------------------------------------------------
#include "DxLib.h"
#include <math.h>

#include "common.h"
#include "input.h"
#include "main.h"
#include "system.h"
#include "singleton.h"
#include "vec2.h"

// �֐� ----------------------------------------------------------------------------------------
// �f�o�b�N������`��
void System::drawDebugString()
{
    SetFontSize(25);
    cr = GetColor(200, 0, 0);

    DrawFormatString(0, 0, cr, "Title :1");
    DrawFormatString(0, 20, cr, "Choice:2");
    DrawFormatString(0, 40, cr, "Game  :3");
}

// �f�o�b�N�L�[
void System::inputDebugKey(void)
{
    if (M_Input->GetKeyDown(KEY_INPUT_1)) M_System.changeSceneStateInit(State_Title);
    if (M_Input->GetKeyDown(KEY_INPUT_2)) M_System.changeSceneStateInit(State_Choice);
    if (M_Input->GetKeyDown(KEY_INPUT_3)) M_System.changeSceneStateInit(State_Game);
}

// �V�[���J�ڏ���
void System::changeSceneStateInit(int nextScene)
{
    // ���݂̃V�[���̏I������
    switch (M_Usable.getSceneState())
    {
    case State_Title:
        M_SceneTitle.end();
        break;
    case State_Choice:
        M_SceneChoice.end();
        break;
    case State_Game:
        M_SceneGame.end();
        break;
    }

    // �V�[���J�ڎ��ɏ�����
    switch (nextScene)
    {
    case State_Title:
        M_SceneTitle.init();
        break;
    case State_Choice:
        M_SceneChoice.init();
        break;
    case State_Game:
        M_SceneGame.init();
        break;
    }

    M_Usable.setSceneState(nextScene);
}