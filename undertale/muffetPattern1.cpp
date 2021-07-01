#include "stdafx.h"
#include "muffetPattern1.h"
#include "muffetBattle.h"
#include "muffetIdle.h"

muffetStateBase * muffetPattern1::inputHandle(muffetBattle * muffet)
{
	if (muffet->getUI()->getState() != INGAME)
	{
		return new muffetIdle();
	}
	return nullptr;
}

void muffetPattern1::update(muffetBattle * muffet)
{
	_fireRndNum = RND->getFromIntTo(0, 100);
	if (_fireRndNum >= 95) spiderBulletFire(muffet);

	if (_vSpiderBullet.size() != 0)
	{
		for (int i = 0; i < _vSpiderBullet.size(); i++)
		{
			_vSpiderBullet[i].x -= 5;
			_vSpiderBullet[i].rc = RectMake(_vSpiderBullet[i].x, _vSpiderBullet[i].y, _vSpiderBullet[i].image->GetWidth(), _vSpiderBullet[i].image->GetHeight());
		}
	}
	for (int i = 0; i < 3; i++)
	{
		_startPoint[i].x = muffet->getUI()->get_main_rect().left + 10;
		_startPoint[i].y = ((muffet->getUI()->get_main_rect().bottom - muffet->getUI()->get_main_rect().top) / 4 + muffet->getUI()->get_main_rect().top) + 40 * i;

		_endPoint[i].x = muffet->getUI()->get_main_rect().right - 10;
		_endPoint[i].y = _startPoint[i].y;
	}
}

void muffetPattern1::enter(muffetBattle * muffet)
{

	_fireRndNum = 0;
	muffet->getUI()->setEnemy_attackTime_max(500);
	for (int i = 0; i < 3; i++)
	{
		_startPoint[i].x = muffet->getUI()->get_main_rect().left + 10;
		_startPoint[i].y = ((muffet->getUI()->get_main_rect().bottom - muffet->getUI()->get_main_rect().top) / 4 + muffet->getUI()->get_main_rect().top) + 40 * i;

		_endPoint[i].x = muffet->getUI()->get_main_rect().right - 10;
		_endPoint[i].y = _startPoint[i].y;
	}

	increase = false;

	muffet->getUI()->set_inGame_heart_y(_startPoint[2].y);
	muffet->getUI()->setEnemy_attackTime_max(500);
}

void muffetPattern1::render(muffetBattle * muffet)
{
	muffet->getUI()->main_rect_control_customizing(true, 5, 250, 150);

	if (_vSpiderBullet.size() != 0)
	{
		for (int i = 0; i < _vSpiderBullet.size(); i++)
		{
			if (_vSpiderBullet[i].x >= 135)
			{
				_vSpiderBullet[i].image->Render(_vSpiderBullet[i].x, _vSpiderBullet[i].y);
				if (KEYMANAGER->isToggleKey(VK_F1))
				{
					D2DRENDER->DrawRectangle(_vSpiderBullet[i].rc, D2DRenderer::DefaultBrush::Red);
				}
			}
		}
	}

	for (int i = 0; i < 3; i++)
	{
		D2DRENDER->DrawLine(_startPoint[i], _endPoint[i], D2DRenderer::DefaultBrush::Purple);
	}

}

void muffetPattern1::exit(muffetBattle * muffet)
{
}

void muffetPattern1::spiderBulletFire(muffetBattle * muffet)
{
	spiderBullet _spider;
	_spider.image = IMAGEMANAGER->FindImage("muffet_spider");
	_spider.x = 535;
	_spider.y = muffet->getUI()->getIGH().rc.top;
	_spider.rc = RectMake(_spider.x, _spider.y, _spider.image->GetWidth(), _spider.image->GetHeight());

	_vSpiderBullet.push_back(_spider);
}
