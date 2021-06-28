#include "stdafx.h"
#include "stage6.h"

HRESULT stage6::init()
{
	ImageManager::GetInstance()->AddImage("���2", L"���������̹���/node stage2.png");
	_backGround = ImageManager::GetInstance()->FindImage("���2");


	_setRect = new stageRect;
	_setRect->release();

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

	_backGround->Render(0, 0);

	if (keyManager::getSingleton()->isToggleKey(VK_F1))
	{
		/*for (int i = 0; i < _setRect->getvGround().size(); i++)
		{
			D2DRENDER->DrawRectangle(_setRect->getvGround()[i].rc, D2DRenderer::DefaultBrush::Red, 1.f);
		}*/
	}
}
