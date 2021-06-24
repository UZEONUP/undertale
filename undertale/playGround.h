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


	Image* _backGround;

	player* _player;
	

	RECT _backRc;
	

public:
	playGround();
	~playGround();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
};


































































