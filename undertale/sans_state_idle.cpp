#include "stdafx.h"
#include "sans_state_idle.h"
#include "sans_state_attack1.h"
#include "sans_state_attack2.h"
#include "sans_state_attack3.h"
#include "sans_state_attack4.h"


sans_state * sans_state_idle::inputHandle(sansBattle * sansBattle)
{
	battleUI* ui = sansBattle->getUI();
	if (ui->getState() == INGAME) 
	{
		/*if (ui->getBattle_turn() == 0)
		{
			return new sans_state_attack1();
		}
		if (ui->getBattle_turn() == 1)
		{
			return new sans_state_attack2();
		}
		if (ui->getBattle_turn() == 2)
		{
			return new sans_state_attack3();
		}*/
		if (ui->getBattle_turn() == 0)
		{
			return new sans_state_attack4();
		}
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
