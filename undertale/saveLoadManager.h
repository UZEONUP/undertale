#pragma once
#include "singletonBase.h"

class player;

class saveLoadManager :  public singletonBase<saveLoadManager>
{
private:
	player* _player;

public:
	saveLoadManager();
	~saveLoadManager();

	HRESULT init();
	void release();
	void update();
	void render();

	void save();
	void load();

	void sceneSet();

	void linkPlayer(player* player) { _player = player; }
};

