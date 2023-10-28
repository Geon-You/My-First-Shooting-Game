#include "MainGame.h"
#include "SceneManager.h"

void MainGame::Initialize()
{
	// ���� ���� ��ü�� ����
	panel = new Panel;
	// ���� ���� ��ü �ʱ�ȭ
	panel->Initialize();

	// ���� ���� ����
	SceneManager::GetInstance()->SetScene(SceneType::TITLE);
}

void MainGame::Update()
{
	// ���� �� ������Ʈ
	// �� ��, ���� ������Ʈ�� ��ȯ Ÿ���� �� Ÿ����..
	// ��ȯ�Ǵ� �� Ÿ���� �����ϰ��� �ϴ� ���� �ִٸ�, �ش� ���� Ÿ���� ��ȯ�ϰԲ�, ������ ������ ����
	auto t = SceneManager::GetInstance()->GetScene()->Update();

	// ��ȯ ���� �� Ÿ�� NONE ���� ũ�ٸ�, ���� �����Ѵٴ� �ǹ�
	if (t > SceneType::NONE)
	{
		// �����ϰ��� �ϴ� ������ ����
		SceneManager::GetInstance()->SetScene(t);
	}
}

void MainGame::Render()
{
	// ȭ�� �����
	panel->Clear();

	// ���� �� �׸���
	SceneManager::GetInstance()->GetScene()->Render();

	// ȭ�� ��ȯ
	panel->Flip();
}

void MainGame::Release()
{
	// �г� ��ü �ı�
	if (panel)
	{
		delete panel;
		panel = nullptr;
	}

	// �� �Ŵ��� �ı�
	SceneManager::Destroy();
}

MainGame::MainGame()
{
}

MainGame::~MainGame()
{
	Release();
}
