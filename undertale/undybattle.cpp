#include "stdafx.h"
#include "undybattle.h"

HRESULT undybattle::init()
{
	_bui = new battleUI;
	_bui->init();
	ImageManager::GetInstance()->AddFrameImage("und_hair", L"Undyne/Und_battle_hair.png", 4, 1);
	ImageManager::GetInstance()->AddFrameImage("und_head", L"Undyne/Und_battle_head1.png", 1, 1);
	ImageManager::GetInstance()->AddFrameImage("und_torso", L"Undyne/Und_Torso.png", 1, 1);
	ImageManager::GetInstance()->AddFrameImage("und_leftarm", L"Undyne/Und_left_arm.png", 1, 1);
	ImageManager::GetInstance()->AddFrameImage("und_rightarm", L"Undyne/Und_right_arm.png", 1, 1);
	ImageManager::GetInstance()->AddFrameImage("und_belly", L"Undyne/Und_belly.png", 1, 1);
	ImageManager::GetInstance()->AddFrameImage("und_legs", L"Undyne/Und_legs.png", 1, 1);
	ImageManager::GetInstance()->AddFrameImage("battleback", L"Undyne/BATTLE_BACKGROUND.png", 1, 1);

	_torso.x = WINSIZEX/2;
	_torso.y = WINSIZEY/2 - 200;
	_torso.rc = RectMakeCenter(_torso.x, _torso.y, 100, 60);
	_torso.img = ImageManager::GetInstance()->FindImage("und_torso");
	_torso.currentFrameX = _torso.currentFrameY = 0;
	

	_head.x = _torso.x;
	_head.y = _torso.y - 50;
	_head.rc = RectMakeCenter(_head.x, _head.y, 40, 40);
	_head.img = ImageManager::GetInstance()->FindImage("und_head");
	_head.currentFrameX = _head.currentFrameY = 0;

	_hair.x = _head.x - 90;
	_hair.y = _head.y;
	_hair.rc = RectMakeCenter(_hair.x, _hair.y, 30, 20);
	_hair.img = ImageManager::GetInstance()->FindImage("und_hair");
	_hair.currentFrameX = _hair.currentFrameY = 0;

	_leftArm.x = _torso.x - 60;
	_leftArm.y = _torso.y;
	_leftArm.rc = RectMakeCenter(_leftArm.x, _leftArm.y, 20, 30);
	_leftArm.img = ImageManager::GetInstance()->FindImage("und_leftarm");
	_leftArm.currentFrameX = _leftArm.currentFrameY = 0;

	_rightArm.x = _torso.x + 60;
	_rightArm.y = _torso.y;
	_rightArm.rc = RectMakeCenter(_rightArm.x, _rightArm.y, 20, 30);
	_rightArm.img = ImageManager::GetInstance()->FindImage("und_rightarm");
	_rightArm.currentFrameX = _rightArm.currentFrameY = 0;


	_belly.x = _torso.x;
	_belly.y = _torso.y + 40;
	_belly.rc = RectMakeCenter(_belly.x, _belly.y, 40, 20);
	_belly.img = ImageManager::GetInstance()->FindImage("und_belly");
	_belly.currentFrameX = _belly.currentFrameY = 0;


	_legs.x = _belly.x;
	_legs.y = _belly.y + 30;
	_legs.rc = RectMakeCenter(_legs.x, _legs.y, 20, 40);
	_legs.img = ImageManager::GetInstance()->FindImage("und_legs");
	_legs.currentFrameX = _legs.currentFrameY = 0;


	for (int i = 0; i < BACKMAX; i++)
	{
		background[i] = RectMakeCenter(i * 100 + 500, WINSIZEY / 2 - 200, 100, 200);
	}



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

	for (int i = 0; i < BACKMAX; i++)
	{
		D2DRENDER->DrawRectangle
		(
			background[i],
			D2DRenderer::DefaultBrush::Red,
			1.f
		);
	}
	_bui->render();
	_hair.img->FrameRender(_hair.rc.left, _hair.rc.top, _hair.currentFrameX, _hair.currentFrameY, 1.f, 1.f, 0.f, 0.f, 0.f, 0.f, 0.f);




}
