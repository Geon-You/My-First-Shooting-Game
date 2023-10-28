#include "Player.h"

Player::Player(Info info)
	: Obj(info)
{
}

Player::~Player()
{
	Release();
}

void Player::Initialize()
{
	// ������ ����, �ʱ�ȭ ������ ƽ ī��Ʈ�� �޴´�.
	prevFireTime = GetTickCount();
	delayTime = 100; // �� 0.1��
}

SceneType Player::Update()
{
	// ȭ��ǥ ����Ű ����
	if (GetAsyncKeyState(VK_UP))
	{
		if (info.pos.y >= 2)
			info.pos.y -= 1;
	}
	// ȭ��ǥ ����Ű �Ʒ���
	if (GetAsyncKeyState(VK_DOWN))
	{
		if (info.pos.y <= BufferSizeY - 3)
			info.pos.y += 1;
	}
	// ȭ��ǥ ����Ű ����
	if (GetAsyncKeyState(VK_LEFT))
	{
		if (info.pos.x >= 2)
			info.pos.x -= 1;
	}
	// ȭ��ǥ ����Ű ������
	if (GetAsyncKeyState(VK_RIGHT))
	{
		if (info.pos.x <= BufferSizeX - 5)
			info.pos.x += 1;
	}

	if (GetAsyncKeyState(VK_SPACE))
	{
		// ���� �߻� �ð� + ������ < ���� �ð�
		if (prevFireTime + delayTime < GetTickCount())
		{
			// �Ѿ��� �߻��Ͽ����Ƿ� ���� �߻� �ð��� ����
			prevFireTime = GetTickCount();
			Fire();
		}
	}

	// �Ѿ� ��ü���� �÷��̾ ������Ʈ �ϴ� ���� ���� ���� ������
	// ó���̴ϱ� ���ϰ� �Ϸ��� ���Ƿ� �̰����� ��.

	return SceneType::NONE;
}

void Player::Render()
{
	Panel::Print("->", info.pos.x - 1, info.pos.y - 1);
	Panel::Print("-->>", info.pos.x - 1, info.pos.y);
	Panel::Print("->", info.pos.x - 1, info.pos.y + 1);


}

void Player::Release()
{
	
}

void Player::Fire()
{
	// �Ѿ� ��ü ������ �ʿ��� �Ѿ� ���� ����
	Info bulletInfo("Bullet", info.pos.x + 3, info.pos.y);
	// �Ѿ� ��ü ����
	Bullet* bullet = new Bullet(bulletInfo);
	// ������ ��ü�� �ʱ�ȭ
	bullet->Initialize();

	// list�� ��ü�� �ִ� ��
	// push_back(), push_front() ���
	bullets->push_back(bullet);
}
