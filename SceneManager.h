#pragma once
#include "Include.h"
#include "Scene.h"

// 모든 씬 객체들을 제어할 클래스
// 현재 씬 객체를 필드로 가지고 있고, 현재 씬을 다른 씬으로 변경하는 기능을 갖음

// 따라서, 씬 변경을 위해서는 해당 클래스 객체(인스턴스)에 접근하여야만 함
// 이 말은 외부에서 접근이 빈번하다는 의미

// 디자인 패턴 중, 싱글톤 패턴을 이용
//  싱글톤 : 객체의 인스턴스를 단 하나로 유지, 외부에서 접근이 편리하게 함
//          
// 1. 편리한 접근을 위해서 -> (외부에서 빈번하게 접근하므로 )
// 2. 매니저 클래스이므로, 인스턴스가 하나만 존재하여야 함(매니저가 여러 개 있어봤자 의미가 없다.)

class SceneManager
{
public:
	Scene* currentScene; // 현재 씬의 인스턴스를 담을 필드

public:
	// 현재 씬 인스턴스를 반환하는 기능
	Scene* GetScene();
	// 현재 씬을 변경하는 기능
	// -> 파라미터로 받은 씬 타입에 따라, 타입에 맞는 씬으로 변경
	void SetScene(SceneType type);

#pragma region 씬 매니저 싱글톤 적용
private:
	static SceneManager* instance; // 씬 매니저의 인스턴스가 존재할 필드

private:
	// 생성자를 private으로 선언함으로써, 외부에서 객체의 인스턴스를 생성할 수 없음
	SceneManager();
public:
	~SceneManager();

public:
	// 씬 매니저 인스턴스를 반환하는 기능
	static SceneManager* GetInstance()
	{
		// 인스턴스가 없다면 생성
		if (instance == nullptr)
			instance = new SceneManager;

		// 생성 or 이미 있을 경우 리턴
		return instance;
	}

	static void Destroy()
	{
		if (instance)
		{
			delete instance;
			instance = nullptr;
		}
	}
#pragma endregion
};

