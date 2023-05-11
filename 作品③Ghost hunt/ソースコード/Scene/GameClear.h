#pragma once
#include <string>
#include "BaseScene.h"
class GameClear :
	public BaseScene
{
public:
    GameClear();
    GameClear(std::string filename,std::string map, std::string pos, int dethenemy,int time);
    ~GameClear();
private:
    bool Init(void) override;
    bool Init(std::string filename);
    uniqueScene Update(double delta, uniqueScene ownScene) override;
    void DrawOwnScreen(double delta) override;
    Scene GetSceneID(void) override { return Scene::GameClear; };
    // �L�[���A�����ĉ�����Ȃ��悤�Ƀf�B���C��������
    double delay;
    double second;
    int dethEnemy;
    // �}�b�v�̏��Ƃ��̃}�b�v�Ɏg���Ă���摜��n����悤�ɂ��Ă���
    std::string fileName_;
    std::string map_;
    // obj�̍��W���t�@�C������ǂݎ��
    std::string objPos_;
    // �I�����Ă��鍀�ڂ��_�ł���悤�ɂ���
    int Select_;
    double Blink_;
    int time_;
    // �L�[�{�[�h���p�b�h��
    int input_;
    // ���y
    int SoundHandle;
    int soundHandle1;
};

