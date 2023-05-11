#pragma once
#include "Vector2.h"
#include "Collision.h"

class Raycast
{
public:
	struct Ray
	{
		Vector2Dbl p;			// �n�_
		Vector2Dbl vec;		// �����x�N�g��
	};
	struct Line
	{
		Vector2Dbl p;			// �n�_
		Vector2Dbl end;		// �I�_
		//Vector2 vec() { return end - p; }		// �����x�N�g��
	};
	std::pair<bool, Vector2Dbl> CheckCollision(Ray ray,Collision col);
	std::pair<bool, Vector2Dbl> CheckRay(Ray ray, Line line);
private:
};

