#pragma once

// 프로젝트에 자주 사용될 상수, 열거형, 구조체 등을 정의

extern bool isRun;

const int BufferSizeX = 140;
const int BufferSizeY = 40;

enum Color
{
	Black, // 검정
	DarkBlue, // 파랑
	Green, // 녹색
	BlueGreen, // 하늘
	Blood, // 빨강
	Purple, // 보라
	Gold, // 갈색
	Original, // 연회색
	Gray, // 진회색
	Blue, // 연파랑
	HighGreen, // 연두
	SkyBlue, // 연하늘
	Red, // 연빨강
	Plum, // 연분홍
	Yellow, // 노랑
	White, // 흰색
};

// 게임 내 사용되는 씬들을 열거
enum SceneType
{
	NONE = -1,
	TITLE, // 타이틀 씬
	INGAME, // 인게임 씬
	GAMEOVER, // 게임 오버 씬
	END,
};

// 2차원 좌표를 갖는 구조체
typedef struct tagPoint
{
	int x;
	int y;
	tagPoint() {}
	tagPoint(int x, int y) : x(x), y(y) {}
}Point;

// 인게임 객체가 공통적으로 갖는 데이터를 정의해둔 구조체
typedef struct tagInfo
{
	const char* name;
	Point pos;
	tagInfo() {}
	tagInfo(const char* name, int x, int y)
	{
		this->name = name;
		pos = Point(x, y);
	}
}Info;