#pragma once
#include "gameNode.h"
#include "bullet.h"

class muffetBattle;

class muffetStateBase : public gameNode
{
protected:
	string _stateName;	

	Image* _imageName;
	int _count;
	int _currentFrameX, _currentFrameY;

	Image* _bulletImageName;
	int _bulletFrameCount;
	int _bulletFrameX, _bulletFrameY;

	bullet* _bullet;
public:
	virtual muffetStateBase* inputHandle(muffetBattle* muffet) = 0;
	virtual void update(muffetBattle* muffet) = 0;
	virtual void enter(muffetBattle* muffet) = 0;
	virtual void exit(muffetBattle* muffet) = 0;

	virtual string getCurrentStateName() { return _stateName; }
	virtual Image* getCurrentStateImg() { return _imageName; }
	virtual int getFramCount() { return _count; }
	virtual int getFrameX() { return _currentFrameX; }
	virtual int getFrameY() { return _currentFrameY; }

	virtual Image* getCurrentStateEffect() { return _bulletImageName; }
	virtual int getEffectFrameX() { return _bulletFrameX; }
	virtual int getEffectFrameY() { return _bulletFrameY; }
};