#pragma once
#include "gameNode.h"
#include "stageRect.h"
#include "player.h"

class stage7 : public gameNode
{
	stageRect* _setRect;

	Image* _backGround;
	player* _player;

public :
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	stageRect* getStageRect() { return _setRect; }
};

