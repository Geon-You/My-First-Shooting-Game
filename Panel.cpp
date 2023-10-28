#include "Panel.h"

// static �ʵ� �ʱ�ȭ
int Panel::bufferIdx = 0;
HANDLE Panel::buffer[2];

Panel::Panel()
{
	memset(buffer, 0, sizeof(buffer));
}

Panel::~Panel()
{
	Release();
}


void Panel::Initialize()
{
	// ������ ���� ũ�� ����
	COORD size = { BufferSizeX, BufferSizeY };
	// ���۸� ������ ��, ����� �簢�� ������ ����
	SMALL_RECT rc;
	rc.Left = 0;
	rc.Right = BufferSizeX - 1;
	rc.Top = 0;
	rc.Bottom = BufferSizeY - 1;

	// Ŀ���� ���� ���� (�Ⱥ��̰Բ�)
	CONSOLE_CURSOR_INFO cursorInfo = { 0, };
	cursorInfo.dwSize = 1; // Ŀ�� ���� ����
	cursorInfo.bVisible = FALSE; // Ŀ���� ������ �ʰ� ����

	// ���� ���� ���� ���� 2���� ���۸� ����
	for (int i = 0; i < 2; ++i)
	{
		buffer[i] = CreateConsoleScreenBuffer(
		GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
		SetConsoleScreenBufferSize(buffer[i], size);
		SetConsoleWindowInfo(buffer[i], TRUE, &rc);
		SetConsoleCursorInfo(buffer[i], &cursorInfo);
	}
}

void Panel::Clear()
{
	// �ֿܼ��� ��� �۾� ��, ���� Ŀ�� ��ġ�� �������� �۾��� ����
	// ȭ�� ��ü�� ������ �� �ְ� ����ϰ� �ִ� Ŀ���� ��ġ�� 0, 0���� ����
	// ����� �۾� ��, ���� ���ڷ� ���� ��ü�� �����
	Goto(0, 0);
	COORD coord = { 0, 0 };
	DWORD dw;
	FillConsoleOutputCharacter(buffer[bufferIdx], ' ', BufferSizeX * BufferSizeY, coord, &dw);
}

void Panel::Flip()
{
	Sleep(10);
	// 2�� ���� �߿� ��¿� ����� ���۸� Ȱ��ȭ
	SetConsoleActiveScreenBuffer(buffer[bufferIdx]);
	// idx ��° ���۸� Ȱ��ȭ ��������, ���� �ε����� ����
	bufferIdx = !bufferIdx; // 0, 1, 0, 1 �������� �����Ǹ鼭 ���۰� �ٲ�
}

void Panel::Release()
{
}

void Panel::Goto(int x, int y)
{
	COORD pos = { x, y };
	SetConsoleCursorPosition(buffer[bufferIdx], pos);
}

void Panel::Print(const char* str, int x, int y)
{
	Goto(x, y);
	DWORD dw;
	WriteFile(buffer[bufferIdx], str, strlen(str), &dw, NULL);
}

void Panel::SetColor(Color color)
{
	SetConsoleTextAttribute(buffer[bufferIdx], (unsigned short)color);
}