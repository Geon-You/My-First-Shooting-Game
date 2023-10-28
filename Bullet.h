#pragma once
#include "Obj.h"
class Bullet :
    public Obj
{
public:
    // Obj��(��) ���� ��ӵ�
    void Initialize() override;
    SceneType Update() override;
    void Render() override;
    void Release() override;

public:
    Bullet(Info info);
    virtual ~Bullet();
};

