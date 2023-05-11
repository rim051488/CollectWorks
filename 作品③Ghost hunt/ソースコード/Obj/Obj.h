#pragma once
#include <memory>
#include <string>
#include "../../Tmx/TmxObj.h"
#include "../Common/Geometry.h"
#include "../Common/Vector2.h"
#include "../Input/Input.h"

struct CheckKey;
struct CheckKey2;
struct PlayerNotCheckKey2;
struct PlayerCheckCol;
struct PlayerCheckCol2;
struct PlayerCheckColKey;
struct PlayerCheckColKey2;
struct PlayerMove;
struct PlayerMove2;
struct EnemyCheckCol;
struct EnemyPlayerCheckCol;
struct EnemyNotCheckCol;
struct NotEnemyCol;
struct EnemyCheckRandom;
struct EnemyMove;
struct EnemyCheckPlayer;
struct EnemyBulletCheckMove;
struct EnemyPCheckCol;
struct EnemyRandomCheckCol;
struct EnemyLoseSight;

enum class ObjID
{
	Player,
	RedEnemy,
	BlackEnemy,
	BossEnemy,
	PlayerBullet,
	EnemyBullet
};

class Obj
{
public:
	Obj();
	~Obj();
	// ��X�������̕��ɕς���
	virtual bool Init(CntType cntType) = 0;
	virtual bool Init(void) = 0;

	virtual void Update(double delta,TmxObj& tmxObj, std::list<std::unique_ptr<Obj>>& objlist) = 0;
	virtual void Draw(void);

	virtual bool AtackHit(int damage) = 0;

	virtual Vector2Dbl GetPos(void);
	virtual void SetRand(double rand);
	virtual double GetRand(void);
	virtual int GetRad(void);
	virtual double GetLost(void);
	virtual bool GetFlag(void);
	virtual double GetDelta(void);
	virtual bool GetAlive(void);
	virtual bool IsAlive(void);
	virtual bool GetPflag(void);
	virtual bool GetEflag(void);
	virtual bool GetPLost(void);

	virtual void SetWall(bool wall);
	virtual void SetPfalg(bool pflag);
	virtual void SetPlost(bool plost);
	virtual void SetAngle(double angle);

	virtual Vector2Dbl GetEnemyPos(void);
	virtual Vector2Dbl GetPlayerPos(void);
	virtual Vector2Dbl GetPlBulletPos(void);
	virtual Vector2Dbl GetEnBulletPos(void);

	virtual ObjID GetObjID(void) = 0;
private:
protected:
	Vector2Dbl pos_;	// ���݂̍��W

	Vector2Dbl oldPos_;	// �O�̍��W

	// �v���C���[�����m�͈͂ɓ����Ă�����
	bool Pflag;
	// �G�l�~�[�̕��킪���m�͈͂ɓ����Ă�����
	bool Eflag;
	// �v���C���[������������
	bool PLost;
	// �G�l�~�[�̍��W
	Vector2Dbl RedEnemyPos_;
	Vector2Dbl BlackEnemyPos_;
	// �v���C���[�̍��W
	Vector2Dbl PlayerPos_;
	// �v���C���[�̕���̍��W
	Vector2Dbl PlBulletPos_;
	// �G�l�~�[�̕���̍��W
	Vector2Dbl EnBulletPos_;
	// �v���C���[��hp
	int PlayerHp;
	// �ړ����x
	double delta_;
	// �ړ����x
	double speed_;

	// �v���C���[�������Ă����ǂ���
	bool Palive_;

	// �ǂ̕����Ɉړ����邩
	double rand_;

	// �������ď�A�E�A���A���Ɗm�F����
	double Lost_;
	// �~�œ����蔻�������̂Ŕ��a�����߂�
	int radius_;
	// �ォ��������͈͂ɓ��������ɐF���w��
	int color_;
	// �`�悷�邩�ǂ���
	bool flag_;
	// �������Ă��邩
	bool Alive_;
	// ����ł�����
	bool alive_;
	// �G�ƃv���C���[�̊Ԃɕǂ����邩�ǂ���
	bool Wall_;

	// �p�x
	double Angle_;

	Geometry geometry_;

	std::unique_ptr<Input> controller_;
	friend PlayerNotCheckKey2;
	friend CheckKey;
	friend CheckKey2;
	friend PlayerCheckCol;
	friend PlayerCheckCol2;
	friend PlayerCheckColKey;
	friend PlayerCheckColKey2;
	friend PlayerMove;
	friend PlayerMove2;
	friend EnemyCheckCol;
	friend EnemyCheckRandom;
	friend EnemyCheckPlayer;
	friend EnemyMove;
	friend EnemyBulletCheckMove;
	friend EnemyNotCheckCol;
	friend EnemyPCheckCol;
	friend EnemyLoseSight;
	friend EnemyRandomCheckCol;
	friend EnemyPlayerCheckCol;
};

