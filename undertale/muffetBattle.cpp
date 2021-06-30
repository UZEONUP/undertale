#include "stdafx.h"
#include "muffetBattle.h"

HRESULT muffetBattle::init()
{
	_btUI = new battleUI;
	_btUI->init(2);

	addMuffetImage();

	/*_mfImage.isFrameImage = false;
	_mfImage.img = ImageManager::GetInstance()->FindImage("muffet_samfle");
	_mfImage.currentFrameX = 0;
	_mfImage.angle = 0;
	_mfImage.x = WINSIZEX / 2;
	_mfImage.y = 90;
	_mfImage.rc = RectMake(_mfImage.x, _mfImage.y, 17, 24);

	_muffetV.push_back(_mfImage);*/

	//머리 머리카락 LR==================================
	_mfImage.isFrameImage = false;
	_mfImage.img = ImageManager::GetInstance()->FindImage("muffet_hair_L");
	_mfImage.angle = 0;
	_mfImage.x = WINSIZEX / 2 - 35;
	_mfImage.y = 50;
	_mfImage.rc = RectMake(_mfImage.x, _mfImage.y, 15, 16);

	_muffetV.push_back(_mfImage);


	_mfImage.isFrameImage = false;
	_mfImage.img = ImageManager::GetInstance()->FindImage("muffet_hair_R");
	_mfImage.angle = 0;
	_mfImage.x = WINSIZEX / 2 + 16;
	_mfImage.y = 50;
	_mfImage.rc = RectMake(_mfImage.x, _mfImage.y, 15, 16);

	_muffetV.push_back(_mfImage);


	_mfImage.isFrameImage = false;
	_mfImage.img = ImageManager::GetInstance()->FindImage("muffet_head");
	_mfImage.angle = 0;
	_mfImage.x = WINSIZEX / 2 - 25;
	_mfImage.y = 50;
	_mfImage.rc = RectMake(_mfImage.x, _mfImage.y, 46, 50);

	_muffetV.push_back(_mfImage);
	//========================================================
	//2
	//눈1~5===================================================
	_mfImage.isFrameImage = true;
	_mfImage.img = ImageManager::GetInstance()->FindImage("muffet_eye1");
	_mfImage.currentFrameX = 0;
	_mfImage.angle = 0;
	_mfImage.x = WINSIZEX / 2 - 13;
	_mfImage.y = 71;
	_mfImage.rc = RectMake(_mfImage.x, _mfImage.y, 7, 9);

	_muffetV.push_back(_mfImage);


	_mfImage.isFrameImage = true;
	_mfImage.img = ImageManager::GetInstance()->FindImage("muffet_eye2");
	_mfImage.currentFrameX = 0;
	_mfImage.angle = 0;
	_mfImage.x = WINSIZEX / 2 - 10;
	_mfImage.y = 66;
	_mfImage.rc = RectMake(_mfImage.x, _mfImage.y, 5, 5);

	_muffetV.push_back(_mfImage);


	_mfImage.isFrameImage = true;
	_mfImage.img = ImageManager::GetInstance()->FindImage("muffet_eye3");
	_mfImage.currentFrameX = 0;
	_mfImage.angle = 0;
	_mfImage.x = WINSIZEX / 2 - 4;
	_mfImage.y = 62;
	_mfImage.rc = RectMake(_mfImage.x, _mfImage.y, 5, 5);

	_muffetV.push_back(_mfImage);


	_mfImage.isFrameImage = true;
	_mfImage.img = ImageManager::GetInstance()->FindImage("muffet_eye4");
	_mfImage.currentFrameX = 0;
	_mfImage.angle = 0;
	_mfImage.x = WINSIZEX / 2 + 1;
	_mfImage.y = 66;
	_mfImage.rc = RectMake(_mfImage.x, _mfImage.y, 9, 9);

	_muffetV.push_back(_mfImage);


	_mfImage.isFrameImage = true;
	_mfImage.img = ImageManager::GetInstance()->FindImage("muffet_eye5");
	_mfImage.currentFrameX = 0;
	_mfImage.angle = 0;
	_mfImage.x = WINSIZEX / 2 + 2;
	_mfImage.y = 71;
	_mfImage.rc = RectMake(_mfImage.x, _mfImage.y, 7, 9);

	_muffetV.push_back(_mfImage);
	//========================================================
	//7
	//어깨=====================================================
	_mfImage.isFrameImage = true;
	_mfImage.img = ImageManager::GetInstance()->FindImage("muffet_shoulder_top");
	_mfImage.currentFrameX = 0;
	_mfImage.angle = 0;
	_mfImage.x = WINSIZEX / 2 - 20;
	_mfImage.y = 93;
	_mfImage.rc = RectMake(_mfImage.x, _mfImage.y, 36, 18);

	_muffetV.push_back(_mfImage);


	_mfImage.isFrameImage = true;
	_mfImage.img = ImageManager::GetInstance()->FindImage("muffet_shoulder_bottom");
	_mfImage.currentFrameX = 0;
	_mfImage.angle = 0;
	_mfImage.x = WINSIZEX / 2 - 22;
	_mfImage.y = 106;
	_mfImage.rc = RectMake(_mfImage.x, _mfImage.y, 36, 18);

	_muffetV.push_back(_mfImage);
	////===========================================================
	////9
	////팔1~4======================================================
	_mfImage.isFrameImage = false;
	_mfImage.img = ImageManager::GetInstance()->FindImage("muffet_arm1");
	_mfImage.currentFrameX = 0;
	_mfImage.angle = 0;
	_mfImage.x = WINSIZEX / 2 - 46;
	_mfImage.y = 88;
	_mfImage.rc = RectMake(_mfImage.x, _mfImage.y, 27, 22);

	_muffetV.push_back(_mfImage);


	_mfImage.isFrameImage = false;
	_mfImage.img = ImageManager::GetInstance()->FindImage("muffet_arm2");
	_mfImage.currentFrameX = 0;
	_mfImage.angle = 0;
	_mfImage.x = WINSIZEX / 2 + 15;
	_mfImage.y = 88;
	_mfImage.rc = RectMake(_mfImage.x, _mfImage.y, 27, 22);

	_muffetV.push_back(_mfImage);


	_mfImage.isFrameImage = false;
	_mfImage.img = ImageManager::GetInstance()->FindImage("muffet_arm3");
	_mfImage.currentFrameX = 0;
	_mfImage.angle = 0;
	_mfImage.x = WINSIZEX / 2 - 37;
	_mfImage.y = 106;
	_mfImage.rc = RectMake(_mfImage.x, _mfImage.y, 15, 17);

	_muffetV.push_back(_mfImage);


	_mfImage.isFrameImage = false;
	_mfImage.img = ImageManager::GetInstance()->FindImage("muffet_arm4");
	_mfImage.currentFrameX = 0;
	_mfImage.angle = 0;
	_mfImage.x = WINSIZEX / 2 + 19;
	_mfImage.y = 106;
	_mfImage.rc = RectMake(_mfImage.x, _mfImage.y, 15, 17);

	_muffetV.push_back(_mfImage);
	//====================================
	//13
	//아래 팔1, 2==========================
	_mfImage.isFrameImage = false;
	_mfImage.img = ImageManager::GetInstance()->FindImage("muffet_arm5");
	_mfImage.currentFrameX = 0;
	_mfImage.angle = 15;
	_mfImage.x = WINSIZEX / 2 - 20;
	_mfImage.y = 113;
	_mfImage.rc = RectMake(_mfImage.x, _mfImage.y, 10, 33);

	_muffetV.push_back(_mfImage);


	_mfImage.isFrameImage = false;
	_mfImage.img = ImageManager::GetInstance()->FindImage("muffet_arm6");
	_mfImage.currentFrameX = 0;
	_mfImage.angle = 345;
	_mfImage.x = WINSIZEX / 2 + 3;
	_mfImage.y = 117;
	_mfImage.rc = RectMake(_mfImage.x, _mfImage.y, 10, 33);

	_muffetV.push_back(_mfImage);


	_mfImage.isFrameImage = false;
	_mfImage.img = ImageManager::GetInstance()->FindImage("muffet_arm7");
	_mfImage.currentFrameX = 0;
	_mfImage.angle = 0;
	_mfImage.x = WINSIZEX / 2 - 20;
	_mfImage.y = 116;
	_mfImage.rc = RectMake(_mfImage.x, _mfImage.y, 15, 32);

	_muffetV.push_back(_mfImage);


	_mfImage.isFrameImage = false;
	_mfImage.img = ImageManager::GetInstance()->FindImage("muffet_arm8");
	_mfImage.currentFrameX = 0;
	_mfImage.angle = 0;
	_mfImage.x = WINSIZEX / 2 + 5;
	_mfImage.y = 116;
	_mfImage.rc = RectMake(_mfImage.x, _mfImage.y, 15, 32);

	_muffetV.push_back(_mfImage);

	////========================
	////18
	////티포트=========================
	_mfImage.isFrameImage = false;
	_mfImage.img = ImageManager::GetInstance()->FindImage("muffet_hand_L");
	_mfImage.currentFrameX = 0;
	_mfImage.angle = 0;
	_mfImage.x = WINSIZEX / 2 - 60;
	_mfImage.y = 100;
	_mfImage.rc = RectMake(_mfImage.x, _mfImage.y, 24, 17);

	_muffetV.push_back(_mfImage);


	_mfImage.isFrameImage = false;
	_mfImage.img = ImageManager::GetInstance()->FindImage("muffet_hand_R");
	_mfImage.currentFrameX = 0;
	_mfImage.angle = 0;
	_mfImage.x = WINSIZEX / 2 + 33;
	_mfImage.y = 100;
	_mfImage.rc = RectMake(_mfImage.x, _mfImage.y, 24, 17);

	_muffetV.push_back(_mfImage);
	////======================================================
	////20
	////몸==============================================
	_mfImage.isFrameImage = false;
	_mfImage.img = ImageManager::GetInstance()->FindImage("muffet_leg");
	_mfImage.currentFrameX = 0;
	_mfImage.angle = 0;
	_mfImage.x = WINSIZEX / 2 - 11;
	_mfImage.y = 135;
	_mfImage.rc = RectMake(_mfImage.x, _mfImage.y, 17, 24);

	_muffetV.push_back(_mfImage);


	_mfImage.isFrameImage = false;
	_mfImage.img = ImageManager::GetInstance()->FindImage("muffet_body_bottom");
	_mfImage.currentFrameX = 0;
	_mfImage.angle = 0;
	_mfImage.x = WINSIZEX / 2 - 15;
	_mfImage.y = 110;
	_mfImage.rc = RectMake(_mfImage.x, _mfImage.y, 25, 26);

	_muffetV.push_back(_mfImage);


	_mfImage.isFrameImage = false;
	_mfImage.img = ImageManager::GetInstance()->FindImage("muffet_body_top");
	_mfImage.currentFrameX = 0;
	_mfImage.angle = 0;
	_mfImage.x = WINSIZEX / 2 - 11;
	_mfImage.y = 98;
	_mfImage.rc = RectMake(_mfImage.x, _mfImage.y, 18, 16);

	_muffetV.push_back(_mfImage);


	return S_OK;
}

void muffetBattle::release()
{
}

void muffetBattle::update()
{
	_btUI->update();
}

void muffetBattle::render()
{
	for (int i = 0; i < _muffetV.size(); i++)
	{
		if (_muffetV[i].isFrameImage)
		{
			_muffetV[i].img->autoFrameRender(_muffetV[i].x, _muffetV[i].y, _muffetV[i].currentFrameX, 1, 10);
		}
		else if (!_muffetV[i].isFrameImage && _muffetV[i].angle == 0)
		{
			_muffetV[i].img->Render(_muffetV[i].x, _muffetV[i].y);
		}
		if (_muffetV[i].angle != 0)
		{
			_muffetV[i].img->Render(_muffetV[i].x, _muffetV[i].y, 1, 1, _muffetV[i].angle);
		}
	}
	_btUI->render();
}

void muffetBattle::addMuffetImage()
{
	ImageManager::GetInstance()->AddImage("muffet_head", L"머펫이미지/head.png");
	ImageManager::GetInstance()->AddImage("muffet_hair_L", L"머펫이미지/hair.png");
	ImageManager::GetInstance()->AddImage("muffet_hair_R", L"머펫이미지/hair2.png");

	ImageManager::GetInstance()->AddFrameImage("muffet_eye1", L"머펫이미지/eye1.png", 7, 1);
	ImageManager::GetInstance()->AddFrameImage("muffet_eye2", L"머펫이미지/eye2.png", 7, 1);
	ImageManager::GetInstance()->AddFrameImage("muffet_eye3", L"머펫이미지/eye3.png", 7, 1);
	ImageManager::GetInstance()->AddFrameImage("muffet_eye4", L"머펫이미지/eye4.png", 7, 1);
	ImageManager::GetInstance()->AddFrameImage("muffet_eye5", L"머펫이미지/eye5.png", 7, 1);

	ImageManager::GetInstance()->AddImage("muffet_shoulder_top", L"머펫이미지/shoulder.png");
	ImageManager::GetInstance()->AddImage("muffet_shoulder_bottom", L"머펫이미지/shoulder2.png");

	ImageManager::GetInstance()->AddImage("muffet_arm1", L"머펫이미지/teaglass left.png");
	ImageManager::GetInstance()->AddImage("muffet_arm2", L"머펫이미지/teaglass right.png");
	ImageManager::GetInstance()->AddImage("muffet_arm3", L"머펫이미지/arm left.png");
	ImageManager::GetInstance()->AddImage("muffet_arm4", L"머펫이미지/arm right.png");

	ImageManager::GetInstance()->AddImage("muffet_arm5", L"머펫이미지/bottom arm left.png");
	ImageManager::GetInstance()->AddImage("muffet_arm6", L"머펫이미지/bottom arm right.png");

	ImageManager::GetInstance()->AddImage("muffet_arm7", L"머펫이미지/bottom arm fist left.png");
	ImageManager::GetInstance()->AddImage("muffet_arm8", L"머펫이미지/bottom arm fist right.png");

	ImageManager::GetInstance()->AddImage("muffet_hand_L", L"머펫이미지/teaport left.png");
	ImageManager::GetInstance()->AddImage("muffet_hand_R", L"머펫이미지/teaport right.png");

	ImageManager::GetInstance()->AddImage("muffet_body_top", L"머펫이미지/body top.png");
	ImageManager::GetInstance()->AddImage("muffet_body_bottom", L"머펫이미지/body bottom.png");
	ImageManager::GetInstance()->AddImage("muffet_leg", L"머펫이미지/leg.png");


	ImageManager::GetInstance()->AddImage("muffet_hit", L"머펫이미지/hit.png");
	ImageManager::GetInstance()->AddImage("muffet_samfle", L"머펫이미지/battle.png");

}
