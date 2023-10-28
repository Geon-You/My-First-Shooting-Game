#pragma once
#include "Include.h"

// ���� ���� ����� ����� Ŭ���� 
class Panel
{
private:
	static HANDLE buffer[2]; // 2���� ��� ����(2���� �����ư��鼭 �׸��� ������)
	// ���� �迭���� Ư�� ���� ���� ��, ����� �ε���
	static int bufferIdx;

public:
	void Initialize(); // ���� �ʱ�ȭ �۾�
	void Clear(); // ���� �����
	void Flip(); // ���� ��ü
	void Release(); // ���� �ı� ��, �޸� ����

	// ���������� ���� ����ϰ� �� ���� ���� ��ɵ�
	// -> ���� ���� ��� ��, �Ϲ����� �ܼ� ��� �̿� �Ұ���
	//    ����, �Ʒ� ���ǵ� ��� ���� ��ɵ��� �̿��ϸ� ��
public:
	// Ŀ���� ��ġ�� �Ķ���ͷ� �ѱ� x, y ��ǥ�� ����
	static void Goto(int x, int y);
	// Ŀ���� x, y ��ǥ�� ���� ��, str ���ڿ��� ���
	static void Print(const char* str, int x, int y);
	// ��� ��, ���� ����
	// (�� �� ���� ��, �ٸ� ���� �����ϱ���� �ش� ������ ������)
	static void SetColor(Color color);

public:
	Panel();
	~Panel();
};

