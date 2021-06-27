#include "stdafx.h"
#include "stage3.h"

HRESULT stage3::init()
{
	ImageManager::GetInstance()->AddImage("통로", L"스테이지이미지/node stage.png");
	_backGround = ImageManager::GetInstance()->FindImage("통로");


	_setRect = new stageRect;
	_setRect->release();
	_setRect->setGround(0, 280, 40, 160);
	_setRect->setGround(40, 440, 400, 40);
	_setRect->setGround(520, 440, 80, 40);
	_setRect->setGround(600, 280, 40, 160);
	_setRect->setGround(160, 240, 440, 40);

	return S_OK;
}

void stage3::release()
{
	_setRect->release();
}

void stage3::update()
{
	_setRect->update();
}

void stage3::render()
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
