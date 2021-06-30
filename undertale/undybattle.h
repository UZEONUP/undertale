#pragma once
#include "gameNode.h"
#include "battleUI.h"
#include <vector>
#define PI 3.14156f
#define BACKMAX 6

struct tagUndyne
{
	RECT rc;
	Image* img;
	int currentFrameX;
	int currentFrameY;
	float x, y;
	float angle;
	bool isMove;
	bool isAttack;
};
struct background
{
	RECT rc;
	Image* img;
	int currentFrameX;
	int currentFrameY;
	float x, y;
	bool isMove;
};

class undybattle :
	public gameNode
{
private:
	int _count = 0;

	tagUndyne _head;
	tagUndyne _hair;
	tagUndyne _torso;
	tagUndyne _leftArm;
	tagUndyne _rightArm;
	tagUndyne _belly;
	tagUndyne _legs; //여기까진 배틀씬에서..

	background _bg[BACKMAX]; // 뒤에 움직이는 배경

	battleUI* _bui;

	bool up;

	vector<background>			 _vBack;
	vector<background>::iterator _viBack;

public:

	HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();


	vector<background> getVback() { return _vBack; }
	vector<background>::iterator getViback() { return _viBack; }

	void backMove();
	battleUI* getUI() { return _bui; }
};

