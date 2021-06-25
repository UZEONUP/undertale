#include "stdafx.h"
#include "stage4.h"

HRESULT stage4::init()
{
	ImageManager::GetInstance()->AddImage("테미마을", L"스테이지이미지/temmie villige.png");
	_backGround = ImageManager::GetInstance()->FindImage("테미마을");


	_setRect = new stageRect;
	_setRect->release();

	return S_OK;
}

void stage4::release()
{
	_setRect->release();
}

void stage4::update()
{
	_setRect->update();
}

void stage4::render()
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
