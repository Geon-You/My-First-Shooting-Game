#include "Ingame.h"
#include "Player.h"
#include "Monster.h"
#include "Bullet.h"

Ingame::Ingame()
	:player(nullptr)
{
}

Ingame::~Ingame()
{
	Release();
}

void Ingame::SpawnMonster()
{
	if (prevSpawnTime + spawnDelayTime < GetTickCount())
	{
		prevSpawnTime = GetTickCount();
		Info monsterInfo("Monster", BufferSizeX - 5, rand() % BufferSizeY);
		Obj* monster = new Monster(monsterInfo);
		monster->Initialize();

		monsters.push_back(monster);
	}
}

void Ingame::Initialize()
{
	// 플레이어 객체 생성을 위해 플레이어 정보를 생성
	Info playerInfo("Player", 5, BufferSizeY / 2);

	player = new Player(playerInfo);
	// 생성한 플레이어 객체를 초기화
	player->Initialize();

	((Player*)player)->SetBullets(&bullets);

	prevSpawnTime = GetTickCount();
	spawnDelayTime = 500;
}

// 몬스터 업데이트, 렌더, 해제 작업 구현
// -> 화면 벗어날 시, 몬스터 객체 파괴
SceneType Ingame::Update()
{
	player->Update();
	SpawnMonster();

	// list 안에 있는 총알 객체들을 업데이트
	// 배열 사용 시에는 인덱스 값을 통해 원소에 접근했음
	// list는 원소에 접근할 때, iterator(반복자) 를 통해 접근 함

	// iterator 선언 시, 반복자가 어떤 타입의 반복자인지를 명시
	// for (int i = 0; i < length; ++i)와 같은 구조
	for (list<Bullet*>::iterator iter = bullets.begin();
		iter != bullets.end();)
	{
		// 총알 객체들의 업데이트 호출
		(*iter)->Update();

		// 총알이 화면을 벗어났다면, 파괴
		if ((*iter)->GetInfo().pos.x >= BufferSizeX - 2)
		{
			delete* iter;
			*iter = nullptr;

			// list.erase() 에 파라미터로 넘긴 공간을 리스트 안에서 지운 후,
			// 원래 해당 공간이 가리키고 있던 공간의 다음 위치를 iterator 형태로 반환을 해줌
			iter = bullets.erase(iter);
			// 위와 같은 경우 erase가 다음 위치를 반환하므로
			// 이터레이터를 다음 공간으로 넘길 필요가 없음
		}
		else
		{
			++iter;
		}
	}

	for (auto iter = monsters.begin();
		iter != monsters.end();)
	{
		// 몬스터 객체들의 업데이트 호출
		(*iter)->Update();

		// 몬스터가 화면을 벗어났다면, 파괴
		if ((*iter)->GetInfo().pos.x <= 2)
		{
			delete* iter;
			*iter = nullptr;

			// list.erase() 에 파라미터로 넘긴 공간을 리스트 안에서 지운 후,
			// 원래 해당 공간이 가리키고 있던 공간의 다음 위치를 iterator 형태로 반환을 해줌
			iter = monsters.erase(iter);
			// 위와 같은 경우 erase가 다음 위치를 반환하므로
			// 이터레이터를 다음 공간으로 넘길 필요가 없음
		}
		else
			++iter;
	}

	return CheckCollision();
}

void Ingame::Render()
{
	player->Render();

	for (auto iter = monsters.begin();
		iter != monsters.end(); ++iter)
	{
		// 몬스터 객체들의 업데이트 호출
		(*iter)->Render();
	}

	for (auto iter = bullets.begin();
		iter != bullets.end(); ++iter)
	{
		// 총알 객체들의 업데이트 호출
		(*iter)->Render();
	}
}

void Ingame::Release()
{
	if (player)
	{
		delete player;
		player = nullptr;
	}

	for (auto iter = monsters.begin(); iter != monsters.end(); ++iter)
	{
		if (*iter)
		{
			delete* iter;
			*iter = nullptr;
		}
	}

	for (auto iter = bullets.begin(); iter != bullets.end(); ++iter)
	{
		if (*iter)
		{
			delete* iter;
			*iter = nullptr;
		}
	}

	bullets.clear();
	monsters.clear();
}

SceneType Ingame::CheckCollision()
{
	// 몬스터와 플레이어 충돌 처리
	// (서로 간의 거리가 2 이하라면 충돌 처리)
	
	for (auto iter = monsters.begin(); iter != monsters.end(); ++iter)
	{
		// x축, y축 별 거리
		int distanceX = player->GetInfo().pos.x - (*iter)->GetInfo().pos.x;
		int distanceY = player->GetInfo().pos.y - (*iter)->GetInfo().pos.y;

		// 충돌 체크
		if ((distanceX <= 2 && distanceX >= -2)
			&& (distanceY <= 2 && distanceY >= -2))
		{
			return SceneType::GAMEOVER;
		}
	}

	// 몬스터와 총알 충돌 처리
	for (auto iter = monsters.begin(); iter != monsters.end();)
	{
		// 충돌 여부를 나타내는 변수
		bool isColl = false;

		// 몬스터 좌표를 받아둠
		int monsterPosX = (*iter)->GetInfo().pos.x;
		int monsterPosY = (*iter)->GetInfo().pos.y;

		for (auto iter2 = bullets.begin(); iter2 != bullets.end(); ++iter2)
		{
			int distanceX = monsterPosX - (*iter2)->GetInfo().pos.x;
			int distanceY = monsterPosY - (*iter2)->GetInfo().pos.y;

			if ((distanceX <= 2 && distanceX >= -2) && (distanceY <= 2 && distanceY >= -2))
			{
				isColl = true;

				delete* iter2;
				*iter2 = nullptr;
				bullets.erase(iter2);
				break;

				// 이미 비교대상인 몬스터가 총알리스트의 특정 총알 객체 하나와 충돌했음
				// 비교 대상인 몬스터가 제거되므로, 더 이상 총알리스트를 순회할 필요가 없음
				// 따라서, 총알리스트 공간 제거 시, 다음 공간의 위치를 받을 필요 없이, 안쪽 for문을 break 함
			}
		}

		// 몬스터가 특정 총알과 충돌했다면
		if (isColl)
		{
			delete* iter;
			*iter = nullptr;
			iter = monsters.erase(iter);
		}
		else
			++iter;
	}

	// 플레이어와 몬스터가 충돌하지 않았을 때, 기본 반환 값
	return SceneType::NONE;
}
