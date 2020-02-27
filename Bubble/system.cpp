// �C���N���[�h -------------------------------------------------------------------------------------
#include "DxLib.h"
#include <math.h>

#include "bubble.h"
#include "common.h"
#include "input.h"
#include "main.h"
#include "map.h"
#include "system.h"
#include "singleton.h"
#include "vec2.h"

// extern�錾,static������ ----------------------------------------------------------------------
extern BubbleObj I_BubbleObj[BUBBLE_MAX];

// �֐� ----------------------------------------------------------------------------------------
// �f�o�b�N������`��
void System::drawDebugString()
{
    SetFontSize(25);
    cr = GetColor(200, 0, 0);

    DrawFormatString(0, 0, cr, "Title :1");
    DrawFormatString(0, 20, cr, "Choice:2");
    DrawFormatString(0, 40, cr, "Game  :3");
    DrawFormatString(120, 0, cr, "bubblePosX  %f", I_BubbleObj[0].pos.x);
    DrawFormatString(120, 20, cr, "bubblePosY  %f", I_BubbleObj[0].pos.y);
    DrawFormatString(120, 40, cr, "bubbleSpeedX%f", I_BubbleObj[0].speed.x);
    DrawFormatString(120, 60, cr, "bubbleSpeedY%f", I_BubbleObj[0].speed.y);
    DrawFormatString(120, 80, cr, "touchBubble[0]%d", I_BubbleObj[0].touchBubble);
    DrawFormatString(120, 100, cr, "touchBubble[1]%d", I_BubbleObj[1].touchBubble);
    DrawFormatString(120, 120, cr, "touchBubble[2]%d", I_BubbleObj[2].touchBubble);
    DrawFormatString(120, 140, cr, "touchBubble[3]%d", I_BubbleObj[3].touchBubble);
    DrawFormatString(120, 160, cr, "level[0]%d", I_BubbleObj[0].level);

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

bool System::isCollRect(vec2f a, vec2f rel_a, vec2f b, vec2f rel_b)
{
    if (a.x <= rel_b.x && b.x <= rel_a.x && a.y <= rel_b.y && b.y <= rel_a.y) return true;
    return false;
}