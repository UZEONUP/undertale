#pragma once
#include "gameNode.h"
#include "title.h"
#include "startStage.h"
#include "stage2.h"
#include "stage3.h"
#include "stage4.h"
#include "stage5.h"
#include "stage6.h"
#include "stage7.h"
#include "undybattle.h"
#include "sansBattle.h"
#include "stageRect.h"
#include "undyne.h"

class player;
class undyne;

class stageManager : public gameNode
{
	player* _player;
	stageRect* _stageRect;

	bool exit; //상점 들어갔다 나옴?
	bool returnStage3;

public :
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	void linkPlayer(player* player) { _player = player; }
	void linkStageRect(stageRect* sr) { _stageRect = sr; }

	//초기 셋팅
	void sceneSet();
};

