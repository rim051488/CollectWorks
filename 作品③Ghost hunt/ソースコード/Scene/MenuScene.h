#pragma once
#include "../Scene/BaseScene.h"
class MenuScene:
	public BaseScene
{
public:
	MenuScene();
	MenuScene(uniqueScene beforScene,int dethEnemy);
	~MenuScene();
private:
	bool Init(void) override;
	uniqueScene Update(double delta, uniqueScene ownScene) override;
	void DrawOwnScreen(double delta) override;
	virtual Scene GetSceneID(void) override;
	int dethEnemy_;
	// �L�[���A�����ĉ�����Ȃ��悤�Ƀf�B���C��������
	double delay;
	double second;
	// �I�����Ă��鍀�ڂ��_�ł���悤�ɂ���
	int Select_;
	double Blink_;
	uniqueScene beforScene_;
	// �L�[�{�[�h���p�b�h��
	int input_;
	// ���y
	int SoundHandle;
	int soundHandle1;
};

