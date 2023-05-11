#pragma once
#include "BaseScene.h"
class InfoScene :
    public BaseScene
{
public:
    InfoScene();
    InfoScene(uniqueScene beforScene);
    ~InfoScene();
private:
    bool Init(void) override;
    uniqueScene Update(double delta, uniqueScene ownScene) override;
    void DrawOwnScreen(double delta) override;
    Scene GetSceneID(void) override ;
    // ��������̐؂�ւ�莞��
    double info_;
    // ��������̎��
    int infoKinds_;
    // �L�[���A�����ĉ�����Ȃ��悤�Ƀf�B���C��������
    double delay;
    double second;
    double delayTime_;
    uniqueScene beforScene_;
    // �L�[�{�[�h���p�b�h��
    int input_;
    // ���y
    int SoundHandle;
    int soundHandle1;
};

