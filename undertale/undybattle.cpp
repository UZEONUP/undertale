#include "stdafx.h"
#include "undybattle.h"

HRESULT undybattle::init()
{
	_bui = new battleUI;
	_bui->init(0);
	ImageManager::GetInstance()->AddFrameImage("und_hair", L"Undyne/Und_battle_hair.png", 4, 1);
	ImageManager::GetInstance()->AddFrameImage("und_head", L"Undyne/Und_battle_head1.png", 1, 1);
	ImageManager::GetInstance()->AddFrameImage("und_torso", L"Undyne/Und_Torso.png", 1, 1);
	ImageManager::GetInstance()->AddFrameImage("und_leftarm", L"Undyne/Und_left_arm.png", 1, 1);
	ImageManager::GetInstance()->AddFrameImage("und_rightarm", L"Undyne/Und_right_arm.png", 1, 1);
	ImageManager::GetInstance()->AddFrameImage("und_belly", L"Undyne/Und_belly.png", 1, 1);
	ImageManager::GetInstance()->AddFrameImage("und_legs", L"Undyne/Und_legs.png", 1, 1);
	ImageManager::GetInstance()->AddFrameImage("battleback", L"Undyne/BATTLE_BACKGROUND.png", 1, 1);
	ImageManager::GetInstance()->AddFrameImage("janSang", L"Undyne/Und_battle_slasheffect.png", 6, 1);
	currentFrameX = currentFrameY = 0;
	_torso.x = WINSIZEX/2;
	_torso.y = WINSIZEY/2 -150;
	_torso.rc = RectMakeCenter(_torso.x, _torso.y, 66, 33);
	_torso.img = ImageManager::GetInstance()->FindImage("und_torso");
	_torso.currentFrameX = _torso.currentFrameY = 0;
	

	_head.x = _torso.x-2.5;
	_head.y = _torso.y -30;
	_head.rc = RectMakeCenter(_head.x, _head.y, 32, 28);
	_head.img = ImageManager::GetInstance()->FindImage("und_head");
	_head.currentFrameX = _head.currentFrameY = 0;

	_hair.x = _head.x -50;
	_hair.y = _head.y;
	_hair.rc = RectMakeCenter(_hair.x, _hair.y, 30, 20);
	_hair.img = ImageManager::GetInstance()->FindImage("und_hair");
	_hair.currentFrameX = _hair.currentFrameY = 0;

	_leftArm.x = _torso.x-30;
	_leftArm.y = _torso.y+30;
	_leftArm.rc = RectMakeCenter(_leftArm.x, _leftArm.y, 47, 71);
	_leftArm.img = ImageManager::GetInstance()->FindImage("und_leftarm");
	_leftArm.currentFrameX = _leftArm.currentFrameY = 0;
	_leftArm.isAttack = true;

	_rightArm.x = _torso.x + 20;
	_rightArm.y = _torso.y +10;
	_rightArm.rc = RectMakeCenter(_rightArm.x, _rightArm.y, 15, 37);
	_rightArm.img = ImageManager::GetInstance()->FindImage("und_rightarm");
	_rightArm.currentFrameX = _rightArm.currentFrameY = 0;


	_belly.x = _torso.x-3;
	_belly.y = _torso.y+20;
	_belly.rc = RectMakeCenter(_belly.x, _belly.y, 37, 24);
	_belly.img = ImageManager::GetInstance()->FindImage("und_belly");
	_belly.currentFrameX = _belly.currentFrameY = 0;


	_legs.x = _belly.x+1;
	_legs.y = _belly.y+25;
	_legs.rc = RectMakeCenter(_legs.x, _legs.y, 39, 37);
	_legs.img = ImageManager::GetInstance()->FindImage("und_legs");
	_legs.currentFrameX = _legs.currentFrameY = 0;

	_leftArm.janSang = RectMakeCenter(((_bui->get_main_rect().left + _bui->get_main_rect().right) / 2), ((_bui->get_main_rect().bottom + _bui->get_main_rect().top) / 2)-10,380,169);
	_jansang = ImageManager::GetInstance()->FindImage("janSang");
	

	_hair.rc = RectMakeCenter(_hair.x, _head.y, 10, 10);
	_head.rc = RectMakeCenter(_head.x, _head.y, 32, 28);
	_leftArm.rc = RectMakeCenter(_leftArm.x, _leftArm.y, 47, 71);
	_rightArm.rc = RectMakeCenter(_rightArm.x, _rightArm.y, 15, 37);
	_belly.rc = RectMakeCenter(_belly.x, _belly.y, 37, 24);
	_legs.rc = RectMakeCenter(_legs.x, _legs.y, 39, 37);
	_torso.rc = RectMakeCenter(_torso.x, _torso.y, 66, 33);

	return S_OK;
}

void undybattle::release()
{
}

void undybattle::update()
{
	_bui->update();
	_count++;
	if (_count % 5 == 0)
	{
		_hair.currentFrameX++;
		if (_hair.currentFrameX >= _hair.img->GetMaxFrameX())_hair.currentFrameX = 0;
		_hair.currentFrameY = 0;
	}
	if (!_leftArm.isAttack)
	{
		if (_head.isMove)
		{
			_head.y -= 0.2;
			if (_head.y < _torso.y - 32) _head.isMove = false;
		}
		else
		{
			_head.y += 0.2;
			if (_head.y > _torso.y - 29)_head.isMove = true;
		}


		if (_torso.isMove)
		{
			_torso.y -= 0.2;
			if (_torso.y < WINSIZEY / 2 - 154)_torso.isMove = false;
		}
		else
		{
			_torso.y += 0.2;
			if (_torso.y > WINSIZEY / 2 - 148)_torso.isMove = true;
		}

		if (_leftArm.isMove)
		{
			_leftArm.y -= 0.2;
			_leftArm.x -= 0.2;
			if (_leftArm.y < _torso.y + 29)_leftArm.isMove = false;
		}
		else
		{
			_leftArm.y += 0.2;
			_leftArm.x += 0.2;
			if (_leftArm.y > _torso.y + 31) _leftArm.isMove = true;
		}

		if (_rightArm.isMove)
		{
			_rightArm.y -= 0.2;
			_rightArm.x -= 0.1;
			if (_rightArm.y < _torso.y + 12) _rightArm.isMove = false;
		}
		else
		{
			_rightArm.y += 0.2;
			_rightArm.x += 0.1;
			if (_rightArm.y > _torso.y + 10) _rightArm.isMove = true;
		}

		if (_belly.isMove)
		{
			_belly.y -= 0.2;
			if (_belly.y < _torso.y + 23)_belly.isMove = false;
		}
		else
		{
			_belly.y += 0.2;
			if (_belly.y > _torso.y + 27)_belly.isMove = true;
		}
	}
	if (_leftArm.isAttack&& angle<80.f)
	{
		angle += 5;
		if (angle == 80.f)maxangle = true;
	}

	if (maxangle)
	{
		angle -= 20;
		if (angle <= -50.f);
	}
	_hair.rc = RectMakeCenter(_hair.x, _head.y-10, 10, 10);
	_head.rc = RectMakeCenter(_head.x, _head.y, 32, 28);
	_leftArm.rc = RectMakeCenter(_leftArm.x, _leftArm.y, 47, 71);
	_rightArm.rc = RectMakeCenter(_rightArm.x, _rightArm.y, 15, 37);
	_belly.rc = RectMakeCenter(_belly.x, _belly.y, 37, 24);
	_legs.rc = RectMakeCenter(_legs.x, _legs.y, 39, 37);
	_torso.rc = RectMakeCenter(_torso.x, _torso.y, 66, 33);
}

void undybattle::render()
{
	if (_leftArm.isAttack)
	{
		_jansang->autoFrameRender(_leftArm.janSang.left, _leftArm.janSang.top, currentFrameX, currentFrameY);
		_leftArm.img->bossFrameRender(_leftArm.rc.left, _leftArm.rc.top, _leftArm.currentFrameX, _leftArm.currentFrameY, 1.f, 1.f, angle, 35.f, 0.f, 0.f, 0.f);
	}

	_rightArm.img->bossFrameRender(_rightArm.rc.left, _rightArm.rc.top, _rightArm.currentFrameX, _rightArm.currentFrameY);
	_legs.img->bossFrameRender(_legs.rc.left, _legs.rc.top, _legs.currentFrameX, _legs.currentFrameY);
	_belly.img->bossFrameRender(_belly.rc.left, _belly.rc.top, _belly.currentFrameX, _belly.currentFrameY);
	_leftArm.img->bossFrameRender(_leftArm.rc.left, _leftArm.rc.top, _leftArm.currentFrameX, _leftArm.currentFrameY);
	_hair.img->bossFrameRender(_hair.rc.left, _hair.rc.top, _hair.currentFrameX, _hair.currentFrameY);
	_torso.img->bossFrameRender(_torso.rc.left, _torso.rc.top, _torso.currentFrameX, _torso.currentFrameY);
	_head.img->bossFrameRender(_head.rc.left, _head.rc.top, _head.currentFrameX, _head.currentFrameY);
	_bui->render();

	D2DRENDER->DrawRectangle
	(
		_leftArm.janSang,
		D2DRenderer::DefaultBrush::Red,
		1.f
		//angle
	);
	D2DRENDER->DrawRectangle
	(
		_leftArm.rc,
		D2DRenderer::DefaultBrush::Red,
		1.f
		//angle
	);
}
