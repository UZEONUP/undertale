#include "stdafx.h"
#include "stage5.h"

HRESULT stage5::init()
{
	ImageManager::GetInstance()->AddImage("�׹̻���", L"���������̹���/temmie shop.png");
	_backGround = ImageManager::GetInstance()->FindImage("�׹̻���");


	_setRect = new stageRect;
	_setRect->release();

	return S_OK;
}

void stage5::release()
{
	_setRect->release();

}

void stage5::update()
{
	_setRect->update();
}

void stage5::render()
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