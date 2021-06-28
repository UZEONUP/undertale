#pragma once
#include "gameNode.h"

struct tagUndyne
{
	RECT rc;
	Image* img;
	int currentFrameX;
	float x, y;
	float angle;
};

class undyne :
	public gameNode
{

private:
	int _count;

	tagUndyne _head;
	tagUndyne _hair;
	tagUndyne _torso;
	tagUndyne _leftArm;
	tagUndyne _rightArm;
	tagUndyne _belly;
	tagUndyne _legs; //여기까진 배틀씬에서..

	tagUndyne _fullbody; //얘는 일반스테이지에서

public:
	 HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();


	RECT getRect() { return _torso.rc; }
};

