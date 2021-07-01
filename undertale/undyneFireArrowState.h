#pragma once
#include "undyneState.h"

class undynebattle;

class undyneFireArrowState :public undyneState
{
private:

public:
	virtual undyneState* inputHandle(undynebattle* undynebattle) = 0;
	virtual void update(undynebattle* undynebattle) = 0;
	virtual void enter(undynebattle* undynebattle) = 0;
	virtual void exit(undynebattle* undynebattle) = 0;
};

