#pragma once
#include "Include.h"
#include "Panel.h"

// �ΰ��� ��ü���� �߻� Ŭ����
class Obj abstract
{
protected:
	Info info; // ��ü�� �̸��� ��ġ�� ���� �ʵ�

public:
	Info GetInfo() { return info; }

public:
	virtual void Initialize() abstract; // ��ü �ʱ�ȭ
	virtual SceneType Update() abstract; // ��ü ����
	virtual void Render() abstract; // ��ü �׸���
	virtual void Release() abstract; // ��ü �ı� ��, �޸� ����

public:
	Obj(Info info);
	virtual ~Obj();
};

