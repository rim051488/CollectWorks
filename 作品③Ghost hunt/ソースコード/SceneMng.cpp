#include "SceneMng.h"
#include <DxLib.h>
#include <memory>
#include <chrono>
#include "Scene/GameScene.h"
#include "Scene/SelectScene.h"
#include "Scene/TitleScene.h"
#include "../_debug/_DebugConOut.h"
#include "../_debug/_DebugDispOut.h"

constexpr int ScreenSizeX = 1024;
constexpr int ScreenSizeY = 768;

void SceneMng::Run(void)
{
	if (!InitFlag_)
	{
		if (!SysInit())		// �m�F�̂��߂ɂ�����x�C�j�V�����C�Y����
		{
			return;
		}
	}
	// �}�E�X�J�[�\�����\���ɂ���
	SetMouseDispFlag(false);
	// �}�E�X�J�[�\�����E�C���h�E�̃N���C�A���g�G���A�O�ɍs���邩�ǂ���
	//SetValidMousePointerWindowOutClientAreaMoveFlag(false);		// ����͂��Ԃ�g��Ȃ����ȁ[
	// �E�B���h�E����A�N�e�B�u�ł�������~�߂Ȃ�
	SetAlwaysRunFlag(true);
	// �ŏ��̃V�[�����C���X�^���X
	scene_ = std::make_unique<TitleScene>();
	std::chrono::system_clock::time_point nowTime, oldTime;
	nowTime = std::chrono::system_clock::now();
	SceneAlive_ = scene_->IsAlive();

	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0 && SceneAlive_)
	{
		_dbgStartDraw();
		double delta = 0.0;
		if (GetWindowActiveFlag() == TRUE)
		{
			// �A�N�e�B�u
			oldTime = nowTime;
			nowTime = std::chrono::system_clock::now();
			auto elTime = nowTime - oldTime;

			auto msec = std::chrono::duration_cast<std::chrono::microseconds>(elTime).count();
			delta = msec / 1000000.0;
		}
		else
		{
			// ��A�N�e�B�u
			delta = 0.0;
			oldTime = nowTime;
			nowTime = std::chrono::system_clock::now();
			auto elTime = nowTime - oldTime;
		}
		scene_ = scene_->Update(delta, std::move(scene_));
		Draw(delta);

		SceneAlive_ = scene_->IsAlive();
	}
}

void SceneMng::Update(void)
{
}

void SceneMng::Draw(double delta)
{
	SetDrawScreen(DX_SCREEN_BACK);
	ClsDrawScreen();

	scene_->Draw(delta);

	//_dbgDraw();
	ScreenFlip();

}

bool SceneMng::SysInit(void)
{
	SetWindowText("Ghost Hunt");

	SetGraphMode(ScreenSizeX, ScreenSizeY, 32);
	ChangeWindowMode(true);
	if (DxLib_Init() == -1)
	{
		return false;
	}
	//_dbgSetup(ScreenSizeX, ScreenSizeY, 255);

	return true;
}

SceneMng::SceneMng()
{
	InitFlag_ = SysInit();
}

SceneMng::~SceneMng()
{
}
