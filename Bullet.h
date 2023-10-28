#pragma once
#include "Obj.h"
class Bullet :
    public Obj
{
public:
    // Obj을(를) 통해 상속됨
    void Initialize() override;
    SceneType Update() override;
    void Render() override;
    void Release() override;

public:
    Bullet(Info info);
    virtual ~Bullet();
};

