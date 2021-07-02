#pragma once
#include "gameNode.h"


#define BULLETMAX 30
#define RBULLETMAX 10

class undybattle;

enum bulletDirection
{
	LEFTFIRE = 0,
	RIGHTFIRE=1,
	UPFIRE=2,
	DOWNFIRE=3
};

struct undyBullet
{
	Image* image;
	float x, y;
	RECT rc;
	bool direction;
	float angle;
	float speed;
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
	bulletDirection _bulletDirect;
	undybattle* _undybattle;
	int _directionSelect;
	int _timer;

	vector<undyBullet> _vBullet;
public:

	void linkundynebattle(undybattle* undybattle) { _undybattle = undybattle; }

	virtual undyneState* inputHandle(undybattle* undybattle) = 0;
	virtual void update(undybattle* undybattle) = 0;
	virtual void enter(undybattle* undybattle) = 0;
	virtual void render(undybattle* undybattle) = 0;
	virtual void exit(undybattle* undybattle) = 0;

	virtual string getCurrentStateName() { return _stateName; }
	virtual Image* getCurrentStateImg() { return _img; }
	virtual int getFramCount() { return _frame; }
	virtual int getFrameX() { return _currentFrameX; }
	virtual int getFrameY() { return _currentFrameY; }

	virtual Image* getCurrentStateEffect() { return _bulletimg; }
	virtual int getEffectFrameX() { return _bulletFrameX; }
	virtual int getEffectFrameY() { return _bulletFrameY; }

	vector<undyBullet> getVbullet() { return _vBullet; }
	RECT getBulletRect(int index) { return _vBullet[index].rc; }
};

