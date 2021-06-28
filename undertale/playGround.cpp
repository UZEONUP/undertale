#include "stdafx.h"
#include "playGround.h"

#pragma comment(linker,"/entry:WinMainCRTStartup /subsystem:console")


playGround::playGround()
{
	//dkfja;sdjfkdsa;kfjs;
}


playGround::~playGround()
{
}

//�ʱ�ȭ �Լ�
HRESULT playGround::init()
{
	gameNode::init(true);

	_sm = new stageManager;
	_sm->init();
	_player = new player;
	_player->init();


	//===========��ȣ������ ��ũ
	_sm->linkPlayer(_player);
	_player->linkStageManager(_sm);
	//==========================


	return S_OK;
}

//�޸� ����
void playGround::release()
{
}

//����
void playGround::update()
{
	gameNode::update();

	_sm->update();
	_player->update();

	CAMERAMANAGER->update();

}

//�׸��� ����
void playGround::render()
{

	//����� �ʱ�ȭ
	D2DRENDER->BeginRender(D2D1::ColorF::Black);

	_sm->render();
	_player->render();

	CAMERAMANAGER->render();

	//����ۿ� �׸� ������� ȭ�鿡 �ѷ���~
	D2DRENDER->EndRender();
}
