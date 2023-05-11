#pragma once
#include <string>
#include "BaseScene.h"
class GameOverScene :
	public BaseScene
{
public:
    GameOverScene();
    GameOverScene(std::string filename, std::string map, std::string pos);
    ~GameOverScene();
private:
    bool Init(void) override;
    bool Init(std::string filename);
    uniqueScene Update(double delta, uniqueScene ownScene) override;
    void DrawOwnScreen(double delta) override;
    Scene GetSceneID(void) override { return Scene::GameOver; };
    // �L�[���A�����ĉ�����Ȃ��悤�Ƀf�B���C��������
    double delay;
    double second;
    // ���݂̃X�e�[�W�����󂯎��
    std::string fileName_;
    std::string map_;
    // obj�̍��W���t�@�C������ǂݎ��
    std::string objPos_;
    // �I�����Ă��鍀�ڂ��_�ł���悤�ɂ���
    int Select_;
    double Blink_;
    // �L�[�{�[�h���p�b�h��
    int input_;
    // ���y
    int SoundHandle;
    int soundHandle1;
};

