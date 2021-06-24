#include "stdafx.h"
#include "testscene2.h"

HRESULT testscene2::init()
{
	_player = new player;
	_player->init();
	
	
	return S_OK;
}

void testscene2::release()
{
}

void testscene2::update()
{
	_player->update();

	
}

void testscene2::render()
{
	
	_player->render();
	
}
