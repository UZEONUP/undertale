#pragma once
#include "gameNode.h"
#include "player.h"
#include "stageManager.h"
#include "startStage.h"


struct tagRRect
{
	RECT rc;
	float x, y;
};

class playGround : public gameNode
{
private:
	tagRRect rc;
	float angle;
	float an2;

	

	player* _player;
	

	RECT _backRc;
	
	stageManager* _sm;
	startStage* _stage1;


public:
	playGround();
	~playGround();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
};


































































