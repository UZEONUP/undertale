#pragma once
#include "gameNode.h"
#include "battleUI.h"
#include <vector>
#define PI 3.14156f
#define BACKMAX 6
struct tagCannon
{
	float x, y;
	float radius;
	float length;
	float gravity;
	float speed;
	float angle;
	bool isFire;
	POINT center;
	POINT cannonEnd;
};
struct tagUndyne
{
	RECT rc;
	RECT janSang;
	Image* img;
	int currentFrameX;
	int currentFrameY;
	float x, y;
	float angle;
	bool isMove;
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
	tagCannon _cannon;
	tagUndyne _head;
	tagUndyne _hair;
	tagUndyne _torso;
	tagUndyne _leftArm;
	tagUndyne _rightArm;
	tagUndyne _belly;
	tagUndyne _legs; //여기까진 배틀씬에서..
	Image* _jansang;
	background _bg[BACKMAX]; // 뒤에 움직이는 배경

	battleUI* _bui;
	int currentFrameX;
	int currentFrameY;


	float angle;
	bool maxangle;
	bool minangle;
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
};

