#include "stdafx.h"
#include "player.h"

HRESULT player::init()
{
	ImageManager::GetInstance()->AddFrameImage("LEFT_MOVE", L"frisk/left_move.png", 4, 1);
	ImageManager::GetInstance()->AddFrameImage("RIGHT_MOVE", L"frisk/right_move.png", 4, 1);
	ImageManager::GetInstance()->AddFrameImage("UP_MOVE", L"frisk/up_move.png", 4, 1);
	ImageManager::GetInstance()->AddFrameImage("DOWN_MOVE", L"frisk/down_move.png", 4, 1);
	ImageManager::GetInstance()->AddFrameImage("LEFT", L"frisk/left.png",1,1);
	ImageManager::GetInstance()->AddFrameImage("RIGHT", L"frisk/right.png",1,1);
	ImageManager::GetInstance()->AddFrameImage("UP", L"frisk/up.png",1,1);
	ImageManager::GetInstance()->AddFrameImage("DOWN", L"frisk/down.png",1,1);

	_player.x = WINSIZEX / 2;
	_player.y = WINSIZEY / 2;
	_player.speed = 3.0f;
	_player.img = ImageManager::GetInstance()->FindImage("DOWN_MOVE");
	_player.state = DOWN_MOVE;
	_player.rc = RectMakeCenter(_player.x,_player.y, 100, 100);
	_player.currentFrameX = 0;
	_player.currentFrameY = 0;
	_index = 0;

	return S_OK;
}

void player::release()
{
}

void player::update()
{
	_count++;

	switch (_player.state)
	{
	case LEFT_MOVE:
		_player.img = ImageManager::GetInstance()->FindImage("LEFT_MOVE");
		if (_count % 5 == 0)
		{
			_player.currentFrameX++;
			if (_player.currentFrameX >=_player.img->GetMaxFrameX())_player.currentFrameX = 0;
			_player.currentFrameY = 0;
		}
		break;

	case RIGHT_MOVE:
		_player.img = ImageManager::GetInstance()->FindImage("RIGHT_MOVE");
		if (_count % 5 == 0)
		{
			_player.currentFrameX++;
			if (_player.currentFrameX >= _player.img->GetMaxFrameX())_player.currentFrameX = 0;
			_player.currentFrameY = 0;
		}
		break;

	case UP_MOVE:
		_player.img = ImageManager::GetInstance()->FindImage("UP_MOVE");
		if (_count % 5 == 0)
		{
			_player.currentFrameX++;
			if (_player.currentFrameX >= _player.img->GetMaxFrameX())_player.currentFrameX = 0;
			_player.currentFrameY = 0;
		}
		break;

	case DOWN_MOVE:
		_player.img = ImageManager::GetInstance()->FindImage("DOWN_MOVE");
		if (_count % 5 == 0)
		{
			_player.currentFrameX++;
			if (_player.currentFrameX >= _player.img->GetMaxFrameX())_player.currentFrameX = 0;
			_player.currentFrameY = 0;
		}
		break;

	case LEFT:
		_player.img = ImageManager::GetInstance()->FindImage("LEFT");
		_player.currentFrameX = 0;
		break;

	case RIGHT:
		_player.img = ImageManager::GetInstance()->FindImage("RIGHT");
		_player.currentFrameX = 0;
		break;

	case UP:
		_player.img = ImageManager::GetInstance()->FindImage("UP");
		_player.currentFrameX = 0;
		break;

	case DOWN:
		_player.img = ImageManager::GetInstance()->FindImage("DOWN");
		_player.currentFrameX = 0;
		break;
	}

	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		_player.state = LEFT_MOVE;
		//_player.x -= _player.speed;
	}
	if (KEYMANAGER->isOnceKeyUp(VK_LEFT))
	{
		//_player.state = LEFT;
	}

	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		_player.state = RIGHT_MOVE;
		//_player.x += _player.speed;
	}
	if (KEYMANAGER->isOnceKeyUp(VK_RIGHT))
	{
		_player.state = RIGHT;
	}

	if (KEYMANAGER->isStayKeyDown(VK_UP))
	{
		_player.state = UP_MOVE;
		//_player.y -= _player.speed;
	}
	if (KEYMANAGER->isOnceKeyUp(VK_UP))
	{
		_player.state = UP;
	}
	if (KEYMANAGER->isStayKeyDown(VK_DOWN))
	{
		_player.state = DOWN_MOVE;
		//_player.y += _player.speed;
	}
	if (KEYMANAGER->isOnceKeyUp(VK_DOWN))
	{
		_player.state = DOWN;
	}
	_player.rc = RectMakeCenter(_player.x, _player.y, 100,100);
}

void player::render()
{
	
	_player.rc = RectMakeCenter(_player.x,_player.y, 100,100);
	_player.img->FrameRender(_player.rc.left, _player.rc.top,_player.currentFrameX,_player.currentFrameY, 2.f, 2.f, 0.f, 0.f, 0.f, 0.f, 0.f);

	
}
