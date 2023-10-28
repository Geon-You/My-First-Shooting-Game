#include "Bullet.h"

Bullet::Bullet(Info info)
    :Obj(info)
{
}

Bullet::~Bullet()
{
    Release();
}

void Bullet::Initialize()
{
}

SceneType Bullet::Update()
{
    ++info.pos.x;

    return SceneType::NONE;
}

void Bullet::Render()
{
    // 해당 함수 호출 이후, 모두 지정한 컬러로 출력됨
    Panel::SetColor(Color::Yellow);

    Panel::Print("ㅇ", info.pos.x - 1, info.pos.y -1);
    Panel::Print("ㅇ", info.pos.x - 1, info.pos.y);
    Panel::Print("ㅇ", info.pos.x - 1, info.pos.y + 1);

    // 총알 객체만 노란 색상 적용, 다른 객체는 원래 색상으로
    Panel::SetColor(Color::White);
}

void Bullet::Release()
{
}
