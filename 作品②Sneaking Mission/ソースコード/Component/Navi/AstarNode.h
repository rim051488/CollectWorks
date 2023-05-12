#pragma once
#include <memory>
#include <list>
#include "../../common/Math.h"

// Astar�T���p�̃m�[�h
class AstarNode
{
public:
	AstarNode(const Math::Vector2I& pos);
	AstarNode();

	/// <summary>
	/// ���e���N���A����
	/// </summary>
	void Clear();

	/// <summary>
	/// �g�[�^���R�X�g�̎擾
	/// </summary>
	/// <param name=""></param>
	/// <returns> �g�[�^���R�X�g </returns>
	const int GetTotalCost(void) const;

	/// <summary>
	/// �g�[�^���̃R�X�g�̃Z�b�g
	/// </summary>
	/// <param name="cost"> �R�X�g </param>
	void SetTotalCost(int cost);

	/// <summary>
	/// �q���[���X�e�B�b�N�R�X�g�̎擾
	/// </summary>
	/// <param name=""></param>
	/// <returns></returns>
	const int GetHeuristicCost(void) const;

	/// <summary>
	/// �w��̍��W�܂ł̃q���[���X�e�B�b�N�R�X�g���v�Z����
	/// </summary>
	/// <param name="pos"> ���W(�}�X��) </param>
	void CalculateHeuristicCost(const Math::Vector2I& pos);

	/// <summary>
	/// ���W(�}�X��)���擾����
	/// </summary>
	/// <param name=""></param>
	/// <returns> �}�X�� </returns>
	const Math::Vector2I& GetPos(void) const;

	/// <summary>
	/// ���W(�}�X��)���Z�b�g����
	/// </summary>
	/// <param name="pos"> �}�X�� </param>
	void SetPos(const Math::Vector2I& pos) { pos_ = pos; }

	/// <summary>
	/// �אڃm�[�h�̃��X�g���擾
	/// </summary>
	/// <param name=""></param>
	/// <returns></returns>
	const std::list<AstarNode*> GetNextNode(void) const { return nextNode_; }

	/// <summary>
	/// �אڃm�[�h��ǉ�����
	/// </summary>
	/// <param name="node"></param>
	void PushNext(AstarNode* node) { nextNode_.emplace_back(node); }

private:

	// ���W(�}�X��)
	Math::Vector2I pos_;

	// ��O�̍��W(�}�X��)
	Math::Vector2I beforPos_;

	// �אڃm�[�h
	std::list<AstarNode*> nextNode_;

	// �q���[���X�e�B�b�N�R�X�g(�S�[���܂ł̋������R�X�g��)
	int heuristicCost_;

	// ���v�R�X�g
	int totalCost_;
};

