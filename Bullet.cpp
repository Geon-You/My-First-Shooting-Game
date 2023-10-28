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
    // �ش� �Լ� ȣ�� ����, ��� ������ �÷��� ��µ�
    Panel::SetColor(Color::Yellow);

    Panel::Print("��", info.pos.x - 1, info.pos.y -1);
    Panel::Print("��", info.pos.x - 1, info.pos.y);
    Panel::Print("��", info.pos.x - 1, info.pos.y + 1);

    // �Ѿ� ��ü�� ��� ���� ����, �ٸ� ��ü�� ���� ��������
    Panel::SetColor(Color::White);
}

void Bullet::Release()
{
}
