#include "stdafx.h"
#include "sans_state_idle.h"
#include "sans_state_attack1.h"


sans_state * sans_state_idle::inputHandle(sansBattle * sansBattle)
{
	battleUI* ui = sansBattle->getUI();

	if (ui->getState() == INGAME && ui->getBattle_turn() == 0)
	{
		return new sans_state_attack1();
	}
	return nullptr;
}

void sans_state_idle::enter(sansBattle * sansBattle)
{

}

void sans_state_idle::update(sansBattle * sansBattle)
{

}

void sans_state_idle::render(sansBattle * sansBattle)
{

}

void sans_state_idle::exit(sansBattle * sansBattle)
{
}
