#pragma once
#include "undyneState.h"

class undyne;

class undyneFireArrowState :public undyneState
{
private:

public:
	virtual undyneState* inputHandle(undyne* undyne) = 0;
	virtual void update(undyne* undyne) = 0;
	virtual void enter(undyne* undyne) = 0;
	virtual void exit(undyne* undyne) = 0;
};

