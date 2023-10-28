#pragma once

// ������Ʈ�� ���� ���� ���, ������, ����ü ���� ����

extern bool isRun;

const int BufferSizeX = 140;
const int BufferSizeY = 40;

enum Color
{
	Black, // ����
	DarkBlue, // �Ķ�
	Green, // ���
	BlueGreen, // �ϴ�
	Blood, // ����
	Purple, // ����
	Gold, // ����
	Original, // ��ȸ��
	Gray, // ��ȸ��
	Blue, // ���Ķ�
	HighGreen, // ����
	SkyBlue, // ���ϴ�
	Red, // ������
	Plum, // ����ȫ
	Yellow, // ���
	White, // ���
};

// ���� �� ���Ǵ� ������ ����
enum SceneType
{
	NONE = -1,
	TITLE, // Ÿ��Ʋ ��
	INGAME, // �ΰ��� ��
	GAMEOVER, // ���� ���� ��
	END,
};

// 2���� ��ǥ�� ���� ����ü
typedef struct tagPoint
{
	int x;
	int y;
	tagPoint() {}
	tagPoint(int x, int y) : x(x), y(y) {}
}Point;

// �ΰ��� ��ü�� ���������� ���� �����͸� �����ص� ����ü
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