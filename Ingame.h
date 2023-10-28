#pragma once
#include "Scene.h"

class Obj;
class Bullet;

class Ingame :
    public Scene
{
private:
    DWORD prevSpawnTime; // ���� ���� �ð�
    DWORD spawnDelayTime; // ���� ������ �ð�
    Obj* player; // �÷��̾� ��ü�� ���� �ʵ�
    list<Obj*> monsters; // ���� ��ü���� ���� �ʵ�
    list<Bullet*> bullets; // �Ѿ˸���Ʈ�� �ּҸ� ���� �ʵ�

private:
    void SpawnMonster(); // ���� ���� ���

public:
    // Scene��(��) ���� ��ӵ�
    void Initialize() override;
    SceneType Update() override;
    void Render() override;
    void Release() override;
    // ���� <-> �Ѿ�, ���� <-> �÷��̾� ���� �浹 ó��
    SceneType CheckCollision();

public:
    Ingame();
    virtual ~Ingame();
};

