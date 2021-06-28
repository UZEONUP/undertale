#include "stdafx.h"
#include "stage2.h"

HRESULT stage2::init()
{
	ImageManager::GetInstance()->AddImage("언다인스테이지", L"스테이지이미지/undyne stage.png");
	_backGround = ImageManager::GetInstance()->FindImage("언다인스테이지");

	CAMERAMANAGER->setMapCamera(640, 1280);

	_setRect = new stageRect;

	_setRect->setGround(0, 600, 240, 600);
	_setRect->setGround(400, 600, 240, 600);

	_player = new player;
	_player->init();

	_undy = new undyne;
	_undy->init();

	_bg = RectMakeCenter(WINSIZEX / 2, WINSIZEY / 2, WINSIZEX, WINSIZEY);

	_sceneRect = RectMake(270, 900, 90, 40);
	return S_OK;
}

void stage2::release()
{
	_setRect->release();
}

void stage2::update()
{
	float x = _player->getX();
	float y = _player->getY();
	float angle;

	RECT temp;
	if (IntersectRect(&temp, &_player->getRect(), &_undy->getRect()))
		_player->setBattlechk(true);


	if (_player->getBattlechk())
	{
		_player->setHeart(x, y);
	}


	_player->update();
	_undy->update();
}

void stage2::render()
{
	/*No.수정
	_backGround->Render(0, 0, 2.f, 2.f);*/

	_backGround->mapRender(-0, -0);

	if (keyManager::getSingleton()->isToggleKey(VK_F1))
	{
		for (int i = 0; i < _setRect->getvGround().size(); i++)
		{
			D2DRENDER->DrawRectangle(_setRect->getvGround()[i].rc, D2DRenderer::DefaultBrush::Red, 1.f);
		}
		D2DRENDER->DrawRectangle(_sceneRect, D2DRenderer::DefaultBrush::White, 1.f);
	}

	
	if (_player->getBattlechk())D2DRENDER->FillRectangle(_bg, D2DRenderer::DefaultBrush::Black);
	_player->render();
	_undy->render();
	char str[128];
	sprintf_s(str, "battlechk : %d ", _player->getBattlechk());
	TextOut(_hdc, 300, 300, str, strlen(str));
}
