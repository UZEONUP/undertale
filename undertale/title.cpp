#include "stdafx.h"
#include "title.h"

HRESULT title::init()
{
	ImageManager::GetInstance()->AddImage("title", L"���������̹���/title.png");
	_backGround = ImageManager::GetInstance()->FindImage("title");
	//_backGround = ImageManager::GetInstance()->FindImage("���۽�������");
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
