#pragma once
#include "gameNode.h"
#include "battleUI.h"


#define BACKMAX 6
struct tagUndyne
{
	RECT rc;
	Image* img;
	int currentFrameX;
	int currentFrameY;
	float x, y;
	float angle;
};

class undybattle :
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

	RECT background[BACKMAX]; // �ڿ� �����̴� ���

	battleUI* _bui;

public:

	HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

};

