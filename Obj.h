#pragma once
#include "Include.h"
#include "Panel.h"

// 인게임 객체들의 추상 클래스
class Obj abstract
{
protected:
	Info info; // 객체의 이름과 위치를 갖는 필드

public:
	Info GetInfo() { return info; }

public:
	virtual void Initialize() abstract; // 객체 초기화
	virtual SceneType Update() abstract; // 객체 연산
	virtual void Render() abstract; // 객체 그리기
	virtual void Release() abstract; // 객체 파괴 시, 메모리 해제

public:
	Obj(Info info);
	virtual ~Obj();
};

