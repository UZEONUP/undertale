#include "stdafx.h"
#include "undyneFireArrowState.h"

undyneState* undyneFireArrowState::inputHandle(undybattle* undybattle)
{
	IMAGEMANAGER->AddImage("LEFTBULLET_OFF", L"Undyne/LEFT_ARROW_OFF");
	IMAGEMANAGER->AddImage("RIGHTBULLET_OFF", L"Undyne/RIGHT_ARROW_OFF");
	IMAGEMANAGER->AddImage("DOWNBULLET_OFF", L"Undyne/DOWN_ARROW_OFF");
	IMAGEMANAGER->AddImage("UPBULLET_OFF", L"Undyne/UP_ARROW_OFF");
	IMAGEMANAGER->AddImage("LEFTBULLET_ON", L"Undyne/LEFT_ARROW_ON");
	IMAGEMANAGER->AddImage("RIGHTBULLET_ON", L"Undyne/RIGHT_ARROW_ON");
	IMAGEMANAGER->AddImage("DOWNBULLET_ON", L"Undyne/DOWN_ARROW_ON");
	IMAGEMANAGER->AddImage("UPBULLET_ON", L"Undyne/UP_ARROW_ON");
	IMAGEMANAGER->AddImage("LEFTBULLET_FAKE", L"Undyne/LEFT_ARROW_FAKE");
	IMAGEMANAGER->AddImage("RIGHTBULLET_FAKE", L"Undyne/RIGHT_ARROW_FAKE");
	IMAGEMANAGER->AddImage("DOWNBULLET_FAKE", L"Undyne/DOWN_ARROW_FAKE");
	IMAGEMANAGER->AddImage("UPBULLET_FAKE", L"Undyne/UP_ARROW_FAKE");
	if (undybattle->getUI()->getState() != INGAME)
	{
		return new undyneIdle();
	}
	return nullptr;

	_bullet->init(30, 600);
}

void undyneFireArrowState::update(undybattle * undybattle)
{
	undybattle->getUI()->setEnemy_attackTime_max(300);
	if (_bulletDirect == 0)
	{
		_bullet->fire("LEFTBULLET_OFF", 0, (undybattle->getUI()->get_main_rect().bottom + undybattle->getUI()->get_main_rect().top) / 2);
	}
	else if (_bulletDirect == 1)
	{
		_bullet->fire("RIGHTBULLET_OFF", WINSIZEX, (undybattle->getUI()->get_main_rect().bottom + undybattle->getUI()->get_main_rect().top) / 2);
	}
	else if (_bulletDirect == 2)
	{
		_bullet->fire("UPBULLET_OFF", (undybattle->getUI()->get_main_rect().left + undybattle->getUI()->get_main_rect().right) / 2, 0);
	}
	else if (_bulletDirect == 3)
	{
		_bullet->fire("UPBULLET_OFF", (undybattle->getUI()->get_main_rect().left + undybattle->getUI()->get_main_rect().right) / 2, 0);
	}
	
}

void undyneFireArrowState::enter(undybattle * undybattle)
{
}

void undyneFireArrowState::render(undybattle * undybattle)
{
}

void undyneFireArrowState::exit(undybattle * undybattle)
{
}
