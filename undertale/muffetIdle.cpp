#include "stdafx.h"
#include "muffetIdle.h"
#include "muffetBattle.h"
#include "muffetPurple.h"
#include "muffetPattern1.h"
#include "muffetPattern2.h"
#include "muffetPattern3.h"

muffetStateBase * muffetIdle::inputHandle(muffetBattle * muffet)
{
	battleUI* ui = muffet->getUI();
	if (ui->getState() == INGAME)
	{
		muffet->getUI()->set_inGame_heart_y(muffet->getUI()->get_main_rect().bottom + muffet->getUI()->get_main_rect().top / 2);
		if (ui->getBattle_turn() == 1)
		{
			return new muffetPurple();
		}
		if (ui->getBattle_turn() == 2)
		{
			return new muffetPattern1();
		}
		if (ui->getBattle_turn() == 3)
		{
			return new muffetPattern2();
		}
		if (ui->getBattle_turn() == 4)
		{
			return new muffetPattern3();
		}
	}

	return nullptr;
}

void muffetIdle::update(muffetBattle * muffet)
{
	/*_count++;

	if (_count % 70)
	{
		if (i != 20)
		{
			if (muffet->getMuffetImageV()[0].y <= 52)
			{
				muffet->getMuffetImageV()[i].y++;

			}
			else if (muffet->getMuffetImageV()[0].y >= 50)
			{
				muffet->getMuffetImageV()[i].y--;
			}

		}
		i++;

		if (i >= muffet->getMuffetImageV().size()) i = 0;
		_count = 0;
	}*/
}

void muffetIdle::enter(muffetBattle * muffet)
{
	/*_count = 0;
	i = 0;*/
}

void muffetIdle::render(muffetBattle * muffet)
{
}

void muffetIdle::exit(muffetBattle * muffet)
{
}
