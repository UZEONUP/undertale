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
	tagUndyne _legs; //������� ��Ʋ������..

	tagUndyne _fullbody; //��� �Ϲݽ�����������

public:
	 HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();


	RECT getRect() { return _torso.rc; }
};

