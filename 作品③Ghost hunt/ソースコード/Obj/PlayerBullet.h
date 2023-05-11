#pragma once
#include <string>
#include "Obj.h"
#include "../../Tmx/TmxObj.h"
#include "../Common/Raycast.h"
#include "../Common/Geometry.h"
class PlayerBullet :
	public Obj
{
public:
    PlayerBullet();
    PlayerBullet(Vector2Dbl Pos, Vector2Dbl Pos2, Vector2Dbl Pos3);
    ~PlayerBullet();
    bool Init(void) override;
    bool Init(CntType cntType) override;
    // ������擾����Ǝ��̕���̏ꏊ���킩��悤�ɂ���
    bool SetNextPos(void);
    // Next�ɂ�����W�����̍��W�ɐ؂�ւ���
    bool Setpos(void);
    void Update(double delta, TmxObj& tmxObj, std::list<std::unique_ptr<Obj>>& objlist) override;
    void Draw(void) override;
    void SetHit(bool hit);
    int GetOutBullet(void);
    bool AtackHit(int damage) override;
private:
    ObjID GetObjID(void) override { return ObjID::PlayerBullet; };
    int Prad;
    int Erad;
    bool REflag_;
    bool BEflag_;
    // �G�ɒe���q�b�g�����Ƃ�
    bool hit_;
    // �G�ɒe�����������ꍇ
    bool alive;
    // �c�e��
    int outBullet_;
    Vector2Dbl bulletVel;
    // �G�l�~�[���e��ǂ������邩�ǂ���
    bool ChaseFlag;
    bool bulletFlag_;
    bool outFlag_;
    // �o������ʒu
    Vector2Dbl pos;
    Vector2Dbl pos2;
    Vector2Dbl pos3;
    // ���̏o������ʒu��ۑ�
    Vector2Dbl NextPos_;
    int NextRand_;
    bool NextFlag_;
    // 2�̖ڂ̓K�p
    Vector2Dbl enemypos_;
    Vector2Dbl MoveVec;
    bool enemyFlag_;
    // �e�����ł���^�C�~���O
    double dtime;
    std::string state_;
    Raycast raycast_;
    TmxObj* tmxobj;
    // �����ڗ������鏈��
    double count_;
    int timelimit;
    bool HighlightFlag_;
    // �o�����o
    std::string imagekey_;
    double AppTime_;
    // �v���C���[�̃t���O
    bool playerFlag_;
    // �L�[�{�[�h���p�b�h��
    int input_;
    // ���y
    int SoundHandle;
};

