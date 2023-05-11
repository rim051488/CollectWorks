#pragma once
#include <string>
#include "../../Tmx/TmxObj.h"
#include "BaseScene.h"
class SelectScene :
	public BaseScene
{
public:
    SelectScene();
    ~SelectScene();
private:
    bool Init(void) override;
    uniqueScene Update(double delta, uniqueScene ownScene) override;
    void DrawOwnScreen(double delta) override;
    Scene GetSceneID(void) override { return Scene::Select; };
    std::string fileName_;
    // �L�[���A�����ĉ�����Ȃ��悤�Ƀf�B���C��������
    double delay;
    double second;
    TmxObj tmxObj_;
    // �}�b�v�̏���w�i�ɕ`�悷�邩�ǂ���
    bool mapDraw_;
    // �}�b�v��\������܂ł̃t�F�[�h�C��
    double count_;
    int timelimit;

    // �I�����Ă��鍀�ڂ��_�ł���悤�ɂ���
    int Select_;
    double Blink_;
    int input_;
    // ���y
    int SoundHandle;
    int soundHandle1;
    Vector2Dbl screensize;
};

