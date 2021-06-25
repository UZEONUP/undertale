#include "stdafx.h"
#include "stage3.h"

HRESULT stage3::init()
{
	ImageManager::GetInstance()->AddImage("통로", L"스테이지이미지/node stage.png");
	_backGround = ImageManager::GetInstance()->FindImage("통로");


	_setRect = new stageRect;
	_setRect->release();
	/*_setRect->setGround(0, 600, 240, 600);
	_setRect->setGround(400, 600, 240, 600);*/

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
	_backGround->Render(0, 0, 2.f, 2.f);
	if (keyManager::getSingleton()->isToggleKey(VK_F1))
	{
		/*for (int i = 0; i < _setRect->getvGround().size(); i++)
		{
			D2DRENDER->DrawRectangle(_setRect->getvGround()[i].rc, D2DRenderer::DefaultBrush::Red, 1.f);
		}*/
	}
}
