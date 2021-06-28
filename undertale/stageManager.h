#pragma once
#include "gameNode.h"
#include "startStage.h"
#include "stage2.h"
#include "stage3.h"
#include "stage4.h"
#include "stage5.h"
#include "stage6.h"
#include "stage7.h"
#include "undybattle.h"

class stageManager : public gameNode
{
	startStage* _stage1;
	stage2* _stage2;
	stage3* _stage3;
	stage4* _stage4;
	stage5* _stage5;
	stage6* _stage6;
	stage7* _stage7;

	undybattle* _undyb;

public :
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
};

