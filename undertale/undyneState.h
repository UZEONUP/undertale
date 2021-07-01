#pragma once
class undyne;

class undyneState
{
	virtual undyneState* inputHandle(undyne* undyne) = 0;
	virtual void update(undyne* undyne) = 0;
	virtual void enter(undyne* undyne) = 0;
	virtual void exit(undyne* undyne) = 0;
};

