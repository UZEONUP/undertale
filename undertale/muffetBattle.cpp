#include "stdafx.h"
#include "muffetBattle.h"

HRESULT muffetBattle::init()
{
	ImageManager::GetInstance()->AddImage("muffet_dounut", L"�����̹���/dounut.png");
	ImageManager::GetInstance()->AddImage("muffet_croissant", L"�����̹���/croissant.png");
	ImageManager::GetInstance()->AddFrameImage("muffet_pet_down", L"�����̹���/pet down.png", 4, 1);
	ImageManager::GetInstance()->AddFrameImage("muffet_pet_side", L"�����̹���/pet side.png", 2, 1);
	ImageManager::GetInstance()->AddImage("muffet_spider", L"�����̹���/spider.png");

	return S_OK;
}

void muffetBattle::release()
{
}

void muffetBattle::update()
{
}

void muffetBattle::render()
{
}

void muffetBattle::addMuffetImage()
{
}
