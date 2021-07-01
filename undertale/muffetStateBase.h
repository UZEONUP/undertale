#pragma once
#include "gameNode.h"
#include <vector>

class muffetBattle;

struct tagNet
{
	POINT starLinePoint, endLinePoint;
};
class muffetStateBase : public gameNode
{
protected:

	muffetBattle* _muffet;

	string _stateName;

	Image* _imageName;
	int _count;
	int _currentFrameX, _currentFrameY;

public:
	virtual muffetStateBase* inputHandle(muffetBattle* muffet) = 0;
	virtual void update(muffetBattle* muffet) = 0;
	virtual void enter(muffetBattle* muffet) = 0;
	virtual void exit(muffetBattle* muffet) = 0;
	virtual void render(muffetBattle* muffet) = 0;

	virtual string getCurrentStateName() { return _stateName; }
	virtual Image* getCurrentStateImg() { return _imageName; }
	virtual int getFramCount() { return _count; }
	virtual int getFrameX() { return _currentFrameX; }
	virtual int getFrameY() { return _currentFrameY; }

	void heart_control(muffetBattle* muffet);
	//void drawNet(muffetBattle* muffet);

	void link(muffetBattle* muffet) { _muffet = muffet; }
};