#pragma once
#include <vector>
#include "../Common/AnimMng.h"
#include "../Common/Geometry.h"
#include "../Common/Raycast.h"
#include "../Common/Collision.h"
#include "Obj.h"

// ����
#define ENEMY_RANGE (150.0)
// �p�x
#define ENEMY_ANGLE (20.0)

struct EnemyModuleNode;
struct EnemySetAnime;
struct EnemyNonCheckPlayer;
struct EnemyNonCheckBullet;

enum class EnemyID
{
    Red,
    Black,
    Boss
};

class Enemy :
    public Obj
{
public:
    Enemy(void);
    ~Enemy();
    bool Init(CntType cntType) override;
    virtual bool Init(void) = 0;
    void Update(double delta, TmxObj& tmxObj, std::list<std::unique_ptr<Obj>>& objlist) override;
    //virtual void Draw(void);
    //virtual void EnemyDraw(void);
    void Draw(void);
    void EnemyDraw(void);
    bool AtackHit(int damage) override;
    // �G�l�~�[�����񂾂Ƃ��̏���
    void DethEnemy(void);

    bool GetDeth(void);

    // �����_���ړ�
    void RandomMove(double delta);

    // ���m�͈͂��ق��̃N���X�ɓn��
    int GetDetection(void);
    // �ҋ@���Ԃ�n��
    double GetWaitTime_(void);

    // �G������ő��x���グ��
    double GetDethSpeed(void);

    virtual EnemyID GetEnemyID(void) = 0;

private:
    // �G�l�~�[���e��ǂ������邩�ǂ���
    bool ChaseFlag_;

    // �v���C���[���������Ă���̎���
    double stime_;
    // �����_���ňړ����邽��
    double randd_;

    // �v���C���[�̓����蔻��p�̑傫��
    int playerRad_;
    // �v���C���[�̒e�̓����蔻��p�̑傫��
    int plBRad_;
    
    // �G������ł����ɂ�ăX�s�[�h���オ��
    double DethSpeed_;

    // �G�l�~�[�̐����Ă��鐔
    size_t AliveEnemy_;

    // �v���C���[�̑O�̍��W
    Vector2Dbl oldPpod_;
    // �ǂɓ������ĉ��b��������
    double wTime_;

    // �e�������Ă��邩�ǂ���
    bool Pbalive_;

    // ����Ƀv���C���[�������Ă��邩�ǂ����̃t���O
    bool PEhit_;

    // �G�l�~�[�̎��S���o
    bool deth_;
    double vanishDeth_;

    // ���m�͈�
    int Detection_;
    // �G��������t���O
    bool vanishFlag_;
    // �G�������t���O
    bool appearFlag_;
    // �G�����ꂽ��A�������肷��Ƃ��̃J�E���g
    double count_;
    // �G�����ꂽ��A�������肵�����̎��Ԏw��
    double TimeLimit_;

    // �v���C���[�����G���ԓ����ǂ���
    bool InvFlag_;

    // �o�����Ă���v���C���[���U������܂ł̑ҋ@����
    double WaitTime_;

    // �v���C���[������ł��Ȃ�������͈͊O�ɂȂ��Ă��ǂ�������
    bool PlayerFlag_;
    bool ChaseFlag;

    // �r�b�N���}�[�N�̕\��
    bool SurprisFlag_;
    double SurprisTime_;

    bool buflag_;
    // ����̍��W
    Raycast raycast_;

    double Time_;

    friend EnemySetAnime;
    friend EnemyNonCheckPlayer;
    friend EnemyNonCheckBullet;

protected:


    AnimeData animeData_;
    int hp_;
    int oldHp_;
    std::vector<char> stateVec_;
    rapidxml::xml_node<>* stateNode_;
    rapidxml::xml_document<> stateDoc_;
    EnemyModuleNode* moduleNode_;
    // ���y
    int SoundHandle;


};

