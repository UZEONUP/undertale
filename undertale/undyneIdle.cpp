#include "stdafx.h"
#include "undyneIdle.h"
#include "undyneFireArrowState.h"

undyneState * undyneIdle::inputHandle(undybattle * undybattle)
{
	battleUI* _bui = undybattle->getUI();
	if (_bui->getState() == INGAME)
	{
		if (_bui->getBattle_turn() == 0)
		{
			return new undyneFireArrowState();
		}
	}
	return nullptr;
}

void undyneIdle::enter(undybattle * undybattle)
{
}

void undyneIdle::update(undybattle * undybattle)
{
}

void undyneIdle::render(undybattle * undybattle)
{
}

void undyneIdle::exit(undybattle * undybattle)
{
}
