#include "MainGame.h"

// ���� ���� ���¸� ��Ÿ���� ���� ����
bool isRun = true;

void main()
{
	// ���ΰ��� ��ü ����
	MainGame mainGame;

	// ���� ���� ��, �ʿ��� �ʱ�ȭ �۾�
	mainGame.Initialize();

	// ���� ���ᰡ �ƴ϶�� ���� ������ �ݺ�
	while (isRun)
	{
		mainGame.Update(); // ���ӿ� �ʿ��� ���� ����
		mainGame.Render(); // ���ӿ� �ʿ��� �׸��� ����
	}

	// ���� �ݺ��� ����Ǿ��ٸ�, ������ �����ٴ� ���̹Ƿ�
	// �޸� ���� ����
	mainGame.Release();
}