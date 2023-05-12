#include "Component.h"

Component::Component(Obj& owner) :
	owner_{owner}
{
}

Component::~Component()
{
}

// 更新処理
void Component::Update(float delta)
{
	// 何もしない
}

void Component::Update(float delta, std::string key)
{
}

