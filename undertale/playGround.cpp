#include "stdafx.h"
#include "playGround.h"

#pragma comment(linker,"/entry:WinMainCRTStartup /subsystem:console")


playGround::playGround()
{
	
}


playGround::~playGround()
{
}

//초기화 함수
HRESULT playGround::init()
{
	gameNode::init(true);
	/*_ts = new testScene;
	_ts->init();*/

	//ImageManager::GetInstance()->AddFrameImage("face1", L"asriel/asriel_face1_5x1.png", 5, 1);
	// _face.x = WINSIZEX / 2;
	// _face.y = WINSIZEY / 2;
	// _face.rc = RectMakeCenter(_face.x, _face.y, 80, 100);
	// _face.img = ImageManager::GetInstance()->FindImage("face1");
	// _face.currentFrameX = _face.currentFrameY = 0;
	// _face.count = 0;

	_sm = new stageManager;
	_sm->init();

	//===========상호참조용 링크


	//==========================

	return S_OK;
}

//메모리 해제
void playGround::release()
{
}

//연산
void playGround::update()
{
	gameNode::update();

	//_ts->update();
	_sm->update();
	/*
	if(_face.count++%10==0)	_face.currentFrameX++;

	if (_face.currentFrameX >= 5)_face.currentFrameX = 0;*/

	CAMERAMANAGER->update();
	CAMERAMANAGER->mousePoint();
}

//그리기 전용
void playGround::render()
{
	//백버퍼 초기화
	D2DRENDER->BeginRender(D2D1::ColorF::Black);

	//_ts->render();
	_sm->render();

	//_face.img->autoFrameRender(WINSIZEX / 2, WINSIZEY / 2, _face.currentFrameX, _face.currentFrameY,25,false);

	CAMERAMANAGER->render();

	//백버퍼에 그린 내용들을 화면에 뿌려라~
	D2DRENDER->EndRender();
}
