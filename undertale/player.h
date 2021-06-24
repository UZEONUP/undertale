#pragma once
#include "gameNode.h"
enum STATE
{
	LEFT,
	RIGHT,
	UP,
	DOWN,
	LEFT_MOVE,
	RIGHT_MOVE,
	UP_MOVE,
	DOWN_MOVE
};

struct tagPlayer
{
	Image* img;
	RECT rc;
	STATE state;
	
	float x, y;
	float speed;
	float angle;
	
	int currentFrameX;
	int currentFrameY;


};
class player :
	public gameNode
{
private:
	tagPlayer _player;
	int _count;


public:
	HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
};

