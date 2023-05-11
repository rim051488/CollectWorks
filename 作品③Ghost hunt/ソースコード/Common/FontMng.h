#pragma once
#include "../Common/Vector2.h"
#include <string>

#define lpFontMng FontMng::GetInstance()

class FontMng
{
public:
	static FontMng& GetInstance()
	{
		static FontMng s_Instance;
		return s_Instance;
	}
	// �f�t�H���g�t�H���g
	bool DefaultFont(std::string str,Vector2Dbl pos,int size,int thick);
	bool DefaultFont(std::string str,Vector2Dbl pos,int size,int thick, int color);
	// �t�H���g�̎�ނ�ύX�ł���
	bool ChangeFont(std::string FontName, std::string str,Vector2Dbl pos, int size, int thick);
	bool ChangeFont(std::string FontName, std::string str,Vector2Dbl pos, int size, int thick, int color);
private:
	FontMng();
	~FontMng();
};

