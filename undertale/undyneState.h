#pragma once
class undynebattle;

class undyneState
{
private:
	undynebattle* _undybattle;



public:

	virtual undyneState* inputHandle(undynebattle* undynebattle) = 0;
	virtual void update(undynebattle* undynebattle) = 0;
	virtual void enter(undynebattle* undynebattle) = 0;
	virtual void exit(undynebattle* undynebattle) = 0;
};

