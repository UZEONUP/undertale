#include "stdafx.h"
#include "startStage.h"

HRESULT startStage::init()
{
	ImageManager::GetInstance()->AddImage("시작스테이지", L"스테이지이미지/start stage.png");
	_backGround = ImageManager::GetInstance()->FindImage("시작스테이지");

	CAMERAMANAGER->setMapCamera(1360, 520);

	/*_player = new player;
	_player->init(WINSIZEX/2, WINSIZEY/2);*/

	_setRect = new stageRect;

	_setRect->setGround(0,0, 480, 120);
	_setRect->setGround(0,0, 116, 158);
	_setRect->setGround(0,160, 40, 360);
	_setRect->setGround(30,360, 50, 40);
	_setRect->setGround(80, 400, 40, 40);
	_setRect->setGround(120, 440, 40, 40);
	_setRect->setGround(160, 480, 280, 40);
	_setRect->setGround(440, 440, 40, 40);
	_setRect->setGround(480, 400, 840, 40);
	_setRect->setGround(1320, 320, 40, 80);
	_setRect->setGround(1274, 206, 40, 114);
	_setRect->setGround(560, 160, 632, 160);
	_setRect->setGround(480, 120, 60, 40);



	return S_OK;
}

void startStage::release()
{
	_setRect->release();
}

void startStage::update()
{
	_setRect->update();
	//_player->update();
}

void startStage::render()
{
	/*No.수정
	_backGround->Render(0, 0, 2.f, 2.f);*/

	_backGround->mapRender(0, 0);

	//_player->render();
	if (keyManager::getSingleton()->isToggleKey(VK_F1))
	{
		for (int i = 0; i < _setRect->getvGround().size(); i++)
		{
			D2DRENDER->DrawRectangle(_setRect->getvGround()[i].rc, D2DRenderer::DefaultBrush::Red, 1.f);
		}
	}
}
