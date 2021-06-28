#include "stdafx.h"
#include "stage7.h"

HRESULT stage7::init()
{
	ImageManager::GetInstance()->AddImage("마지막", L"스테이지이미지/last stage.png");
	_backGround = ImageManager::GetInstance()->FindImage("마지막");


	_setRect = new stageRect;
	_setRect->release();

	_setRect->setGround(0, 0, 80, 1200);
	_setRect->setGround(80, 960, 40, 46);
	_setRect->setGround(120, 1000, 80, 40);
	_setRect->setGround(200, 1400, 80, 160);
	_setRect->setGround(360, 1400, 80, 160);
	_setRect->setGround(440, 1000, 80, 40);
	_setRect->setGround(520, 960, 40, 46);
	_setRect->setGround(560, 0, 80, 1200);
	_setRect->setGround(80, 230, 40, 90);
	_setRect->setGround(120, 150, 400, 86);
	_setRect->setGround(200, 1040, 80, 160);
	_setRect->setGround(360, 1040, 80, 160);
	_setRect->setGround(520, 230, 40, 90);

	return S_OK;
}

void stage7::release()
{
	_setRect->release();
}

void stage7::update()
{
	_setRect->update();
}

void stage7::render()
{
	/*No.수정
	_backGround->Render(0, 0, 2.f, 2.f);*/

	_backGround->Render(0, 0);

	if (keyManager::getSingleton()->isToggleKey(VK_F1))
	{
		for (int i = 0; i < _setRect->getvGround().size(); i++)
		{
			D2DRENDER->DrawRectangle(_setRect->getvGround()[i].rc, D2DRenderer::DefaultBrush::Red, 1.f);
		}
	}
}
