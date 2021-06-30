#include "stdafx.h"
#include "sans_state_attack1.h"

sans_state * sans_state_attack1::inputHandle(sansBattle * sansBattle)
{
	if (sansBattle->getUI()->getState() != INGAME)
	{
		return new sans_state_idle();
	}
	return nullptr;
}

void sans_state_attack1::enter(sansBattle * sansBattle)
{
	sansBattle->getObject()._pattern = 1;
	sansBattle->getObject()._isattack = true;
	sansBattle->getUI()->setEnemy_attackTime_max(300);
	_bone_speed = 2.5f;
	for (int i = 0; i < BONEMAX / 2; i++)
	{
		_bone_20[i].x = i * 100 - 800;
		_bone_20[i].y = 370;
		_bone_20[i].width = 10;
		_bone_20[i].hieght = 20;
		_bone_20[i].rc = RectMakeCenter(_bone_20[i].x, _bone_20[i].y, _bone_20[i].width, _bone_20[i].hieght);

		_bone_20[i].img = ImageManager::GetInstance()->FindImage("»À´Ù±Í_20");

		_bone_100[i].x = i * 100 - 800;
		_bone_100[i].y = 230;
		_bone_100[i].width = 10;
		_bone_100[i].hieght = 100;
		_bone_100[i].rc = RectMakeCenter(_bone_100[i].x, _bone_100[i].y, _bone_100[i].width, _bone_100[i].hieght);

		_bone_100[i].img = ImageManager::GetInstance()->FindImage("»À´Ù±Í_100");

		_bone_20[i + BONEMAX / 2].x = (i + BONEMAX / 2) * 100 - 200;
		_bone_20[i + BONEMAX / 2].y = 370;
		_bone_20[i + BONEMAX / 2].width = 10;
		_bone_20[i + BONEMAX / 2].hieght = 20;
		_bone_20[i + BONEMAX / 2].rc = RectMakeCenter(_bone_20[i + BONEMAX / 2].x, _bone_20[i + BONEMAX / 2].y, _bone_20[i + BONEMAX / 2].width, _bone_20[i + BONEMAX / 2].hieght);

		_bone_20[i + BONEMAX / 2].img = ImageManager::GetInstance()->FindImage("»À´Ù±Í_20");

		_bone_100[i + BONEMAX / 2].x = (i + BONEMAX / 2) * 100 - 200;
		_bone_100[i + BONEMAX / 2].y = 230;
		_bone_100[i + BONEMAX / 2].width = 10;
		_bone_100[i + BONEMAX / 2].hieght = 100;
		_bone_100[i + BONEMAX / 2].rc = RectMakeCenter(_bone_100[i + BONEMAX / 2].x, _bone_100[i + BONEMAX / 2].y, _bone_100[i + BONEMAX / 2].width, _bone_100[i + BONEMAX / 2].hieght);

		_bone_100[i + BONEMAX / 2].img = ImageManager::GetInstance()->FindImage("»À´Ù±Í_100");
	}

}

void sans_state_attack1::update(sansBattle * sansBattle)
{
	sansBattle->getUI()->main_rect_control_customizing(true, 20, 400, 170);

	for (int i = 0; i < BONEMAX / 2; i++)
	{
		_bone_20[i].x += _bone_speed;
		_bone_20[i].rc = RectMakeCenter(_bone_20[i].x, _bone_20[i].y, _bone_20[i].width, _bone_20[i].hieght);
		_bone_100[i].x += _bone_speed;
		_bone_100[i].rc = RectMakeCenter(_bone_100[i].x, _bone_100[i].y, _bone_100[i].width, _bone_100[i].hieght);
		_bone_20[i + BONEMAX / 2].x -= _bone_speed;
		_bone_20[i + BONEMAX / 2].rc = RectMakeCenter(_bone_20[i + BONEMAX / 2].x, _bone_20[i + BONEMAX / 2].y, _bone_20[i + BONEMAX / 2].width, _bone_20[i + BONEMAX / 2].hieght);
		_bone_100[i + BONEMAX / 2].x -= _bone_speed;
		_bone_100[i + BONEMAX / 2].rc = RectMakeCenter(_bone_100[i + BONEMAX / 2].x, _bone_100[i + BONEMAX / 2].y, _bone_100[i + BONEMAX / 2].width, _bone_100[i + BONEMAX / 2].hieght);
	}
}

void sans_state_attack1::render(sansBattle * sansBattle)
{
	for (int i = 0; i < BONEMAX / 2; i++)
	{
		_bone_20[i].img->Render(_bone_20[i].x - _bone_20[i].width / 2, _bone_20[i].y - _bone_20[i].hieght / 2);
		_bone_100[i].img->Render(_bone_100[i].x - _bone_100[i].width / 2, _bone_100[i].y - _bone_20[i].hieght / 2);
		_bone_20[i + BONEMAX / 2].img->Render(_bone_20[i + BONEMAX / 2].x - _bone_20[i + BONEMAX / 2].width / 2, _bone_20[i + BONEMAX / 2].y - _bone_20[i + BONEMAX / 2].hieght / 2);
		_bone_100[i + BONEMAX / 2].img->Render(_bone_100[i + BONEMAX / 2].x - _bone_20[i + BONEMAX / 2].width / 2, _bone_100[i + BONEMAX / 2].y - _bone_20[i].hieght / 2);

		D2DRENDER->DrawRectangle
		(
			_bone_20[i].rc,
			D2DRenderer::DefaultBrush::White,
			5.F
		);
	}
}

void sans_state_attack1::exit(sansBattle * sansBattle)
{
}
