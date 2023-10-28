#include "SceneManager.h"
#include "Title.h"
#include "Ingame.h"
#include "GameOver.h"

// Ŭ���� ���� ���� �ʵ尡 �����Ѵٸ�,
// Ŭ���� �ܺ� ���� �������� ���� �ʵ带 �ʱ�ȭ�ؾ� ��
// ����ó�� Ŭ������ .h�� .cpp�� �и��� ���,
// .cpp ���� �������� �ʱ�ȭ�� �����ϸ� ��
// ���� .h�� ����Ѵٸ� ��� ������ ���� �������� �ʱ�ȭ�� �����ϸ� ��
SceneManager* SceneManager::instance = nullptr;

Scene* SceneManager::GetScene()
{
	return currentScene;
}

void SceneManager::SetScene(SceneType type)
{
	// ���� ���� ���ο� ������ �����ϱ� ����
	// ���� �� ��ü�� ������
	if (currentScene)
	{
		delete currentScene;
		currentScene = nullptr;
	}

	switch (type)
	{
	case TITLE:
		// Ÿ��Ʋ �� ��ü �Ҵ�
		currentScene = new Title();
		break;
	case INGAME:
		currentScene = new Ingame();
		break;
	case GAMEOVER:
		currentScene = new GameOver();
		break;
	}

	// ���� ������ ���ؼ�, ��������� currentScene��
	// ���ο� ���� �Ҵ��Ͽ����Ƿ�, ���ο� ���� �ʱ�ȭ
	currentScene->Initialize();
}

SceneManager::SceneManager()
{
}

SceneManager::~SceneManager()
{
	if (currentScene)
	{
		// �� �Ŵ��� ��ü �ı� ��, ���� ���� �����Ѵٸ� �޸� ����
		delete currentScene;
		currentScene = nullptr;
	}
}
