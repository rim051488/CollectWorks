#pragma once
#include <memory>
#include "../Common/Vector2.h"
class BaseScene;
using uniqueScene = std::unique_ptr<BaseScene>;

// �V�[���̎��
enum class Scene
{
	Title /*�^�C�g���V�[��*/,
	Select/*�Z���N�g�V�[��*/,
	Game/*�Q�[���V�[��*/,
	GameClear/*�Q�[���N���A*/,
	GameOver/*�Q�[���I�[�o�[*/,
	Transition/*�g�����W�V�����V�[��*/,
	Info,/*�������*/
	Max	
};

class BaseScene
{
public:
	BaseScene();
	virtual ~BaseScene();
	virtual bool Init(void) = 0;
	virtual uniqueScene Update(double delta,uniqueScene ownScene) = 0;
	virtual void Draw(double delta);
	virtual void DrawOwnScreen(double delta) = 0;
	virtual Scene GetSceneID(void) = 0;
	// �V�[���̒��ŃQ�[�����I������������ꂽ��
	virtual bool IsAlive(void);
private:
protected:
	int screenID_;				// ���݂̃V�[����id���擾
	Vector2 screenSize_;		// �X�N���[���̃T�C�Y
	bool Alive_;				// �I�������I�񂾂��ǂ���
};

