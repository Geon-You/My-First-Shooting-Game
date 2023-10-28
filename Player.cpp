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
	// 연산을 위해, 초기화 시점의 틱 카운트를 받는다.
	prevFireTime = GetTickCount();
	delayTime = 100; // 약 0.1초
}

SceneType Player::Update()
{
	// 화살표 방향키 위쪽
	if (GetAsyncKeyState(VK_UP))
	{
		if (info.pos.y >= 2)
			info.pos.y -= 1;
	}
	// 화살표 방향키 아래쪽
	if (GetAsyncKeyState(VK_DOWN))
	{
		if (info.pos.y <= BufferSizeY - 3)
			info.pos.y += 1;
	}
	// 화살표 방향키 왼쪽
	if (GetAsyncKeyState(VK_LEFT))
	{
		if (info.pos.x >= 2)
			info.pos.x -= 1;
	}
	// 화살표 방향키 오른쪽
	if (GetAsyncKeyState(VK_RIGHT))
	{
		if (info.pos.x <= BufferSizeX - 5)
			info.pos.x += 1;
	}

	if (GetAsyncKeyState(VK_SPACE))
	{
		// 이전 발사 시간 + 딜레이 < 현재 시간
		if (prevFireTime + delayTime < GetTickCount())
		{
			// 총알을 발사하였으므로 이전 발사 시간을 갱신
			prevFireTime = GetTickCount();
			Fire();
		}
	}

	// 총알 객체들을 플레이어가 업데이트 하는 것은 좋지 못한 구조임
	// 처음이니까 편하게 하려고 임의로 이곳에서 함.

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
	// 총알 객체 생성에 필요한 총알 정보 생성
	Info bulletInfo("Bullet", info.pos.x + 3, info.pos.y);
	// 총알 객체 생성
	Bullet* bullet = new Bullet(bulletInfo);
	// 생성한 객체를 초기화
	bullet->Initialize();

	// list에 객체를 넣는 법
	// push_back(), push_front() 사용
	bullets->push_back(bullet);
}
