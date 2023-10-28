#pragma once
#include "Scene.h"

class Obj;
class Bullet;

class Ingame :
    public Scene
{
private:
    DWORD prevSpawnTime; // 이전 스폰 시간
    DWORD spawnDelayTime; // 스폰 딜레이 시간
    Obj* player; // 플레이어 객체를 담을 필드
    list<Obj*> monsters; // 몬스터 객체들을 담을 필드
    list<Bullet*> bullets; // 총알리스트의 주소를 담을 필드

private:
    void SpawnMonster(); // 몬스터 생성 기능

public:
    // Scene을(를) 통해 상속됨
    void Initialize() override;
    SceneType Update() override;
    void Render() override;
    void Release() override;
    // 몬스터 <-> 총알, 몬스터 <-> 플레이어 간의 충돌 처리
    SceneType CheckCollision();

public:
    Ingame();
    virtual ~Ingame();
};

