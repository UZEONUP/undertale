#include "stdafx.h"
#include "sans_state.h"
#include "sansBattle.h"

void sans_state::heart_control(sansBattle* sansBattle)
{
	//하트 이동
	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		sansBattle->getUI()->set_inGame_heart_x(sansBattle->getUI()->getIGH().x - 3);
	}
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		sansBattle->getUI()->set_inGame_heart_x(sansBattle->getUI()->getIGH().x + 3);
	}
	if (KEYMANAGER->isStayKeyDown(VK_UP))
	{
		sansBattle->getUI()->set_inGame_heart_y(sansBattle->getUI()->getIGH().y - 5);
	}
	if (KEYMANAGER->isStayKeyDown(VK_DOWN))
	{
		sansBattle->getUI()->set_inGame_heart_y(sansBattle->getUI()->getIGH().y + 3);
	}
	//중력 값
	else sansBattle->getUI()->set_inGame_heart_y(sansBattle->getUI()->getIGH().y + _gravity);
	

	//예외처리
	if (sansBattle->getUI()->get_main_rect().left + 12 >= sansBattle->getUI()->getIGH().x)
	{
		sansBattle->getUI()->set_inGame_heart_x(sansBattle->getUI()->get_main_rect().left + 12);
	}
	if (sansBattle->getUI()->get_main_rect().right - 12 <= sansBattle->getUI()->getIGH().x)
	{
		sansBattle->getUI()->set_inGame_heart_x(sansBattle->getUI()->get_main_rect().right - 12);
	}
	if (sansBattle->getUI()->get_main_rect().top + 12 >= sansBattle->getUI()->getIGH().y)
	{
		sansBattle->getUI()->set_inGame_heart_y(sansBattle->getUI()->get_main_rect().top + 12);
	}
	if (sansBattle->getUI()->get_main_rect().bottom - 12 <= sansBattle->getUI()->getIGH().y)
	{
		sansBattle->getUI()->set_inGame_heart_y(sansBattle->getUI()->get_main_rect().bottom - 12);
	}



}
