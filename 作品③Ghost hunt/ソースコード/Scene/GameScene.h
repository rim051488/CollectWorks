#pragma once
#include <memory>
#include <list>
#include <map>
#include "BaseScene.h"
#include "../Common/Vector2.h"
#include "../Common/Geometry.h"
#include "../../Tmx/TmxObj.h"
#include "../Obj/Enemy.h"
#include "../Obj/Obj.h"
struct GetPos;
struct Getpos;
class GameScene :
    public BaseScene
{
public:
    GameScene();
    GameScene(std::string filename, std::string map, std::string pos);
    ~GameScene();
private:
    bool Init(void) override;
    bool Init(std::string filename);
    uniqueScene Update(double delta, uniqueScene ownScene) override;
    void DrawOwnScreen(double delta) override;
    Scene GetSceneID(void) override { return Scene::Game; };

    // �ȈՓI�ȃJ�E���g�_�E���p�̕ϐ�(�f���^���g���̂�double�ɂ��Ă���)
    double time_;
    double Endtime_;
    // ��������
    double timeLimit_;
    // �v���C���[�������Ă��邩�ǂ���
    bool PlayerAlive_;
    // �L�[���A�����ĉ�����Ȃ��悤�Ƀf�B���C��������
    double delay;
    double second;
    double count_;
    int timelimit;
    // �e�̎c�e��
    int outBullet_;
    // �}�b�v�̏��Ƃ��̃}�b�v�Ɏg���Ă���摜��n����悤�ɂ��Ă���
    std::string fileName_;
    std::string map_;
    // obj�̍��W���t�@�C������ǂݎ��
    std::string objPos_;
    // Obj��list������
    std::list<std::unique_ptr<Obj>> objList_;
    // �G�̍��W���Ⴄ�ꏊ�ɂ���2���
    std::list<std::unique_ptr<Obj>> EnemyList_;
    std::list<std::unique_ptr<Obj>> enemyList_;
    // �{�X��obj
    std::list<std::unique_ptr<Obj>> bossList_;
    bool Bossflag_;
    double BossTime_;
    bool bossdeth;
    bool bossApp_;
    size_t objsize;
    // �G�����񂾐�
    int dethEnemy_;
    //std::map<std::string, std::unique_ptr<Obj>> objListMap_;
    CntType cntType_;
    Geometry geometry;
    TmxObj tmxObj_;
    std::vector<char> stateVec_;
    rapidxml::xml_node<>* stateNode_;
    rapidxml::xml_document<> stateDoc_;
    GetPos* moduleNode_;
    // �L�[�{�[�h���p�b�h��
    int input_;
    // ���y
    int SoundHandle;
    int soundHandle1;
};

