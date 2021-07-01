#include "stdafx.h"
#include "progressBar.h"

progressBar::progressBar()
{
}

progressBar::~progressBar()
{
}

HRESULT progressBar::init(float x, float y, float width, float height)
{
	_x = x;
	_y = y;
	_width = width;

	_rc = RectMake(x, y, width, height);

	barTop = IMAGEMANAGER->AddImage("frontBar", L"hpBarTop.png");
	barBottom = IMAGEMANAGER->AddImage("bottomBar", L"hpBarBottom.png");
	

	return S_OK;
}

void progressBar::release()
{
}

void progressBar::update()
{
	_rc = RectMakeCenter(_x, _y, barTop->GetWidth(), barTop->GetHeight());
}

void progressBar::render()
{
	barBottom->Render(_rc.left,_rc.top);
	barTop->barRender(_rc.left,_rc.top,_width);
}

void progressBar::setGauge(float currentGauge, float maxGauge)
{
	_width = (currentGauge / maxGauge) * barBottom->GetWidth();
}
