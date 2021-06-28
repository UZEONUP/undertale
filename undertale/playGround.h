#pragma once
#include "gameNode.h"
#include "player.h"
#include "stageManager.h"



class playGround : public gameNode
{
private:
	stageManager* _sm;
	player* _player;

public:
	playGround();
	~playGround();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
};


































































