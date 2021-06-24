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
	
	int currentHP;
	
	
	float x, y;
	float speed;
	float angle;
	
	int currentFrameX;
	int currentFrameY;

	bool isBattle;

};
class player :
	public gameNode
{
private:
	tagPlayer _player;
	tagPlayer _heart;

	int _count;
	int _index;

	RECT _enemy;
	
public:
	HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();


	RECT getRect() { return _player.rc; }
	tagPlayer getHeart() {return _heart;}
	//void setHeart(Image* heart) { _heart.img = heart; }
	




};

