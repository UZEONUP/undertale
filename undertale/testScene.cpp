#include "stdafx.h"
#include "testScene.h"

HRESULT testScene::init()
{
	_asriel = new asriel;
	_asriel->init();

	return S_OK;
}

void testScene::release()
{
}

void testScene::update()
{
	_asriel->update();
}

void testScene::render()
{
	_asriel->render();
}
