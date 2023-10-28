#pragma once
#include "Include.h"
#include "Scene.h"

// ��� �� ��ü���� ������ Ŭ����
// ���� �� ��ü�� �ʵ�� ������ �ְ�, ���� ���� �ٸ� ������ �����ϴ� ����� ����

// ����, �� ������ ���ؼ��� �ش� Ŭ���� ��ü(�ν��Ͻ�)�� �����Ͽ��߸� ��
// �� ���� �ܺο��� ������ ����ϴٴ� �ǹ�

// ������ ���� ��, �̱��� ������ �̿�
//  �̱��� : ��ü�� �ν��Ͻ��� �� �ϳ��� ����, �ܺο��� ������ ���ϰ� ��
//          
// 1. ���� ������ ���ؼ� -> (�ܺο��� ����ϰ� �����ϹǷ� )
// 2. �Ŵ��� Ŭ�����̹Ƿ�, �ν��Ͻ��� �ϳ��� �����Ͽ��� ��(�Ŵ����� ���� �� �־���� �ǹ̰� ����.)

class SceneManager
{
public:
	Scene* currentScene; // ���� ���� �ν��Ͻ��� ���� �ʵ�

public:
	// ���� �� �ν��Ͻ��� ��ȯ�ϴ� ���
	Scene* GetScene();
	// ���� ���� �����ϴ� ���
	// -> �Ķ���ͷ� ���� �� Ÿ�Կ� ����, Ÿ�Կ� �´� ������ ����
	void SetScene(SceneType type);

#pragma region �� �Ŵ��� �̱��� ����
private:
	static SceneManager* instance; // �� �Ŵ����� �ν��Ͻ��� ������ �ʵ�

private:
	// �����ڸ� private���� ���������ν�, �ܺο��� ��ü�� �ν��Ͻ��� ������ �� ����
	SceneManager();
public:
	~SceneManager();

public:
	// �� �Ŵ��� �ν��Ͻ��� ��ȯ�ϴ� ���
	static SceneManager* GetInstance()
	{
		// �ν��Ͻ��� ���ٸ� ����
		if (instance == nullptr)
			instance = new SceneManager;

		// ���� or �̹� ���� ��� ����
		return instance;
	}

	static void Destroy()
	{
		if (instance)
		{
			delete instance;
			instance = nullptr;
		}
	}
#pragma endregion
};

