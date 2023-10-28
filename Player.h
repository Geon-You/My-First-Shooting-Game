#pragma once
#include "Obj.h"
#include "Bullet.h"
#include "Monster.h"

class Player :
    public Obj
{
private:
    // ������ �Ѿ� ��ü�� ���� �ʵ�
    // �迭 ���� �ٸ� �����̳ʸ� ����Ϸ��� ��
    // �迭�� �� �Ѿ��� ��⿡ �������� ������?
    // list�� STL(standard template library) �ڷᱸ�� �� �ϳ�, �迭�� ����� ����
    list<Bullet*>* bullets;

    DWORD prevFireTime; // ���� �߻� ��, ������ �ð�
    DWORD delayTime; // �߻� ������ �ð�

public:
    void SetBullets(list<Bullet*>* bullets) { this->bullets = bullets; }


public:
    // Obj��(��) ���� ��ӵ�
    void Initialize() override;
    SceneType Update() override;
    void Render() override;
    void Release() override;
    void Fire();

public:
    Player(Info info);
    virtual ~Player();
};

