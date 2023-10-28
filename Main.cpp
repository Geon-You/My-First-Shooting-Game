#include "MainGame.h"

// 게임 실행 상태를 나타내는 전역 변수
bool isRun = true;

void main()
{
	// 메인게임 객체 생성
	MainGame mainGame;

	// 게임 시작 전, 필요한 초기화 작업
	mainGame.Initialize();

	// 게임 종료가 아니라면 메인 로직을 반복
	while (isRun)
	{
		mainGame.Update(); // 게임에 필요한 연산 실행
		mainGame.Render(); // 게임에 필요한 그리기 실행
	}

	// 위의 반복이 종료되었다면, 게임이 끝났다는 뜻이므로
	// 메모리 해제 진행
	mainGame.Release();
}