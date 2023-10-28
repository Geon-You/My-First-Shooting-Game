#pragma once
#include "Obj.h"
#include "Bullet.h"
#include "Monster.h"

class Player :
    public Obj
{
private:
    // 복수의 총알 객체를 담을 필드
    // 배열 말고 다른 컨테이너를 사용하려고 함
    // 배열이 왜 총알을 담기에 적절하지 않은지?
    // list는 STL(standard template library) 자료구조 중 하나, 배열과 비슷한 형태
    list<Bullet*>* bullets;

    DWORD prevFireTime; // 이전 발사 후, 지나간 시간
    DWORD delayTime; // 발사 딜레이 시간

public:
    void SetBullets(list<Bullet*>* bullets) { this->bullets = bullets; }


public:
    // Obj을(를) 통해 상속됨
    void Initialize() override;
    SceneType Update() override;
    void Render() override;
    void Release() override;
    void Fire();

public:
    Player(Info info);
    virtual ~Player();
};

