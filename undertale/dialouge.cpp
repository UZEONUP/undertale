#include "stdafx.h"
#include "dialouge.h"

dialouge::dialouge()
{
}

dialouge::~dialouge()
{
}

HRESULT dialouge::init()
{
	_num = 1;
	i = 0;
	_count = 0;



	_str = INIDATA->loadDataString("������", "����", num);
	_test = INIDATA->loadDataInterger("������", "��ŸƮ��", "1");

	return S_OK;
}

void dialouge::release()
{
}

void dialouge::update()
{
	_count++;
	//�̴ϵ����� title���� �������ֱ����� int to string ��ȯ
	num[64] = _itoa_s(_num, num, sizeof(num), 10);




	//i�� ����� ���̿� ���� ������ ��縦 ��� ǥ��
	//i�� ����� ���̿� ������ ���� ���� �Ѿ
	if (KEYMANAGER->isOnceKeyDown('Z'))
	{
		if (i != strlen(_str))
		{
			i = strlen(_str);
		}
		if (i == strlen(word._change))
		{
			num[64] = _itoa_s(_num, num, sizeof(num), 10);
			_str = INIDATA->loadDataString("������", "����", num);
			_num++;
			i = 0;
		}
	}


	if (_count % 2 == 0)
	{
		strncpy_s(word._change, sizeof(word._change), _str, i * 2);
		i++;
	}


}

void dialouge::render()
{
	SetTextColor(_hdc, RGB(255, 255, 255));
	char str[256];
	HFONT font, oldFont;
	/*
	CreateFont(
			40,					������
			0,					���� ����
			40,					���� ����
			0,					���� ����
			600,				���� ����
			0,					bool ���� ����(���Ÿ�ü)
			0,					bool ���� ����
			0,					bool ���� ��Ҽ�
			HANGUL_CHARSET,		���� ����
			0,					��� ��Ȯ��
			0,					Ŭ���� ��Ȯ��
			0,					��� ����Ƽ
			0,					�ڰ�
			TEXT("�ü�ü")
	);
	*/


	font = CreateFont(30, 0, 0, 0, 600, false, false, false, HANGUL_CHARSET,
		0, 0, 0, 0, TEXT("-��������������"));
	oldFont = (HFONT)SelectObject(_hdc, font);


	TextOut(_hdc, 150, 500, word._change, strlen(word._change));




	DeleteObject(font);


}
