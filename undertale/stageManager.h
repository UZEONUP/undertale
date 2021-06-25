#pragma once
#include "gameNode.h"
#include "startStage.h"
#include "stage2.h"
#include "undybattle.h"


class stageManager : public gameNode
{
	startStage* _stage1;
	stage2* _stage2;
	undybattle* _undybattle;

public :
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
};

