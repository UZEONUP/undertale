#include "stdafx.h"
#include "testscene2.h"

HRESULT testscene2::init()
{
	_player = new player;
	_player->init();
	_enemyRect = RectMakeCenter(WINSIZEX / 2, WINSIZEY / 2, 50, 50);
	return S_OK;
}

void testscene2::release()
{
}

void testscene2::update()
{
	_player->update();

	RECT temp;
	if (IntersectRect(&temp, &_player->getRect(), &_enemyRect))
	{
		
	}
}

void testscene2::render()
{
	
	_player->render();
}
