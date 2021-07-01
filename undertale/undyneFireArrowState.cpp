#include "stdafx.h"
#include "undyneFireArrowState.h"

undyneState* undyneFireArrowState::inputHandle(undybattle* undybattle)
{
	

	if (undybattle->getUI()->getState() != INGAME)
	{
		return new undyneIdle();
	}
	return nullptr;

}

void undyneFireArrowState::update(undybattle* undybattle)
{
	undybattle->getUI()->setEnemy_attackTime_max(300);

	_timer++;

	if (_timer % 5 == 0)
	{
		_directionSelect = RND->getFromIntTo(0, 3);
		switch (_directionSelect)
		{
		case 0:
			_bulletDirect = LEFTFIRE;
			break;
		case 1:
			_bulletDirect = RIGHTFIRE;
			break;
		case 2:
			_bulletDirect = UPFIRE;
			break;
		case 3:
			_bulletDirect = DOWNFIRE;
			break;
		}
		switch (_bulletDirect)
		{
		case LEFTFIRE:
			BULLETMANAGER->fire(0, (undybattle->getUI()->get_main_rect().bottom + undybattle->getUI()->get_main_rect().top) / 2, 0);
			break;
		case RIGHTFIRE:
			BULLETMANAGER->fire(WINSIZEX, (undybattle->getUI()->get_main_rect().bottom + undybattle->getUI()->get_main_rect().top) / 2, PI);
			break;
		case UPFIRE:
			BULLETMANAGER->fire((undybattle->getUI()->get_main_rect().left + undybattle->getUI()->get_main_rect().right) / 2, 0, PI*1.5);
			break;
		case DOWNFIRE:
			BULLETMANAGER->fire((undybattle->getUI()->get_main_rect().left + undybattle->getUI()->get_main_rect().right) / 2, WINSIZEY, PI / 2);
			break;
		}
	}

	BULLETMANAGER->move();
}

void undyneFireArrowState::enter(undybattle * undybattle)
{
	IMAGEMANAGER->AddImage("LEFTBULLET_OFF", L"Undyne/LEFT_ARROW_OFF.png");
	IMAGEMANAGER->AddImage("RIGHTBULLET_OFF", L"Undyne/RIGHT_ARROW_OFF.png");
	IMAGEMANAGER->AddImage("DOWNBULLET_OFF", L"Undyne/DOWN_ARROW_OFF.png");
	IMAGEMANAGER->AddImage("UPBULLET_OFF", L"Undyne/UP_ARROW_OFF.png");

	BULLETMANAGER->init("LEFTBULLET_OFF", 10, 600);

	switch (_bulletDirect)
	{
	case LEFTFIRE:
		BULLETMANAGER->init("LEFTBULLET_OFF", 10, 600);
		break;
	case RIGHTFIRE:
		BULLETMANAGER->init("RIGHTBULLET_OFF", 10, 600);
		break;
	case UPFIRE:
		BULLETMANAGER->init("UPBULLET_OFF", 10, 600);
		break;
	case DOWNFIRE:
		BULLETMANAGER->init("DOWNBULLET_OFF", 10, 600);
		break;
	
	}
}

void undyneFireArrowState::render(undybattle * undybattle)
{
	BULLETMANAGER->render();
}

void undyneFireArrowState::exit(undybattle * undybattle)
{

}
