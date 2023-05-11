#pragma once
#include "Obj.h"
class EnemyBullet :
	public Obj
{
public:
    EnemyBullet();
    ~EnemyBullet();
    bool Init(void) override;
    bool InitAlive(void);
    bool Init(CntType cntType) override;
    void Update(double delta, TmxObj& tmxObj, std::list<std::unique_ptr<Obj>>& objlist) override;
    void Draw(void) override;
    bool AtackHit(int damage) override;
private:
    ObjID GetObjID(void) override { return ObjID::EnemyBullet; };
    int Prad;
    int Erad;
    Vector2Dbl bulletVel;
    bool RedAlive;
    bool BlackAlive;
    // �G�l�~�[���e��ǂ������邩�ǂ���
    bool ChaseFlag;

    // �e�����ł���^�C�~���O
    double dtime;

};

