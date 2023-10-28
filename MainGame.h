#pragma once
#include "Panel.h"

class MainGame
{
private:
	Panel* panel; // 더블 버퍼를 제어할 객체

public:
	// 메인게임 인스턴스가 생성되고, 처음 한 번 필요한 초기화 작업 
	void Initialize();
	// 게임 내 필요한 연산 처리
	void Update();
	// 게임 내 그리기 작업
	void Render();
	// 메인게임 인스턴스가 파괴될 때, 동적 할당해서 사용한 객체가 있다면
	// 이 곳에서 메모리 해제
	void Release();

public:
	MainGame();
	~MainGame();
};

