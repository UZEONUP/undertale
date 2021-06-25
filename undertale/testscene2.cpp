#include "stdafx.h"
#include "testscene2.h"

HRESULT testscene2::init()
{
	_player = new player;
	_player->init();
	
	_undy = new undyne;
	_undy->init();

	_bg = RectMakeCenter(WINSIZEX / 2, WINSIZEY / 2, WINSIZEX, WINSIZEY);

	return S_OK;
}

void testscene2::release()
{
}

void testscene2::update()
{
	RECT temp;
	if (IntersectRect(&temp, &_player->getRect(), &_undy->getRect()))
		_player->setBattlechk(true);

	if (_player->getBattlechk())
	{
		_player->setHeart(_player->getX(), _player->getY());
	}


	_player->update();
	_undy->update();
}

void testscene2::render()
{
	if(_player->getBattlechk())D2DRENDER->FillRectangle(_bg,D2DRenderer::DefaultBrush::Black);
	_player->render();
	_undy->render();
}
