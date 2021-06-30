#include "stdafx.h"
#include "stage6.h"

HRESULT stage6::init()
{
	ImageManager::GetInstance()->AddImage("���2", L"���������̹���/node stage2.png");
	_backGround = ImageManager::GetInstance()->FindImage("���2");

	CAMERAMANAGER->setMapCamera(638, 676);

	_setRect = new stageRect;
	_setRect->release();

	_sceneRect = RectMake(285, 260, 75, 40);
	return S_OK;
}

void stage6::release()
{
	_setRect->release();
}

void stage6::update()
{
	_setRect->update();
}

void stage6::render()
{
	/*No.����
	_backGround->Render(0, 0, 2.f, 2.f);*/

	_backGround->mapRender(0, 0);

	if (keyManager::getSingleton()->isToggleKey(VK_F1))
	{
		/*for (int i = 0; i < _setRect->getvGround().size(); i++)
		{
			D2DRENDER->DrawRectangle(_setRect->getvGround()[i].rc, D2DRenderer::DefaultBrush::Red, 1.f);
		}*/
		D2DRENDER->DrawRectangle(_sceneRect, D2DRenderer::DefaultBrush::White, 1.f);
	}
}
