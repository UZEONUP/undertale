#include "stdafx.h"
#include "stage5.h"

HRESULT stage5::init()
{
	ImageManager::GetInstance()->AddImage("테미상점", L"스테이지이미지/temmie shop.png");
	_backGround = ImageManager::GetInstance()->FindImage("테미상점");



	return S_OK;
}

void stage5::release()
{
}

void stage5::update()
{
	if (KEYMANAGER->isOnceKeyDown('X'))
	{
		release();
		SCENEMANAGER->changeScene("stage4");
	}
}

void stage5::render()
{
	_backGround->Render(0, 0);

	if (keyManager::getSingleton()->isToggleKey(VK_F1))
	{
		/*for (int i = 0; i < _setRect->getvGround().size(); i++)
		{
			D2DRENDER->DrawRectangle(_setRect->getvGround()[i].rc, D2DRenderer::DefaultBrush::Red, 1.f);
		}*/
	}
}
