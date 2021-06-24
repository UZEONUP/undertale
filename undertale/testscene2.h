#pragma once
#include "gameNode.h"
#include "player.h"

class testscene2 :
	public gameNode
{
private :
	player* _player;
	
	

public:

	HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
};

