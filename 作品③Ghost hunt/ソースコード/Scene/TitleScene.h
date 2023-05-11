#pragma once
#include "BaseScene.h"
#include "../Obj/Obj.h"
#include "../Input/Input.h"


class TitleScene :
	public BaseScene
{
public:
    TitleScene();
    ~TitleScene();
private:
    bool Init(void) override;
    uniqueScene Update(double delta, uniqueScene ownScene) override;
    void DrawOwnScreen(double delta) override;
    Scene GetSceneID(void) override { return Scene::Title; };
    // ��ʂ��ς�낤�Ƃ����
    // �I�����ꂽ��F���ς��悤�ɂ���
    bool Flag_;
    int color_;
    double speed_;
    double speed_X;
    double speed_Y;
    // ����邩�����邩
    bool appFlag_;
    // �����
    bool apptitle_;
    double titletime_;
    // �L�[���A�����ĉ�����Ȃ��悤�Ƀf�B���C��������
    double delay;
    double second;
    double delayTime_;
    // �I�����Ă��鍀�ڂ��_�ł���悤�ɂ���
    int Select_;
    double Blink_;
    int GraphH;
    // �L�[�{�[�h��PAD��
    //CntType cntType_;
    //std::unique_ptr<Input> controller_;
    int input_;
    // ���y
    int SoundHandle;
    int soundHandle1;
};

