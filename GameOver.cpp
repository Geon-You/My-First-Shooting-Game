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
	// 엔터 키를 눌렀다면 재도전
	if (GetAsyncKeyState(VK_RETURN))
	{
		// 씬을 인게임으로 변경
		return SceneType::INGAME;
	}
	// esc 키를 눌렀다면 게임 종료
	else if (GetAsyncKeyState(VK_ESCAPE))
	{
		isRun = false;
	}

	return SceneType::NONE;
}

void GameOver::Render()
{
	Panel::Print("Enter - 재도전, ESC - 게임 종료", 5, 12);
}

void GameOver::Release()
{
}
