#pragma once
#include "gameNode.h"
#include "player.h"


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
	RECT _mfRc;

	Image* _muffet;
	Image* _backGround;
	Image* _muffetFrame;

	int _fCount;
	int _currentFrameX;

	float _x, _y;

	float _angle;

public:
	playGround();
	~playGround();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
};


































































