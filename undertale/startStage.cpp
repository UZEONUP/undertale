#include "stdafx.h"
#include "startStage.h"

HRESULT startStage::init()
{
	IMAGEMANAGER->AddImage("donut", L"Undyne/RIGHT_ARROW_OFF.png");
	IMAGEMANAGER->AddImage("시작스테이지", L"스테이지이미지/start stage.png");
	_backGround = IMAGEMANAGER->FindImage("시작스테이지");

	CAMERAMANAGER->setMapCamera(1360, 520);

	_player = new player;
	_player->init(WINSIZEX/2, WINSIZEY/2);
	_setRect = new stageRect;

	_setRect->setGround(0, 0, 480, 120);
	_setRect->setGround(0, 0, 116, 158);
	_setRect->setGround(0, 160, 40, 200);
	_setRect->setGround(30, 360, 50, 40);
	_setRect->setGround(80, 400, 40, 40);
	_setRect->setGround(120, 440, 40, 40);
	_setRect->setGround(160, 480, 280, 40);
	_setRect->setGround(440, 440, 40, 40);
	_setRect->setGround(480, 400, 840, 40);
	_setRect->setGround(1320, 320, 40, 80);
	_setRect->setGround(1274, 206, 40, 114);
	_setRect->setGround(560, 160, 632, 160);
	_setRect->setGround(480, 120, 80, 40);

	_sceneRect = RectMake(1200, 270, 70, 30);

	_timer = 0;
	_bar = new progressBar;
	_bar->init(WINSIZEX / 2, WINSIZEY / 2 - 100,60,30);
	hp = 0;

	SAVELOADMANAGER->linkPlayer(_player);
	//BULLETMANAGER->linkPlayer(_player);
	_setRect->linkPlayer(_player);
	_bar->linkPlayer(_player);


	//BULLETMANAGER->init("donut", 30, 400);

	return S_OK;
}

void startStage::release()
{
	_player->release();
	_setRect->release();
}

void startStage::update()
{
	/*_timer++;
	if (_timer%5 == 0)
	{
		_timer = 0;
		BULLETMANAGER->fire(600, 50,GetAngle( 600, 50,_player->getX(),_player->getY()));
	}
	BULLETMANAGER->move();*/

	if (IsCollision(_player->getBRect(), _sceneRect))
	{
		_player->setMoveStop(1);
		_player->setAlpha(_player->getAlpha() - 0.01f);
		if (_player->getAlpha() <= 0.f)
		{
			release();
			SCENEMANAGER->changeScene("stage2");
		}
	}

	_setRect->update();
	if(!_player->getMoveStop())_player->update();
	_bar->update();
	hp += 0.1f;
	_bar->setGauge(300-hp, 300);
}

void startStage::render()
{
	_backGround->mapRender(0, 0);

	_player->render();
	_bar->render();
	//BULLETMANAGER->render();
	if (keyManager::getSingleton()->isToggleKey(VK_F1))
	{
		for (int i = 0; i < _setRect->getvGround().size(); i++)
		{
			D2DRENDER->DrawRectangle(_setRect->getvGround()[i].rc, D2DRenderer::DefaultBrush::Red, 1.f);
		}
		D2DRENDER->DrawRectangle(_sceneRect, D2DRenderer::DefaultBrush::White, 1.f);
	}
}
