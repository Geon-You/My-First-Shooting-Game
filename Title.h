#pragma once
#include "Scene.h"
class Title :
    public Scene
{
public:
    // Scene��(��) ���� ��ӵ�
    void Initialize() override;
    SceneType Update() override;
    void Render() override;
    void Release() override;

public:
    Title();
    virtual ~Title();
};

