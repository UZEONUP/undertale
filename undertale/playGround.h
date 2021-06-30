#pragma once
#include "gameNode.h"
#include "stageManager.h"
#include "testScene.h"

struct tagFace
{
	Image* img;
	RECT rc;
	int currentFrameX;
	int currentFrameY;
	float x, y;
	int count;
};

class playGround : public gameNode
{
private:
	testScene* _ts;

	stageManager* _sm;

	tagFace _face;

public:
	playGround();
	~playGround();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

};


































































