#pragma once
#include "Scene.h"
class GameOver :
    public Scene
{
public:
    GameOver();
    virtual ~GameOver();

    // Scene��(��) ���� ��ӵ�
    void Initialize() override;
    SceneType Update() override;
    void Render() override;
    void Release() override;
};

