#pragma once
#include "Vector2.h"

class Geometry
{
public:
	// �~�Ɖ~�̓����蔻��
	bool IsHit(const Vector2Dbl plPos, const Vector2Dbl enPos, const int plradius, const int enradius);

	// ���W�A��(rad)����x(deg)
	static double Rad2DegD(double rad);

	// �x(deg)���烉�W�A��(rad)
	static double Deg2RadD(double deg);

	// 0�`360�x�͈̔͂Ɏ��߂�
	static double DegIn360(double deg);

	// 0�`2��(360�x)�͈̔͂Ɏ��߂�
	static double RadIn2PI(double rad);
};
