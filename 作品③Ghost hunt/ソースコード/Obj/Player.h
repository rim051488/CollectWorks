#pragma once
#include <vector>
#include <string>
#include "../Common/AnimMng.h"
#include "../Common/Raycast.h"
#include "../Common/Geometry.h"
#include "Obj.h"

struct PlayerModuleNode;
struct PlayerModuleNodeN;
struct PlayerSetAnime;

class Player :
    public Obj
{
public:
    Player();
    Player(CntType cntType,Vector2Dbl Pos);
    ~Player();
    bool Init(void) override;
    bool Init(CntType cntType) override;
    void Update(double delta, TmxObj& tmxObj, std::list<std::unique_ptr<Obj>>& objlist) override;
    void Draw(void) override;
    bool AtackHit(int damage) override;
    std::string GetState(void);
    double GetInvincible(void);
private:

    AnimeData animeData_;
    AnimeData shaderData_;
    Raycast raycast_;

    ObjID GetObjID(void) override { return ObjID::Player; };
    std::vector<char> stateVec_;
    rapidxml::xml_node<>* stateNode_;
    rapidxml::xml_document<> stateDoc_;
    PlayerModuleNode* moduleNode_;
    std::vector<char> stateVecN_;
    rapidxml::xml_node<>* stateNodeN_;
    rapidxml::xml_document<> stateDocN_;
    PlayerModuleNodeN* moduleNodeN_;

    // �G�̑傫��
    int enemyRad;
    // �e�̑傫��
    int buRad;
    // �e���������Ă��邩�ǂ���
    bool PBalive;

    // �v���C���[�̃t���O
    bool flag;
    double time_;
    double Time_;

    // �V�F�[�_�p�ϐ�
    int ps_;
    int cbuff_;
    float* threshold_;
    float angle_;
    // �c�@��\�����邩�ǂ���
    bool Hpflag_;
    // �ŏ��̎c�@��\�����鎞��
    double Hptime_;
    Vector2Dbl pos;
    // ���G����
    double InvTime_;
    bool Invincible_;
    // �ҋ@����
    double waitTime_;
    // �����яオ�銴����hp��\��
    double count_;
    double timelimit_;
    friend CheckKey;
    friend PlayerSetAnime;
    // ���y
    int SoundHandle;
};

