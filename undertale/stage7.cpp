#include "stdafx.h"
#include "stage7.h"

HRESULT stage7::init()
{
	ImageManager::GetInstance()->AddImage("마지막", L"스테이지이미지/last stage.png");
	_backGround = ImageManager::GetInstance()->FindImage("마지막");


	_setRect = new stageRect;
	_setRect->release();

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
	_backGround->Render(0, 0, 2.f, 2.f);
	if (keyManager::getSingleton()->isToggleKey(VK_F1))
	{
		/*for (int i = 0; i < _setRect->getvGround().size(); i++)
		{
			D2DRENDER->DrawRectangle(_setRect->getvGround()[i].rc, D2DRenderer::DefaultBrush::Red, 1.f);
		}*/
	}
}
