#pragma once
#include "gameNode.h"
#include "player.h"

class title : public gameNode
{
	Image* _backGround;
	player* _player;

public :
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	title* getScene() { return this; }
	player* getPlayer() { return _player; }
};

