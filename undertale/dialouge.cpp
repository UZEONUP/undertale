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



	_str = INIDATA->loadDataString("우전없", "샌즈", num);
	_test = INIDATA->loadDataInterger("우전없", "메타트론", "1");

	return S_OK;
}

void dialouge::release()
{
}

void dialouge::update()
{
	_count++;
	//이니데이터 title값을 변경해주기위해 int to string 변환
	num[64] = _itoa_s(_num, num, sizeof(num), 10);




	//i가 대사의 길이와 같이 않으면 대사를 모두 표시
	//i가 대사의 길이와 같으면 다음 대사로 넘어감
	if (KEYMANAGER->isOnceKeyDown('Z'))
	{
		if (i != strlen(_str))
		{
			i = strlen(_str);
		}
		if (i == strlen(word._change))
		{
			num[64] = _itoa_s(_num, num, sizeof(num), 10);
			_str = INIDATA->loadDataString("우전없", "샌즈", num);
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
			40,					문자폭
			0,					문자 넓이
			40,					문자 기울기
			0,					문자 방향
			600,				문자 굵기
			0,					bool 문자 기울기(이탤릭체)
			0,					bool 문자 밑줄
			0,					bool 문자 취소선
			HANGUL_CHARSET,		문자 셋팅
			0,					출력 정확도
			0,					클리핑 정확도
			0,					출력 퀄리티
			0,					자간
			TEXT("궁서체")
	);
	*/


	font = CreateFont(30, 0, 0, 0, 600, false, false, false, HANGUL_CHARSET,
		0, 0, 0, 0, TEXT("-윤디자인웹돋움"));
	oldFont = (HFONT)SelectObject(_hdc, font);


	TextOut(_hdc, 150, 500, word._change, strlen(word._change));




	DeleteObject(font);


}
