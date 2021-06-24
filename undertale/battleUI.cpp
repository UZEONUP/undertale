#include "stdafx.h"
#include "battleUI.h"

battleUI::battleUI()
{
}

battleUI::~battleUI()
{
}

HRESULT battleUI::init()
{
	_menu_off[0] = ImageManager::GetInstance()->AddImage("공격_off", L"UI_공격_비활성화_110_42.png");
	_menu_off[1] = ImageManager::GetInstance()->AddImage("행동_off", L"UI_행동_비활성화_110_42.png");
	_menu_off[2] = ImageManager::GetInstance()->AddImage("아이템_off", L"UI_아이템_비활성화_110_42.png");
	_menu_off[3] = ImageManager::GetInstance()->AddImage("자비_off", L"UI_자비_비활성화_110_42.png");
	_menu_on[0] = ImageManager::GetInstance()->AddImage("공격_on", L"UI_공격_활성화_110_42.png");
	_menu_on[1] = ImageManager::GetInstance()->AddImage("행동_on", L"UI_행동_활성화_110_42.png");
	_menu_on[2] = ImageManager::GetInstance()->AddImage("아이템_on", L"UI_아이템_활성화_110_42.png");
	_menu_on[3] = ImageManager::GetInstance()->AddImage("자비_on", L"UI_자비_활성화_110_42.png");

	_main_rc.x = WINSIZEX / 2;
	_main_rc.y = WINSIZEY / 2 + 50;
	
	_main_rc.rc = RectMakeCenter(_main_rc.x, _main_rc.y, 150, 150);
	
	_heart = ImageManager::GetInstance()->AddImage("하트", L"UI_하트_20_20.png"); 

	_menu_count = 0;

	return S_OK;
}

void battleUI::release()
{
}

void battleUI::update()
{
	if (KEYMANAGER->isOnceKeyDown(VK_LEFT))
	{
		_menu_count--;
		if (_menu_count < 0) _menu_count = 0;
	}
	if (KEYMANAGER->isOnceKeyDown(VK_RIGHT))
	{
		_menu_count++;
		if (_menu_count > 3) _menu_count = 3;
	}
}

void battleUI::render()
{
	D2DRENDER->DrawRectangle
	(
		_main_rc.rc,
		D2DRenderer::DefaultBrush::White,
		5.F
	);

	_menu_off[0]->Render(0, 0, 1, 1, 0, 0, 0, 20, WINSIZEY - 50);
	_menu_off[1]->Render(0, 0, 1, 1, 0, 0, 0, 20 + 150, WINSIZEY - 50);
	_menu_off[2]->Render(0, 0, 1, 1, 0, 0, 0, 20 + 300, WINSIZEY - 50);
	_menu_off[3]->Render(0, 0, 1, 1, 0, 0, 0, 20 + 450, WINSIZEY - 50);
	
	
	
	
	if (_menu_count == 0) 
	{
		_menu_on[0]->Render(0, 0, 1, 1, 0, 0, 0, 20, WINSIZEY - 50);
		_heart->Render(0, 0, 1, 1, 0, 0, 0, 30, WINSIZEY - 40);
	}
	if (_menu_count == 1) 
	{
		_menu_on[1]->Render(0, 0, 1, 1, 0, 0, 0, 20 + 150, WINSIZEY - 50);
		_heart->Render(0, 0, 1, 1, 0, 0, 0, 30 + 150, WINSIZEY - 40);
	}
	if (_menu_count == 2) 
	{
		_menu_on[2]->Render(0, 0, 1, 1, 0, 0, 0, 20 + 300, WINSIZEY - 50);
		_heart->Render(0, 0, 1, 1, 0, 0, 0, 30 + 300, WINSIZEY - 40);
	}
	if (_menu_count == 3) 
	{
		_menu_on[3]->Render(0, 0, 1, 1, 0, 0, 0, 20 + 450, WINSIZEY - 50);
		_heart->Render(0, 0, 1, 1, 0, 0, 0, 30 + 450, WINSIZEY - 40);
	}
	
}
