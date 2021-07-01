#pragma once
#include "gameNode.h"


struct tagUndy
{
	RECT rc;
	Image* img;
	int currentFrameX;
	int currentFrameY;
	float x, y;
	float angle;
};

class undyne :
	public gameNode
{

private:
	int _count;

	tagUndy _fullbody; //��� �Ϲݽ�����������


public:
	 HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	void inPutHandle();


	RECT getRect() { return _fullbody.rc; }
	tagUndy getUndy() { return _fullbody; }
};

