#include "stdafx.h"
#include "muffetBattle.h"

HRESULT muffetBattle::init()
{
	ImageManager::GetInstance()->AddImage("muffet_dounut", L"머펫이미지/dounut.png");
	ImageManager::GetInstance()->AddImage("muffet_croissant", L"머펫이미지/croissant.png");
	ImageManager::GetInstance()->AddFrameImage("muffet_pet_down", L"머펫이미지/pet down.png", 4, 1);
	ImageManager::GetInstance()->AddFrameImage("muffet_pet_side", L"머펫이미지/pet side.png", 2, 1);
	ImageManager::GetInstance()->AddImage("muffet_spider", L"머펫이미지/spider.png");

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
