#include "stdafx.h"
#include "sansBattle.h"

sansBattle::sansBattle()
{
}

sansBattle::~sansBattle()
{
}

HRESULT sansBattle::init()
{
	_ui = new battleUI;
	_ui->init(1);

	ImageManager::GetInstance()->AddFrameImage("»÷Áî_¸Ó¸®", L"»÷ÁîÀÌ¹ÌÁö/»÷Áî_head_32_30_17.png", 17, 1);
	ImageManager::GetInstance()->AddFrameImage("»÷Áî_¶¡", L"»÷ÁîÀÌ¹ÌÁö/»÷Áî_sweat_32_9_3.png", 3, 1);
	ImageManager::GetInstance()->AddFrameImage("»÷Áî_¸ö", L"»÷ÁîÀÌ¹ÌÁö/»÷Áî_body_72_35_8.png", 8, 1);
	ImageManager::GetInstance()->AddFrameImage("»÷Áî_´Ù¸®", L"»÷ÁîÀÌ¹ÌÁö/»÷Áî_legs_52_23_2.png", 2, 1);
	ImageManager::GetInstance()->AddFrameImage("»÷Áî_¾Æ·¡°ø°Ý", L"»÷ÁîÀÌ¹ÌÁö/»÷Áî_attackDown_62_73_5.png", 5, 1);
	ImageManager::GetInstance()->AddFrameImage("»÷Áî_À§°ø°Ý", L"»÷ÁîÀÌ¹ÌÁö/»÷Áî_attackUp_62_73_5.png", 5, 1);
	ImageManager::GetInstance()->AddFrameImage("»÷Áî_¿À¸¥ÂÊ°ø°Ý", L"»÷ÁîÀÌ¹ÌÁö/»÷Áî_attackRight_97_48_6.png", 6, 1);
	ImageManager::GetInstance()->AddFrameImage("»÷Áî_¿ÞÂÊ°ø°Ý", L"»÷ÁîÀÌ¹ÌÁö/»÷Áî_attackLeft_97_48_6.png", 6, 1);
	ImageManager::GetInstance()->AddImage("»À´Ù±Í_20", L"»÷ÁîÀÌ¹ÌÁö/»À´Ù±Í_10_20.png");

	_sans_head.x = 290;
	_sans_head.y = 120;
	_sans_head.width = 32;
	_sans_head.hieght = 30;
	_sans_head.currentFrameX = 4;
	_sans_head.currentFrameY = 0;
	_sans_head.rc = RectMakeCenter(_sans_head.x, _sans_head.y, _sans_head.width, _sans_head.hieght);

	/*_sans_sweat.x = 290;
	_sans_sweat.y = 120;
	_sans_sweat.width = 32;
	_sans_sweat.hieght = 30;
	_sans_sweat.currentFrameX = 0;
	_sans_sweat.currentFrameY = 0;
	_sans_sweat.rc = RectMakeCenter(_sans_sweat.x, _sans_sweat.y, _sans_sweat.width, _sans_sweat.hieght);*/

	_sans_body.x = 290;
	_sans_body.y = 150;
	_sans_body.width = 72;
	_sans_body.hieght = 35;
	_sans_body.currentFrameX = 0;
	_sans_body.currentFrameY = 0;
	_sans_body.rc = RectMakeCenter(_sans_body.x, _sans_body.y, _sans_body.width, _sans_body.hieght);

	_sans_legs.x = 290;
	_sans_legs.y = 170;
	_sans_legs.width = 52;
	_sans_legs.hieght = 23;
	_sans_legs.currentFrameX = 0;
	_sans_legs.currentFrameY = 0;
	_sans_legs.rc = RectMakeCenter(_sans_legs.x, _sans_legs.y, _sans_legs.width, _sans_legs.hieght);

	_sans_attack.x = 261;
	_sans_attack.y = 111;
	_sans_attack.width = 62;
	_sans_attack.hieght = 73;
	_sans_attack.currentFrameX = 0;
	_sans_attack.currentFrameY = 0;
	_sans_attack.rc = RectMake(_sans_attack.x, _sans_attack.y, _sans_attack.width, _sans_attack.hieght);

	_sans_head.img = ImageManager::GetInstance()->FindImage("»÷Áî_¸Ó¸®");
	_sans_sweat.img = ImageManager::GetInstance()->FindImage("»÷Áî_¶¡");
	_sans_body.img = ImageManager::GetInstance()->FindImage("»÷Áî_¸ö");
	_sans_legs.img = ImageManager::GetInstance()->FindImage("»÷Áî_´Ù¸®");
	_sans_attack.img = ImageManager::GetInstance()->FindImage("»÷Áî_¾Æ·¡°ø°Ý");

	//=============================°ø°Ý1========================================

	for (int i = 0; i < BONEMAX; i++)
	{
		_bone_20[i].x = 200 + i * 10;
		_bone_20[i].y = 350;
		_bone_20[i].width = 10;
		_bone_20[i].hieght = 20;
		_bone_20[i].rc = RectMakeCenter(_bone_20[i].x, _bone_20[i].y, _bone_20[i].width, _bone_20[i].hieght);

		_bone_20[i].img = ImageManager::GetInstance()->FindImage("»À´Ù±Í_20");
	}

	//==========================================================================
	_isattack = false;
	_isMove = false;
	_pattern = 0;

	return S_OK;
}

void sansBattle::release()
{
}

void sansBattle::update()
{
	//¸»Ç³¼± ´ë»ç Ä«¿îÆ® 4¶ó¸é
	if (_ui->get_bubble_talk_count() == 4)
	{
		_sans_head.currentFrameX = 5;
	}
	//°ÔÀÓ»óÅÂ°¡ ÀÎ°ÔÀÓ && ¹èÆ² ÅÏ Ä«¿îÆ®°¡ 0ÀÌ¸é
	if (_ui->getState() == INGAME && _ui->getBattle_turn() == 0)
	{
		_pattern = 1;
		_isattack = true;
		_sans_head.currentFrameX = 15;
		_ui->setEnemy_attackTime_max(500);
		_ui->main_rect_control_customizing(true, 20, 400, 150);


		if (!_isMove)
		{
			_sans_head.y += 0.2f;
			if (_sans_head.y >= 122) _isMove = true;
		}
		if (_isMove)
		{
			_sans_head.y -= 0.2f;
			if (_sans_head.y <= 119) _isMove = false;
		}
		updateAttack1(_pattern);

	}

	_sans_head.rc = RectMakeCenter(_sans_head.x, _sans_head.y, _sans_head.width, _sans_head.hieght);
	_sans_body.rc = RectMakeCenter(_sans_body.x, _sans_body.y, _sans_body.width, _sans_body.hieght);
	_sans_legs.rc = RectMakeCenter(_sans_legs.x, _sans_legs.y, _sans_legs.width, _sans_legs.hieght);
	_sans_attack.rc = RectMake(_sans_attack.x, _sans_attack.y, _sans_attack.width, _sans_attack.hieght);


	_ui->update();
}

void sansBattle::render()
{

	if (!_isattack)
	{
		_sans_body.img->bossFrameRender(_sans_body.rc.left, _sans_body.rc.top, _sans_body.currentFrameX, _sans_body.currentFrameY);
		/*_sans_body.img->autoFrameRender(_sans_body.rc.left, _sans_body.rc.top, 0,0);*/
		_sans_legs.img->bossFrameRender(_sans_legs.rc.left, _sans_legs.rc.top, _sans_legs.currentFrameX, _sans_legs.currentFrameY);
	}

	if (_isattack)
	{
		_sans_attack.img->autoFrameRender(_sans_attack.rc.left, _sans_attack.rc.top, 0, 0, 10, false);
	}
	_sans_head.img->bossFrameRender(_sans_head.rc.left, _sans_head.rc.top, _sans_head.currentFrameX, _sans_head.currentFrameY);

	if (_pattern == 1)
	{
		for (int i = 0; i < BONEMAX; i++)
		{
			_bone_20[i].img->Render(_bone_20[i].x, _bone_20[i].y);
		}
	}


	_ui->render();
}

void sansBattle::setAttack1(int pattern)
{
	if (pattern == 1)
	{
		for (int i = 0; i < BONEMAX; i++)
		{

		}
	}
}

void sansBattle::updateAttack1(int pattern)
{
	if (pattern == 1)
	{
		for (int i = 0; i < BONEMAX; i++)
		{
			_bone_20[i].x += 1.f;
			_bone_20[i].rc = RectMakeCenter(_bone_20[i].x, _bone_20[i].y, _bone_20[i].width, _bone_20[i].hieght);
		}
	}
}
