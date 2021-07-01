#pragma once
#include "gameNode.h"
#include "bullet.h"

#define BULLETMAX 30
#define RBULLETMAX 10

class undybattle;

enum bulletDirection
{
	LEFT = 0,
	RIGHT,
	UP,
	DOWN
};


class undyneState : gameNode
{
protected:
	string _stateName;

	Image* _img;
	int _frame;
	int _currentFrameX, _currentFrameY;

	Image* _bulletimg;
	int _bulletFrame;
	int _bulletFrameX, _bulletFrameY;

	bullet* _bullet;
public:

	virtual undyneState* inputHandle(undybattle* undybattle) = 0;
	virtual void update(undybattle* undybattle) = 0;
	virtual void enter(undybattle* undybattle) = 0;
	virtual void exit(undybattle* undybattle) = 0;

	virtual string getCurrentStateName() { return _stateName; }
	virtual Image* getCurrentStateImg() { return _img; }
	virtual int getFramCount() { return _frame; }
	virtual int getFrameX() { return _currentFrameX; }
	virtual int getFrameY() { return _currentFrameY; }

	virtual Image* getCurrentStateEffect() { return _bulletimg; }
	virtual int getEffectFrameX() { return _bulletFrameX; }
	virtual int getEffectFrameY() { return _bulletFrameY; }
};

