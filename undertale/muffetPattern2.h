#pragma once
#include "muffetStateBase.h"
#include <vector>

class muffetBattle;

struct spiderBullet2
{
	Image* image;
	float x, y;
	RECT rc;
};
class muffetPattern2 : public muffetStateBase
{
	spiderBullet2 _spider;

	vector<spiderBullet2> _vSpiderBullet;

	POINT _startPoint[3];
	POINT _endPoint[3];

	int _fireRndNum;

	bool increase;

public:
	virtual muffetStateBase* inputHandle(muffetBattle* muffet);
	virtual void update(muffetBattle* muffet);
	virtual void enter(muffetBattle* muffet);
	virtual void render(muffetBattle* muffet);
	virtual void exit(muffetBattle* muffet);

	void spiderBulletFire(muffetBattle * muffet);
};

