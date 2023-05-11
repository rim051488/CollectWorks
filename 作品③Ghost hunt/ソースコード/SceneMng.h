#pragma once
#include "Scene/BaseScene.h"

#define lpSceneMng SceneMng::GetInstance()

class SceneMng
{
public:
	// �ÓI�ȃV���O���g��
	static SceneMng& GetInstance()
	{
		static SceneMng s_Instance;
		return s_Instance;
	}

	void Run(void);			// ���s����
private:
	bool SysInit(void);		// ����������
	void Update(void);
	void Draw(double delta);
	bool InitFlag_;
	uniqueScene scene_;
	SceneMng();
	~SceneMng();
	bool SceneAlive_;		// �I���{�^���������ꂽ���ǂ���

};

