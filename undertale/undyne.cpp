#include "stdafx.h"
#include "undyne.h"

HRESULT undyne::init()
{
	

	_torso.x = WINSIZEX / 2 + 300;
	_torso.y = WINSIZEY / 2;
	_torso.rc = RectMakeCenter(_torso.x, _torso.y,50,30);

	_head.x = _torso.x;
	_head.y = _torso.y - 20;
	_head.rc = RectMakeCenter(_head.x, _head.y, 20, 20);




	return S_OK;
}

void undyne::release()
{
}

void undyne::update()
{
}

void undyne::render()
{
	D2DRENDER->DrawRectangle
	(
		_head.rc,
		D2DRenderer::DefaultBrush::Red,1.f
	);

	D2DRENDER->DrawRectangle
	(
		_torso.rc,
		D2DRenderer::DefaultBrush::Red, 1.f
	);
}
