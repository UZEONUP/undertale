#pragma once
#include "gameNode.h"

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

public:
	playGround();
	~playGround();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
};

