#include "Monster.h"

Monster::Monster(Info info)
	:Obj(info)
{
}

Monster::~Monster()
{
	Release();
}

void Monster::Initialize()
{
}

SceneType Monster::Update()
{
	--info.pos.x;

	return SceneType::NONE;
}

void Monster::Render()
{
	Panel::SetColor(Color::Red);
	Panel::Print("<<-%-<", info.pos.x - 3, info.pos.y);
	Panel::SetColor(Color::White);
}

void Monster::Release()
{
}
