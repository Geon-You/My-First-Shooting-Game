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
	// �÷��̾� ��ü ������ ���� �÷��̾� ������ ����
	Info playerInfo("Player", 5, BufferSizeY / 2);

	player = new Player(playerInfo);
	// ������ �÷��̾� ��ü�� �ʱ�ȭ
	player->Initialize();

	((Player*)player)->SetBullets(&bullets);

	prevSpawnTime = GetTickCount();
	spawnDelayTime = 500;
}

// ���� ������Ʈ, ����, ���� �۾� ����
// -> ȭ�� ��� ��, ���� ��ü �ı�
SceneType Ingame::Update()
{
	player->Update();
	SpawnMonster();

	// list �ȿ� �ִ� �Ѿ� ��ü���� ������Ʈ
	// �迭 ��� �ÿ��� �ε��� ���� ���� ���ҿ� ��������
	// list�� ���ҿ� ������ ��, iterator(�ݺ���) �� ���� ���� ��

	// iterator ���� ��, �ݺ��ڰ� � Ÿ���� �ݺ��������� ���
	// for (int i = 0; i < length; ++i)�� ���� ����
	for (list<Bullet*>::iterator iter = bullets.begin();
		iter != bullets.end();)
	{
		// �Ѿ� ��ü���� ������Ʈ ȣ��
		(*iter)->Update();

		// �Ѿ��� ȭ���� ����ٸ�, �ı�
		if ((*iter)->GetInfo().pos.x >= BufferSizeX - 2)
		{
			delete* iter;
			*iter = nullptr;

			// list.erase() �� �Ķ���ͷ� �ѱ� ������ ����Ʈ �ȿ��� ���� ��,
			// ���� �ش� ������ ����Ű�� �ִ� ������ ���� ��ġ�� iterator ���·� ��ȯ�� ����
			iter = bullets.erase(iter);
			// ���� ���� ��� erase�� ���� ��ġ�� ��ȯ�ϹǷ�
			// ���ͷ����͸� ���� �������� �ѱ� �ʿ䰡 ����
		}
		else
		{
			++iter;
		}
	}

	for (auto iter = monsters.begin();
		iter != monsters.end();)
	{
		// ���� ��ü���� ������Ʈ ȣ��
		(*iter)->Update();

		// ���Ͱ� ȭ���� ����ٸ�, �ı�
		if ((*iter)->GetInfo().pos.x <= 2)
		{
			delete* iter;
			*iter = nullptr;

			// list.erase() �� �Ķ���ͷ� �ѱ� ������ ����Ʈ �ȿ��� ���� ��,
			// ���� �ش� ������ ����Ű�� �ִ� ������ ���� ��ġ�� iterator ���·� ��ȯ�� ����
			iter = monsters.erase(iter);
			// ���� ���� ��� erase�� ���� ��ġ�� ��ȯ�ϹǷ�
			// ���ͷ����͸� ���� �������� �ѱ� �ʿ䰡 ����
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
		// ���� ��ü���� ������Ʈ ȣ��
		(*iter)->Render();
	}

	for (auto iter = bullets.begin();
		iter != bullets.end(); ++iter)
	{
		// �Ѿ� ��ü���� ������Ʈ ȣ��
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
	// ���Ϳ� �÷��̾� �浹 ó��
	// (���� ���� �Ÿ��� 2 ���϶�� �浹 ó��)
	
	for (auto iter = monsters.begin(); iter != monsters.end(); ++iter)
	{
		// x��, y�� �� �Ÿ�
		int distanceX = player->GetInfo().pos.x - (*iter)->GetInfo().pos.x;
		int distanceY = player->GetInfo().pos.y - (*iter)->GetInfo().pos.y;

		// �浹 üũ
		if ((distanceX <= 2 && distanceX >= -2)
			&& (distanceY <= 2 && distanceY >= -2))
		{
			return SceneType::GAMEOVER;
		}
	}

	// ���Ϳ� �Ѿ� �浹 ó��
	for (auto iter = monsters.begin(); iter != monsters.end();)
	{
		// �浹 ���θ� ��Ÿ���� ����
		bool isColl = false;

		// ���� ��ǥ�� �޾Ƶ�
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

				// �̹� �񱳴���� ���Ͱ� �Ѿ˸���Ʈ�� Ư�� �Ѿ� ��ü �ϳ��� �浹����
				// �� ����� ���Ͱ� ���ŵǹǷ�, �� �̻� �Ѿ˸���Ʈ�� ��ȸ�� �ʿ䰡 ����
				// ����, �Ѿ˸���Ʈ ���� ���� ��, ���� ������ ��ġ�� ���� �ʿ� ����, ���� for���� break ��
			}
		}

		// ���Ͱ� Ư�� �Ѿ˰� �浹�ߴٸ�
		if (isColl)
		{
			delete* iter;
			*iter = nullptr;
			iter = monsters.erase(iter);
		}
		else
			++iter;
	}

	// �÷��̾�� ���Ͱ� �浹���� �ʾ��� ��, �⺻ ��ȯ ��
	return SceneType::NONE;
}
