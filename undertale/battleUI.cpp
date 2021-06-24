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
	_menu_off[0] = ImageManager::GetInstance()->AddImage("����_off", L"UI_����_��Ȱ��ȭ_110_42.png");
	_menu_off[1] = ImageManager::GetInstance()->AddImage("�ൿ_off", L"UI_�ൿ_��Ȱ��ȭ_110_42.png");
	_menu_off[2] = ImageManager::GetInstance()->AddImage("������_off", L"UI_������_��Ȱ��ȭ_110_42.png");
	_menu_off[3] = ImageManager::GetInstance()->AddImage("�ں�_off", L"UI_�ں�_��Ȱ��ȭ_110_42.png");
	_menu_on[0] = ImageManager::GetInstance()->AddImage("����_on", L"UI_����_Ȱ��ȭ_110_42.png");
	_menu_on[1] = ImageManager::GetInstance()->AddImage("�ൿ_on", L"UI_�ൿ_Ȱ��ȭ_110_42.png");
	_menu_on[2] = ImageManager::GetInstance()->AddImage("������_on", L"UI_������_Ȱ��ȭ_110_42.png");
	_menu_on[3] = ImageManager::GetInstance()->AddImage("�ں�_on", L"UI_�ں�_Ȱ��ȭ_110_42.png");

	_main_rc.x = WINSIZEX / 2;
	_main_rc.y = WINSIZEY / 2 + 50;
	
	_main_rc.rc = RectMakeCenter(_main_rc.x, _main_rc.y, 150, 150);
	
	_heart = ImageManager::GetInstance()->AddImage("��Ʈ", L"UI_��Ʈ_20_20.png"); 

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
