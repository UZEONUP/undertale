#include "stdafx.h"
#include "stage2.h"

HRESULT stage2::init()
{
	ImageManager::GetInstance()->AddImage("����ν�������", L"���������̹���/undyne stage.png");
	_backGround = ImageManager::GetInstance()->FindImage("����ν�������");

	CAMERAMANAGER->setMapCamera(640, 980);

	_setRect = new stageRect;

	_setRect->setGround(0, 200, 230, 1000);
	_setRect->setGround(400, 200, 240, 1000);

	_player = new player;
	_player->init();

	_sceneRect = RectMake(250, 600, 70, 30);


	_undy = new undyne;
	_undy->init();

	_bg = RectMakeCenter(WINSIZEX / 2, WINSIZEY / 2, WINSIZEX, WINSIZEY);

	return S_OK;
}

void stage2::release()
{
	_setRect->release();
}

void stage2::update()
{
	//_undy->update();
}

void stage2::render()
{
	/*No.����
	_backGround->Render(0, 0, 2.f, 2.f);*/

	_backGround->mapRender(-10, -250);

	if (keyManager::getSingleton()->isToggleKey(VK_F1))
	{
		for (int i = 0; i < _setRect->getvGround().size(); i++)
		{
			D2DRENDER->DrawRectangle(_setRect->getvGround()[i].rc, D2DRenderer::DefaultBrush::Red, 1.f);
		}
		D2DRENDER->DrawRectangle(_sceneRect, D2DRenderer::DefaultBrush::White, 1.f);
	}

	
	if (_player->getBattlechk())D2DRENDER->FillRectangle(_bg, D2DRenderer::DefaultBrush::Black);
	//_undy->render();
	char str[128];
	sprintf_s(str, "battlechk : %d ", _player->getBattlechk());
	TextOut(_hdc, 300, 300, str, strlen(str));
}
