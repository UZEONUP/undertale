#include "stdafx.h"
#include "title.h"

HRESULT title::init()
{
	ImageManager::GetInstance()->AddImage("title", L"스테이지이미지/title.png");
	_backGround = ImageManager::GetInstance()->FindImage("title");
	//_backGround = ImageManager::GetInstance()->FindImage("시작스테이지");
	CAMERAMANAGER->setMapCamera(640, 480);
	return S_OK;
}

void title::release()
{
}

void title::update()
{
}

void title::render()
{
	_backGround->mapRender(0, 0);

}
