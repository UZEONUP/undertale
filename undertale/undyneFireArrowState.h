#pragma once
#include "undyneState.h"
#include "undyneIdle.h"

class undybattle;


class undyneFireArrowState :public undyneState
{
private:
	bulletDirection _bulletDirect;
	undyBullet* _undybullet;
public:
	virtual undyneState* inputHandle(undybattle* undybattle);
	virtual void update(undybattle* undybattle);
	virtual void enter(undybattle* undybattle);
	virtual void render(undybattle* undybattle);
	virtual void exit(undybattle* undybattle);

	void undybulletFire(undybattle* undybattle);
};

