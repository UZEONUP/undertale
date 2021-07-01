#pragma once
#include "muffetStateBase.h"

class muffetBattle;

class muffetPattern1 : public muffetStateBase
{

public :
	virtual muffetStateBase* inputHandle(muffetBattle* muffet);
	virtual void update(muffetBattle* muffet);
	virtual void enter(muffetBattle* muffet);
	virtual void exit(muffetBattle* muffet);
};

