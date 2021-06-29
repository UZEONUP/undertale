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


	_torso.x = WINSIZEX / 2;
	_torso.y = WINSIZEY / 2;
	_torso.rc = RectMakeCenter(_torso.x, _torso.y, 66, 33);
	_torso.img = ImageManager::GetInstance()->FindImage("und_torso");
	_torso.currentFrameX = _torso.currentFrameY = 0;
	_torso.isMove = false;

	_head.x = _torso.x + 100;
	_head.y = _torso.y;
	_head.rc = RectMakeCenter(_head.x, _head.y, 32, 28);
	_head.img = ImageManager::GetInstance()->FindImage("und_head");
	_head.currentFrameX = _head.currentFrameY = 0;
	_head.isMove = false;

	_hair.x = _head.x;
	_hair.y = _head.y;
	_hair.rc = RectMakeCenter(_hair.x, _hair.y, 30, 20);
	_hair.img = ImageManager::GetInstance()->FindImage("und_hair");
	_hair.currentFrameX = _hair.currentFrameY = 0;
	_hair.isMove = false;

	_leftArm.x = _torso.x;
	_leftArm.y = _torso.y;
	_leftArm.rc = RectMakeCenter(_leftArm.x, _leftArm.y, 47, 71);
	_leftArm.img = ImageManager::GetInstance()->FindImage("und_leftarm");
	_leftArm.currentFrameX = _leftArm.currentFrameY = 0;
	_leftArm.isMove = false;

	_rightArm.x = _torso.x;
	_rightArm.y = _torso.y;
	_rightArm.rc = RectMakeCenter(_rightArm.x, _rightArm.y, 15, 37);
	_rightArm.img = ImageManager::GetInstance()->FindImage("und_rightarm");
	_rightArm.currentFrameX = _rightArm.currentFrameY = 0;
	_rightArm.isMove = false;


	_belly.x = _torso.x;
	_belly.y = _torso.y + 70;
	_belly.rc = RectMakeCenter(_belly.x, _belly.y, 37, 24);
	_belly.img = ImageManager::GetInstance()->FindImage("und_belly");
	_belly.currentFrameX = _belly.currentFrameY = 0;
	_belly.isMove = false;

	_legs.x = _belly.x;
	_legs.y = _belly.y + 20;
	_legs.rc = RectMakeCenter(_legs.x, _legs.y, 39, 37);
	_legs.img = ImageManager::GetInstance()->FindImage("und_legs");
	_legs.currentFrameX = _legs.currentFrameY = 0;


	background bg;
	bg.img = ImageManager::GetInstance()->FindImage("battleback");
	bg.currentFrameX = bg.currentFrameY = 0;
	bg.x = (bg.rc.left + bg.rc.right) / 2;
	bg.y = (bg.rc.top + bg.rc.bottom) / 2;
	for (int i = 0; i < BACKMAX; i++)
	{
		bg.rc = RectMakeCenter(i * 100 + 40, WINSIZEY / 2 - (i * 10), 100, 220);
	}
	_vBack.push_back(bg);


	return S_OK;
}

void undybattle::release()
{
}

void undybattle::update()
{
	_bui->update();
	_count++;
	/*if (_count % 5 == 0)
	{
		_hair.currentFrameX++;
		if (_hair.currentFrameX >= _hair.img->GetMaxFrameX())_hair.currentFrameX = 0;
		_hair.currentFrameY = 0;
	}
*/
	if (_head.isMove)
	{
		_head.y -= 0.2;
		if (_head.y < _torso.y - 52) _head.isMove = false;
	}
	else
	{
		_head.y += 0.2;
		if (_head.y > _torso.y - 48)_head.isMove = true;
	}


	if (_torso.isMove)
	{
		_torso.y -= 0.2;
		if (_torso.y < WINSIZEY / 2 - 122)_torso.isMove = false;
	}
	else
	{
		_torso.y += 0.2;
		if (_torso.y > WINSIZEY / 2 - 118)_torso.isMove = true;
	}

	if (_leftArm.isMove)
	{
		_leftArm.y -= 0.2;
		_leftArm.x -= 0.4;
		if (_leftArm.y < _torso.y - 2)_leftArm.isMove = false;
	}
	else
	{
		_leftArm.y += 0.2;
		_leftArm.x += 0.4;
		if (_leftArm.y > _torso.y + 2) _leftArm.isMove = true;
	}

	if (_rightArm.isMove)
	{
		_rightArm.y -= 0.1;
		_rightArm.x += 0.3;
		if (_rightArm.y < _torso.y - 2) _rightArm.isMove = false;
	}
	else
	{
		_rightArm.y += 0.1;
		_rightArm.x -= 0.3;
		if (_rightArm.y > _torso.y + 2) _rightArm.isMove = true;
	}

	if (_belly.isMove)
	{
		_belly.y -= 0.2;
		if (_belly.y < _torso.y + 68)_belly.isMove = false;
	}
	else
	{
		_belly.y += 0.2;
		if (_belly.y > _torso.y + 72)_belly.isMove = true;
	}



	//backMove();


	_hair.rc = RectMakeCenter(_hair.x, _head.y, 10, 10);
	_head.rc = RectMakeCenter(_head.x, _head.y, 32, 28);
	_leftArm.rc = RectMakeCenter(_leftArm.x, _leftArm.y, 47, 71);
	_rightArm.rc = RectMakeCenter(_rightArm.x, _rightArm.y, 15, 37);
	_belly.rc = RectMakeCenter(_belly.x, _belly.y, 37, 24);
	_legs.rc = RectMakeCenter(_legs.x, _legs.y, 39, 37);
	_torso.rc = RectMakeCenter(_torso.x, _torso.y, 66, 33);
}

void undybattle::render()
{
	D2DRENDER->DrawRectangle
	(
		_torso.rc,
		D2DRenderer::DefaultBrush::Red,
		1.f
	);

	D2DRENDER->DrawRectangle
	(
		_head.rc,
		D2DRenderer::DefaultBrush::Red,
		1.f
	);

	D2DRENDER->DrawRectangle
	(
		_hair.rc,
		D2DRenderer::DefaultBrush::Red,
		1.f
	);

	D2DRENDER->DrawRectangle
	(
		_rightArm.rc,
		D2DRenderer::DefaultBrush::Red,
		1.f
	);

	D2DRENDER->DrawRectangle
	(
		_leftArm.rc,
		D2DRenderer::DefaultBrush::Red,
		1.f
	);

	D2DRENDER->DrawRectangle
	(
		_belly.rc,
		D2DRenderer::DefaultBrush::Red,
		1.f
	);

	D2DRENDER->DrawRectangle
	(
		_legs.rc,
		D2DRenderer::DefaultBrush::Red,
		1.f
	);

	for (_viBack = _vBack.begin(); _viBack != _vBack.end();)
	{
		D2DRENDER->DrawRectangle
		(
			_viBack->rc,
			D2DRenderer::DefaultBrush::Red,
			1.f
		);
		_viBack->img->FrameRender(_viBack->rc.left, _viBack->rc.top, _viBack->currentFrameX, _viBack->currentFrameY);
	}


	_leftArm.img->bossFrameRender(_leftArm.rc.left, _leftArm.rc.top, _leftArm.currentFrameX, _leftArm.currentFrameY);
	_rightArm.img->bossFrameRender(_rightArm.rc.left, _rightArm.rc.top, _rightArm.currentFrameX, _rightArm.currentFrameY);
	_legs.img->bossFrameRender(_legs.rc.left, _legs.rc.top, _legs.currentFrameX, _legs.currentFrameY);
	_torso.img->bossFrameRender(_torso.rc.left, _torso.rc.top, _torso.currentFrameX, _torso.currentFrameY);
	_belly.img->bossFrameRender(_belly.rc.left, _belly.rc.top, _belly.currentFrameX, _belly.currentFrameY);
	_hair.img->bossFrameRender(_hair.rc.left, _hair.rc.top, _hair.currentFrameX, _hair.currentFrameY);
	_head.img->bossFrameRender(_head.rc.left, _head.rc.top, _head.currentFrameX, _head.currentFrameY);


	_bui->render();
}

void undybattle::backMove()
{
	for (_viBack = _vBack.begin(); _viBack != _vBack.end(); ++_viBack)
	{
		if (_viBack->y < 0) _viBack->isMove = true;
		else if (_viBack->y > 100) _viBack->isMove = false;

		if (_viBack->isMove)_viBack->y += 2;
		else { _viBack->y -= 2; }

	}
}
