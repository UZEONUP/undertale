#include "stdafx.h"
#include "title.h"

HRESULT title::init()
{
	IMAGEMANAGER->AddImage("title", L"스테이지이미지/title.png");
	_backGround = IMAGEMANAGER->FindImage("title");
	
	CAMERAMANAGER->setMapCamera(640, 480);

	_player = new player;
	_player->init(WINSIZEX / 2, WINSIZEY / 2);
	SAVELOADMANAGER->linkPlayer(_player);

	return S_OK;
}

void title::release()
{
}

void title::update()
{
	if (keyManager::getSingleton()->isOnceKeyDown('Z'))
	{
		SCENEMANAGER->changeScene("stage1");
	}
	_player->update();
}

void title::render()
{
	_backGround->mapRender(0, 0);
}
