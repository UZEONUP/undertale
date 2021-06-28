#pragma once
#include "gameNode.h"
#include "stageRect.h"
#include "player.h"
#include "undyne.h"

class stage2 : public gameNode
{
	stageRect* _setRect;
	
	Image* _backGround;
	
	
	RECT _bg;
	player* _player;
	undyne* _undy;

	RECT _sceneRect;

public :
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	player* getPlayer() { return _player; }
	RECT getSceneRect() { return _sceneRect; }
};

