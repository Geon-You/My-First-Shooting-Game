#include "GameOver.h"

GameOver::GameOver()
{
}

GameOver::~GameOver()
{
	Release();
}

void GameOver::Initialize()
{
}

SceneType GameOver::Update()
{
	// ���� Ű�� �����ٸ� �絵��
	if (GetAsyncKeyState(VK_RETURN))
	{
		// ���� �ΰ������� ����
		return SceneType::INGAME;
	}
	// esc Ű�� �����ٸ� ���� ����
	else if (GetAsyncKeyState(VK_ESCAPE))
	{
		isRun = false;
	}

	return SceneType::NONE;
}

void GameOver::Render()
{
	Panel::Print("Enter - �絵��, ESC - ���� ����", 5, 12);
}

void GameOver::Release()
{
}
