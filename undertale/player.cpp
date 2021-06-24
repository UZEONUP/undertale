#include "stdafx.h"
#include "player.h"

HRESULT player::init()
{
	ImageManager::GetInstance()->AddFrameImage("LEFT_MOVE", L"frisk/left.bmp", 2, 1);
	_player.x = WINSIZEX / 2;
	_player.y = WINSIZEY / 2;
	_player.speed = 3.0f;
	_player.img = ImageManager::GetInstance()->FindImage("LEFT_MOVE");
	_player.state = LEFT;
	_player.rc = RectMakeCenter(_player.x,_player.y, 100, 100);
	_player.currentFrameX = 0;
	_player.currentFrameY = 0;

	return S_OK;
}

void player::release()
{
}

void player::update()
{
	if (_player.state == LEFT_MOVE)
	{
		_player.img = ImageManager::GetInstance()->FindImage("LEFT_MOVE");
	}

	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		_player.state = LEFT_MOVE;
		_player.x -= 5;
	}
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		_player.state = RIGHT_MOVE;
	}
	if (KEYMANAGER->isStayKeyDown(VK_UP))
	{
		_player.state = UP_MOVE;
	}
	if (KEYMANAGER->isStayKeyDown(VK_DOWN))
	{
		_player.state = DOWN_MOVE;
	}

	_count++;
	if (_count % 5 == 0)
	{
		_player.currentFrameX++;
		if (_player.currentFrameX > 1)_player.currentFrameX = 0;
		_player.currentFrameY = 0;
	}


	_player.rc = RectMakeCenter(_player.x, _player.y, 100,100);
}

void player::render()
{
	
		_player.rc = RectMakeCenter(_player.x,_player.y, 100,100);
		_player.img->FrameRender(Vector2(_player.rc.left, _player.rc.top), _player.currentFrameX,_player.currentFrameY);
		

		D2DRENDER->DrawRectangle(_player.rc, D2DRenderer::DefaultBrush::Red, 1.f);
	
}
