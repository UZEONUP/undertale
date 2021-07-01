#pragma once
#include "gameNode.h"
#include "stageRect.h"
#include "player.h"
#include "progressBar.h"

class startStage : public gameNode
{
	stageRect* _setRect;
	Image* _backGround;
	player* _player;
	progressBar* _bar;
	float hp;
	RECT _sceneRect;

	int _timer;

	Image* bush;


public :
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	stageRect* getStageRect() { return _setRect; }
	RECT getSceneRect() { return _sceneRect; }

	startStage* getScene() { return this; }

	player* getPlayer() { return _player; }

};

