#include "stdafx.h"
#include "stage5.h"

HRESULT stage5::init()
{
	ImageManager::GetInstance()->AddImage("�׹̻���", L"���������̹���/temmie shop.png");
	_backGround = ImageManager::GetInstance()->FindImage("�׹̻���");

	shopSet();
	itemSet();

	i = 0;

	return S_OK;
}

void stage5::release()
{
}

void stage5::update()
{
	if (KEYMANAGER->isOnceKeyDown(VK_LEFT)&& i>0)i--;
	if (KEYMANAGER->isOnceKeyDown(VK_RIGHT)&& i<4)i++;

	if (KEYMANAGER->isOnceKeyDown(VK_RETURN))
	{
		char ablity[128];
		char price[128];
		ablity[127] = _itoa_s(_vItem[i].ablity, ablity, sizeof(ablity), 10);
		price[127] = _itoa_s(_vItem[i].price, price, sizeof(price), 10);
		INIDATA->addData(_vItem[i].name, "����", _vItem[i].description);
		INIDATA->addData(_vItem[i].name, "ü�� ȸ��", ablity);
		INIDATA->addData(_vItem[i].name, "����", price);
		INIDATA->iniSave("�κ��丮");
	}

	if (KEYMANAGER->isOnceKeyDown('X'))
	{
		release();
		SCENEMANAGER->changeScene("stage4");
	}
}

void stage5::render()
{
	_backGround->Render(0, 0);
	itemOut();
}

void stage5::shopSet()
{

}

void stage5::itemSet()
{
	//40 360
	//280
	/*INIDATA->addData("�Ź� ���̴�", "����", "�Ź̸� ���Ƽ� ���� ��� ���̴ٸ� ����ŷ~!");
	INIDATA->addData("�Ź� ���̴�", "ü�� ȸ��", "24");
	INIDATA->addData("�Ź� ���̴�", "����", "700");
	INIDATA->iniSave("��������Ʈ");

	INIDATA->addData("�Ź� ����", "����", "�Ź� �ٸ��� �� �ڸ��� ��� ������ �վ Ƣ���!");
	INIDATA->addData("�Ź� ����", "�ɷ�", "12");
	INIDATA->addData("�Ź� ����", "����", "400");

	INIDATA->addData("���ͽ�īġ ����", "����", "�������� ���� ������������ �����. ���� �𸥴�!");
	INIDATA->addData("���ͽ�īġ ����", "�ɷ�", "5");
	INIDATA->addData("���ͽ�īġ ����", "����", "250");

	INIDATA->addData("��â��", "����", "������ ��κ��ε� ��â�� ��� ���� �� ����?");
	INIDATA->addData("��â��", "�ɷ�", "10");
	INIDATA->addData("��â��", "����", "500");

	INIDATA->addData("���̽�ũ��", "����", "�Ź̸� ���Ƽ� ���� ��� ���̴ٸ� ����ŷ");
	INIDATA->addData("���̽�ũ��", "�ɷ�", "15");
	INIDATA->addData("���̽�ũ��", "����", "550");

	INIDATA->iniSave("��������Ʈ");*/

	tagItemInfo potion1;
	potion1.rc = RectMake(30, 280, 285, 240);
	potion1.itemKind = ITEM_POTION;
	potion1.name = "�Ź� ���̴�";
	potion1.description ="�Ź̸� ���Ƽ� ���� ��� ���̴ٸ� ����ŷ~!";
	potion1.ablity = 24;
	potion1.price = 700;

	tagItemInfo potion2;
	potion2.rc = RectMake(325, 300, 285, 240);
	potion2.itemKind = ITEM_POTION;
	potion2.name = "�Ź� ����";
	potion2.description = "�Ź� �ٸ��� �� �ڸ��� ��� ������ �վ Ƣ���!";
	potion2.ablity = 12;
	potion2.price = 400;

	tagItemInfo potion3;
	potion3.rc = RectMake(30, 280, 285, 240);
	potion3.itemKind = ITEM_POTION;
	potion3.name = "���ͽ�īġ ����";
	potion3.description = "�������� ���� ������������ �����. ���� �𸥴�!";
	potion3.ablity = 5;
	potion3.price = 250;

	tagItemInfo potion4;
	potion4.rc = RectMake(325, 300, 285, 240);
	potion4.itemKind = ITEM_POTION;
	potion4.name = "��â��";
	potion4.description = "������ ��κ��ε� ��â�� ��� ���� �� ����?";
	potion4.ablity = 10;
	potion4.price = 500;

	tagItemInfo potion5;
	potion5.rc = RectMake(30, 280, 285, 240);
	potion5.itemKind = ITEM_POTION;
	potion5.name = "���̽�ũ��";
	potion5.description = "���̽�!";
	potion5.ablity = 15;
	potion5.price = 550;

	_vItem.push_back(potion1);
	_vItem.push_back(potion2);
	_vItem.push_back(potion3);
	_vItem.push_back(potion4);
	_vItem.push_back(potion5);
}

void stage5::itemOut()
{
	D2DRENDER->RenderText
	(
		20,290,L"�̸�:", 30,D2DDEFAULTBRUSH::White
	);
	D2DRENDER->RenderText
	(
		20, 340, L"����:", 15, D2DDEFAULTBRUSH::White
	);
	D2DRENDER->RenderText
	(
		20, 360, L"ȸ�� ȿ��:", 15, D2DDEFAULTBRUSH::White
	);
	D2DRENDER->RenderText
	(
		20, 380, L"����:", 15, D2DDEFAULTBRUSH::White
	);

	D2DRENDER->RenderTextField
	(
		100, 300,ConvertCtoWC(_vItem[i].name), D2D1COLOR::White,30,280,20
	);
	D2DRENDER->RenderTextField
	(
		100, 340, ConvertCtoWC(_vItem[i].description), D2D1COLOR::White, 15, 460, 20
	);

	char str[128];
	str[64] = _itoa_s(_vItem[i].ablity, str,sizeof(str),10);
	D2DRENDER->RenderTextField
	(
		100, 360, ConvertCtoWC(str), D2D1COLOR::White, 15, 280, 20
	);
	str[64] = _itoa_s(_vItem[i].price, str, sizeof(str), 10);
	D2DRENDER->RenderTextField
	(
		100, 380, ConvertCtoWC(str), D2D1COLOR::White, 15, 280, 20
	);
	
}
