#pragma once
#include "Stage.h"

class Background;

class Stage_06 :
    public Stage
{
private:
	Vec2 m_vResolution;
	Background* m_pBack;

public:
	void update() override;
	void finalupdate() override;
	void render(HDC _dc) override;
	void Enter() override;
	void Exit() override;

public:
	void MakeUI();

public:
	Stage_06();
	~Stage_06();
};

