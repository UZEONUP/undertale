#include "stdafx.h"
#include "player.h"


HRESULT player::init(float x, float y)
{
	ImageManager::GetInstance()->AddFrameImage("LEFT_MOVE", L"frisk/left_move.png", 4, 1);
	ImageManager::GetInstance()->AddFrameImage("RIGHT_MOVE", L"frisk/right_move.png", 4, 1);
	ImageManager::GetInstance()->AddFrameImage("UP_MOVE", L"frisk/up_move.png", 4, 1);
	ImageManager::GetInstance()->AddFrameImage("DOWN_MOVE", L"frisk/down_move.png", 4, 1);
	ImageManager::GetInstance()->AddFrameImage("LEFT", L"frisk/left.png", 1, 1);
	ImageManager::GetInstance()->AddFrameImage("RIGHT", L"frisk/right.png", 1, 1);
	ImageManager::GetInstance()->AddFrameImage("UP", L"frisk/up.png", 1, 1);
	ImageManager::GetInstance()->AddFrameImage("DOWN", L"frisk/down.png", 1, 1);
	ImageManager::GetInstance()->AddFrameImage("RED", L"hearts/RED.png", 1, 1);

	_undy = new undyne;
	_undy->init();


	_player.speed = 3.0f;
	_player.img = ImageManager::GetInstance()->FindImage("DOWN");
	_player.state = DOWN;
	_player.rc = RectMakeCenter(WINSIZEX / 2, WINSIZEY / 2, 40, 60);
	setPlayerX(x);
	setPlayerY(y);
	_player.balpan = RectMake(_player.rc.left, _player.rc.bottom, 40, 5);  // 캐릭터 하단의 발판.
	_player.currentFrameX = 0;
	_player.currentFrameY = 0;
	_player.isBattle = false;
	_heart.img = ImageManager::GetInstance()->FindImage("RED");
	_heart.currentFrameX = 0;

	_blink = 0;
	_index = 0;
	_timer = 0;
	return S_OK;
}

void player::release()
{
}

void player::update()
{
	
	_undy->update();
	

	if (!_player.isBattle)
	{
		_count++;
		if (KEYMANAGER->isStayKeyDown(VK_LEFT))
		{
			_player.state = LEFT_MOVE;
			_player.x -= _player.speed;
		}
		if (KEYMANAGER->isOnceKeyUp(VK_LEFT))
		{
			_player.state = LEFT;
		}

		if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
		{
			_player.state = RIGHT_MOVE;
			_player.x += _player.speed;
		}
		if (KEYMANAGER->isOnceKeyUp(VK_RIGHT))
		{
			_player.state = RIGHT;
		}

		if (KEYMANAGER->isStayKeyDown(VK_UP))
		{
			_player.state = UP_MOVE;
			_player.y -= _player.speed;
		}
		if (KEYMANAGER->isOnceKeyUp(VK_UP))
		{
			_player.state = UP;
		}
		if (KEYMANAGER->isStayKeyDown(VK_DOWN))
		{
			_player.state = DOWN_MOVE;
			_player.y += _player.speed;
		}
		if (KEYMANAGER->isOnceKeyUp(VK_DOWN))
		{
			_player.state = DOWN;
		}
		switch (_player.state)
		{
		case LEFT_MOVE:
			_player.img = ImageManager::GetInstance()->FindImage("LEFT_MOVE");
			if (_count % 5 == 0)
			{
				_player.currentFrameX++;
				if (_player.currentFrameX >= _player.img->GetMaxFrameX())_player.currentFrameX = 0;
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
		_player.rc = RectMakeCenter(_player.x, _player.y, 40, 60);
		_player.balpan = RectMake(_player.rc.left, _player.rc.bottom, 40, 5);
	}

	/*_heart.x = _player.x - 2;
	_heart.y = _player.y + 10;*/

	if (!_imageON)
	{
		_heart.img->SetAlpha(0);
	}
	else
	{
		_heart.img->SetAlpha(1);
	}

	if (_blink >= 3)
	{
		
		_heart.angle = GetAngle(_heart.x, _heart.y, WINSIZEX / 2, WINSIZEY / 2);
		_heart.x -= cosf(_heart.angle) * -_player.speed;
		_heart.y -= -sinf(_heart.angle) * -_player.speed;
		_heart.rc = RectMakeCenter(_heart.x, _heart.y, 20, 20);

		if (_heart.x >=WINSIZEX/2 + 100 || _heart.x <=WINSIZEX/2 - 100)
		{
			_player.changeScene = true;
		}
	}
}

void player::render()
{
	if (!_player.deletepl)
	{
		//
		_player.rc = RectMakeCenter(_player.x, _player.y, 40, 60);
		_player.balpan = RectMake(_player.rc.left, _player.rc.bottom, 40, 5);
		_player.img->FrameRender(_player.rc.left, _player.rc.top, _player.currentFrameX, _player.currentFrameY, 1.f, 1.f, 0.f, 0.f, 0.f, 0.f, 0.f);
	}
	_heart.img->FrameRender(_heart.rc.left, _heart.rc.top, _heart.currentFrameX, _heart.currentFrameY, 1.f, 1.f, 0.f, 0.f, 0.f, 0.f, 0.f);

	D2DRENDER->DrawRectangle
	(
		_player.rc,
		D2DRenderer::DefaultBrush::Red,
		1.f
		//angle
	);
	D2DRENDER->DrawRectangle
	(
		_player.balpan,
		D2DRenderer::DefaultBrush::Red,
		1.f
		//angle
	);

	
}

void player::setHeart(float x, float y)
{
	_heart.rc = RectMakeCenter(_heart.x,_heart.y, 20, 20);
	
	_timer++;
	if (_blink < 3)
	{
		if (_timer % 10 == 0)
		{
			if (!_imageON)
			{
				_imageON = true;
				_timer = 0;
			}
			else
			{
				_blink++;
				_imageON = false;
				_timer = 0;
			}
		}
		_heart.x = _player.x;
		_heart.y = _player.y;
	}
	if(_blink ==3)
	{
		_player.deletepl = true;
		_heart.rc = RectMakeCenter(_heart.x, _heart.y, 20, 20);
		_imageON = true;
	}
}




