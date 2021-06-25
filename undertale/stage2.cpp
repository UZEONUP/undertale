#include "stdafx.h"
#include "stage2.h"

HRESULT stage2::init()
{
	ImageManager::GetInstance()->AddImage("언다인스테이지", L"스테이지이미지/undyne stage.png");
	_backGround = ImageManager::GetInstance()->FindImage("언다인스테이지");


	_setRect = new stageRect;
	_setRect->release();

	_setRect->setGround(0, 600, 240, 600);
	_setRect->setGround(400, 600, 240, 600);

	return S_OK;
}

void stage2::release()
{
	_setRect->release();
}

void stage2::update()
{
	_setRect->update();
}

void stage2::render()
{
	_backGround->Render(0, 0, 2.f, 2.f);
	if (keyManager::getSingleton()->isToggleKey(VK_F1))
	{
		for (int i = 0; i < _setRect->getvGround().size(); i++)
		{
			D2DRENDER->DrawRectangle(_setRect->getvGround()[i].rc, D2DRenderer::DefaultBrush::Red, 1.f);
		}
	}
}
