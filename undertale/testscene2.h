#pragma once
#include "gameNode.h"
#include "player.h"
#include "undyne.h"

class testscene2 :
	public gameNode
{
private :
	RECT _bg;
	player* _player;
	undyne* _undy;
	

public:

	HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	player* getPlayer() { return _player; }
};

