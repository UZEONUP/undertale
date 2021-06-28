#include "stdafx.h"
#include "undybattle.h"

HRESULT undybattle::init()
{
	_bui = new battleUI;
	_bui->init();

	_torso.x = WINSIZEX/2;
	_torso.y = WINSIZEY/2;
	_torso.rc = RectMakeCenter(_torso.x, _torso.y, 100, 60);

	_head.x = _torso.x;
	_head.y = _torso.y - 50;
	_head.rc = RectMakeCenter(_head.x, _head.y, 40, 40);

	_hair.x = _head.x + 30;
	_hair.y = _head.y;
	_hair.rc = RectMakeCenter(_hair.x, _hair.y, 30, 20);

	_leftArm.x = _torso.x - 60;
	_leftArm.y = _torso.y;
	_leftArm.rc = RectMakeCenter(_leftArm.x, _leftArm.y, 20, 30);

	_rightArm.x = _torso.x + 60;
	_rightArm.y = _torso.y;
	_rightArm.rc = RectMakeCenter(_rightArm.x, _rightArm.y, 20, 30);

	_belly.x = _torso.x;
	_belly.y = _torso.y + 40;
	_belly.rc = RectMakeCenter(_belly.x, _belly.y, 40, 20);

	_legs.x = _belly.x;
	_legs.y = _belly.y + 30;
	_legs.rc = RectMakeCenter(_legs.x, _legs.y, 20, 40);

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
}

void undybattle::render()
{
	D2DRENDER->DrawRectangle
	(
		_torso.rc,
		D2DRenderer::DefaultBrush::Red,
		1.f
		//angle
	);

	D2DRENDER->DrawRectangle
	(
		_head.rc,
		D2DRenderer::DefaultBrush::Red,
		1.f
		//angle
	);

	D2DRENDER->DrawRectangle
	(
		_hair.rc,
		D2DRenderer::DefaultBrush::Red,
		1.f
		//angle
	);

	D2DRENDER->DrawRectangle
	(
		_rightArm.rc,
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

	D2DRENDER->DrawRectangle
	(
		_belly.rc,
		D2DRenderer::DefaultBrush::Red,
		1.f
		//angle
	);

	D2DRENDER->DrawRectangle
	(
		_legs.rc,
		D2DRenderer::DefaultBrush::Red,
		1.f
		//angle
	);

	for (int i = 0; i < BACKMAX; i++)
	{
		D2DRENDER->DrawRectangle
		(
			background[i],
			D2DRenderer::DefaultBrush::Red,
			1.f
			//angle
		);
	}
	_bui->render();
}
