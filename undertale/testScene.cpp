#include "stdafx.h"
#include "testScene.h"

HRESULT testScene::init()
{
	_bui = new battleUI;
	_bui->init();
	
	return S_OK;
}

void testScene::release()
{
}

void testScene::update()
{
	if (KEYMANAGER->isOnceKeyDown(VK_F2)) SCENEMANAGER->changeScene("Å×½ºÆ®2");
	_bui->update();
}

void testScene::render()
{
	_bui->render();
}
