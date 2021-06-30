#include "stdafx.h"
#include "heart.h"

HRESULT heart::init(int color) // 0.»¡°­ 1.ÃÊ·Ï 2.ÆÄ¶û 3.º¸¶ó
{

	ImageManager::GetInstance()->AddFrameImage("RED", L"hearts/RED.png", 1, 1);
	ImageManager::GetInstance()->AddFrameImage("RED_DAMAGED", L"hearts/RED_DAMAGED.png", 2, 1);
	ImageManager::GetInstance()->AddFrameImage("RED_RUN", L"hearts/RED_RUN.png", 2, 1);
	ImageManager::GetInstance()->AddFrameImage("BLUE", L"hearts/BLUE.png", 1, 1);
	ImageManager::GetInstance()->AddFrameImage("BLUE_DAMAGED", L"hearts/BLUE_DAMAGED.png", 2, 1);
	ImageManager::GetInstance()->AddFrameImage("BLUE_LEFT", L"hearts/BLUE_LEFT.png", 1, 1);
	ImageManager::GetInstance()->AddFrameImage("BLUE_LEFT_DAMAGED", L"hearts/BLUE_LEFT_DAMAGED.png", 2, 1);
	ImageManager::GetInstance()->AddFrameImage("BLUE_RIGHT", L"hearts/BLUE_RIGHT.png", 1, 1);
	ImageManager::GetInstance()->AddFrameImage("BLUE_RIGHT_DAMAGED", L"hearts/BLUE_RIGHT_DAMAGED.png", 2, 1);
	ImageManager::GetInstance()->AddFrameImage("BLUE_UP", L"hearts/BLUE_UP.png", 1, 1);
	ImageManager::GetInstance()->AddFrameImage("BLUE_UP_DAMAGED", L"hearts/BLUE_UP_DAMAGED.png", 2, 1);
	ImageManager::GetInstance()->AddFrameImage("GREEN", L"hearts/GREEN.png", 1, 1);
	ImageManager::GetInstance()->AddFrameImage("GREEN_DAMAGED", L"hearts/GREEN_DAMAGED.png", 2, 1);
	ImageManager::GetInstance()->AddFrameImage("PURPLE", L"hearts/PURPLE.png", 1, 1);
	ImageManager::GetInstance()->AddFrameImage("PURPLE_DAMAGED", L"hearts/PURPLE_DAMAGED.png", 2, 1);

	_iGH.x = WINSIZEX / 2;
	_iGH.y = WINSIZEY / 2+100;
	_iGH.rc = RectMakeCenter(_iGH.x, _iGH.y, 20, 20);
	_iGH.currentFrameX = _iGH.currentFrameY = 0;
	_iGH.speed = 3.0f;
	color = 0;
	switch (color)
	{
	case 0:
		_iGH.img = ImageManager::GetInstance()->FindImage("RED");
		break;

	case 1:
		_iGH.img = ImageManager::GetInstance()->FindImage("GREEN");
		break;

	case 2:
		_iGH.img = ImageManager::GetInstance()->FindImage("BLUE");
		break;
	case 3:
		_iGH.img = ImageManager::GetInstance()->FindImage("PURPLE");
		break;
	}


	return S_OK;
}

void heart::release()
{
}

void heart::update()
{
	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		_iGH.x -= _iGH.speed;
	}
	
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		_iGH.x += _iGH.speed;
	}
	
	if (KEYMANAGER->isStayKeyDown(VK_UP))
	{
		_iGH.y -= _iGH.speed;
	}
	if (KEYMANAGER->isStayKeyDown(VK_DOWN))
	{
		_iGH.y += _iGH.speed;
	}
	_iGH.rc = RectMakeCenter(_iGH.x, _iGH.y, 20, 20);
}

void heart::render()
{
	D2DRENDER->DrawRectangle
	(
		_iGH.rc,
		D2DRenderer::DefaultBrush::Red,
		1.f
		//angle
	);
	//_iGH.img->FrameRender(_iGH.rc.left, _iGH.rc.top, _iGH.currentFrameX, _iGH.currentFrameY);
}
