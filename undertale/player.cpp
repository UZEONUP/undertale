#include "stdafx.h"
#include "player.h"
#include "stageManager.h"
#include <vector>
#include <algorithm>

HRESULT player::init()
{
	cout << SCENEMANAGER->getSceneName() << "인잇"<<endl;
	IMAGEMANAGER->AddFrameImage("LEFT_MOVE", L"frisk/left_move.png", 4, 1);
	IMAGEMANAGER->AddFrameImage("RIGHT_MOVE", L"frisk/right_move.png", 4, 1);
	IMAGEMANAGER->AddFrameImage("UP_MOVE", L"frisk/up_move.png", 4, 1);
	IMAGEMANAGER->AddFrameImage("DOWN_MOVE", L"frisk/down_move.png", 4, 1);
	IMAGEMANAGER->AddFrameImage("LEFT", L"frisk/left.png", 1, 1);
	IMAGEMANAGER->AddFrameImage("RIGHT", L"frisk/right.png", 1, 1);
	IMAGEMANAGER->AddFrameImage("UP", L"frisk/up.png", 1, 1);
	IMAGEMANAGER->AddFrameImage("DOWN", L"frisk/down.png", 1, 1);
	IMAGEMANAGER->AddFrameImage("RED", L"hearts/RED.png", 1, 1);


	if (SCENEMANAGER->isCurrentScene("stage2")) //산
	{
		_player.x = WINSIZEX / 2 + 20;
		_player.y = 1100;
	}
	else if (SCENEMANAGER->isCurrentScene("stage3"))//위로 올라감
	{
		_player.x = 100;
		_player.y = 350;
	}
	else if (SCENEMANAGER->isCurrentScene("stage4"))//상점 가기 전
	{
		_player.x = 120;
		_player.y = 100;
	}
	else if (SCENEMANAGER->isCurrentScene("stage6"))//엘베
	{
		_player.x = WINSIZEX / 2;
		_player.y = 700;
	}
	else if (SCENEMANAGER->isCurrentScene("stage7"))//마지막 스테이지
	{
		_player.x = WINSIZEX / 2 + 20;
		_player.y = 1120;
	}
	else
	{
		_player.x = WINSIZEX / 2;
		_player.y = WINSIZEY / 2;
	}

	_player.speed = 3.0f;
	_player.img = IMAGEMANAGER->FindImage("DOWN");
	_player.state = DOWN;
	_player.rc = RectMakeCenter(_player.x, _player.y, 40, 60);
	_player.balpan = RectMake(_player.rc.left, _player.rc.bottom - 10, 40, 10);  // 캐릭터 하단의 발판.
	_player.currentFrameX = 0;
	_player.currentFrameY = 0;
	_player.isBattle = false;
	_player.alpha = 1.0f;
	_heart.img = IMAGEMANAGER->FindImage("RED");
	_heart.currentFrameX = 0;

	
	_vObject.push_back(&_player);

	_blink = 0;
	_index = 0;
	_timer = 0;
	return S_OK;
}
HRESULT player::init(float x, float y)
{
	cout << SCENEMANAGER->getSceneName() << "인잇"<<endl;
	IMAGEMANAGER->AddFrameImage("LEFT_MOVE", L"frisk/left_move.png", 4, 1);
	IMAGEMANAGER->AddFrameImage("RIGHT_MOVE", L"frisk/right_move.png", 4, 1);
	IMAGEMANAGER->AddFrameImage("UP_MOVE", L"frisk/up_move.png", 4, 1);
	IMAGEMANAGER->AddFrameImage("DOWN_MOVE", L"frisk/down_move.png", 4, 1);
	IMAGEMANAGER->AddFrameImage("LEFT", L"frisk/left.png", 1, 1);
	IMAGEMANAGER->AddFrameImage("RIGHT", L"frisk/right.png", 1, 1);
	IMAGEMANAGER->AddFrameImage("UP", L"frisk/up.png", 1, 1);
	IMAGEMANAGER->AddFrameImage("DOWN", L"frisk/down.png", 1, 1);
	IMAGEMANAGER->AddFrameImage("RED", L"hearts/RED.png", 1, 1);

	_player.x = x;
	_player.y = y;

	_player.speed = 3.0f;
	_player.img = IMAGEMANAGER->FindImage("DOWN");
	_player.state = DOWN;
	_player.rc = RectMakeCenter(_player.x, _player.y, 40, 60);
	_player.balpan = RectMake(_player.rc.left, _player.rc.bottom - 10, 40, 10);  // 캐릭터 하단의 발판.
	_player.currentFrameX = 0;
	_player.currentFrameY = 0;
	_player.isBattle = false;
	_player.alpha = 1.0f;
	_heart.img = IMAGEMANAGER->FindImage("RED");
	_heart.currentFrameX = 0;

	_vObject.push_back(&_player);

	if (sceneManager::getSingleton()->isCurrentScene("stage2"))
	{
		ImageManager::GetInstance()->AddFrameImage("undyneEyespark", L"Undyne/Und_eyeSpark.png", 9, 1);
		_undy.x = WINSIZEX / 2;
		_undy.y = 400;
		_undy.rc = RectMakeCenter(_undy.x, _undy.y, 80, 100);
		_undy.img = ImageManager::GetInstance()->FindImage("undyneEyespark");
		_undy.currentFrameX = _undy.currentFrameY = 0;

		_vObject.push_back(&_undy);

	}

	_blink = 0;
	_index = 0;
	_timer = 0;
	return S_OK;
}

void player::release()
{
	_vObject.clear();
}

bool compare(tagPlayer * a, tagPlayer * b)
{
	return a->rc.bottom < b->rc.bottom;
}

void player::update()
{
	for (int i = 0; i < _vObject.size(); i++)
	{
		_vObject[i]->count++;

		sort(_vObject.begin(), _vObject.end(), compare);

		if (_vObject[i]->count % 10 == 0)
		{
			_vObject[i]->currentFrameX++;
			if (_vObject[i]->currentFrameX >= _vObject[i]->img->GetMaxFrameX()) _vObject[i]->currentFrameX = 0;
			_vObject[i]->currentFrameY = 0;

			_vObject[i]->count = 0;
		}
		_vObject[i]->rc = RectMakeCenter(_vObject[i]->x, _vObject[i]->y, 100, 100);
	}

	if (!_player.isBattle)
	{
		//_player.count++;
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
			if (_player.count % 5 == 0)
			{
				_player.currentFrameX++;
				if (_player.currentFrameX >= _player.img->GetMaxFrameX())_player.currentFrameX = 0;
				_player.currentFrameY = 0;
			}
			break;

		case RIGHT_MOVE:
			_player.img = ImageManager::GetInstance()->FindImage("RIGHT_MOVE");
			if (_player.count % 5 == 0)
			{
				_player.currentFrameX++;
				if (_player.currentFrameX >= _player.img->GetMaxFrameX())_player.currentFrameX = 0;
				_player.currentFrameY = 0;
			}
			break;

		case UP_MOVE:
			_player.img = ImageManager::GetInstance()->FindImage("UP_MOVE");
			if (_player.count % 5 == 0)
			{
				_player.currentFrameX++;
				if (_player.currentFrameX >= _player.img->GetMaxFrameX())_player.currentFrameX = 0;
				_player.currentFrameY = 0;
			}
			break;

		case DOWN_MOVE:
			_player.img = ImageManager::GetInstance()->FindImage("DOWN_MOVE");
			if (_player.count % 5 == 0)
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
		_player.balpan = RectMake(_player.rc.left, _player.rc.bottom - 10, 40, 10);
	}


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
		if (_heart.x >= WINSIZEX / 2 + 100 || _heart.x <= WINSIZEX / 2 - 100)
		{
			_player.changeScene = true;
		}
	}
	CAMERAMANAGER->updateCamera(_player.x, _player.y);
}

void player::render()
{
	for (int i = 0; i < _vObject.size(); i++)
	{
		_vObject[i]->img->FrameRender(_vObject[i]->rc.left, _vObject[i]->rc.top, _vObject[i]->currentFrameX, _vObject[i]->currentFrameY,_vObject[i]->alpha);
	}
		_heart.img->FrameRender(_heart.rc.left, _heart.rc.top, _heart.currentFrameX, _heart.currentFrameY);
	//if (!_player.deletepl)
	//{
	//	//
	//	_player.rc = RectMakeCenter(_player.x, _player.y, 40, 60);
	//	_player.balpan = RectMake(_player.rc.left, _player.rc.bottom-10, 40, 10);
	//	_player.img->FrameRender(_player.rc.left, _player.rc.top, _player.currentFrameX, _player.currentFrameY);
	//}
	

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
	_heart.rc = RectMakeCenter(_heart.x, _heart.y, 20, 20);

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
	if (_blink == 3)
	{
		_player.deletepl = true;
		_heart.rc = RectMakeCenter(_heart.x, _heart.y, 20, 20);
		_imageON = true;
	}
}




