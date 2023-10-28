#pragma once
#include "Panel.h"

class MainGame
{
private:
	Panel* panel; // ���� ���۸� ������ ��ü

public:
	// ���ΰ��� �ν��Ͻ��� �����ǰ�, ó�� �� �� �ʿ��� �ʱ�ȭ �۾� 
	void Initialize();
	// ���� �� �ʿ��� ���� ó��
	void Update();
	// ���� �� �׸��� �۾�
	void Render();
	// ���ΰ��� �ν��Ͻ��� �ı��� ��, ���� �Ҵ��ؼ� ����� ��ü�� �ִٸ�
	// �� ������ �޸� ����
	void Release();

public:
	MainGame();
	~MainGame();
};

