#include "stdafx.h"
#include "playGround.h"
#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")


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

	_backRc = RectMake(0, 0, WINSIZEX, WINSIZEY);
	_mfRc = RectMake(200, 200, 100, 100);
	ImageManager::GetInstance()->AddImage("TestObject", L"TrapObject.png");
	ImageManager::GetInstance()->AddFrameImage("TestFrameObject",
		L"Bomb.png", 3, 1);
	
	ImageManager::GetInstance()->AddImage("머펫", L"머펫이미지/idle.bmp");
	ImageManager::GetInstance()->AddImage("시작스테이지", L"스테이지이미지/start stage.png");

	_muffet = ImageManager::GetInstance()->FindImage("머펫");
	_backGround = ImageManager::GetInstance()->FindImage("시작스테이지");


	rc.x = WINSIZEX/2;
	rc.y = WINSIZEY/2;
	rc.rc = RectMake(rc.x,rc.y, 50, 50);

	angle = 0;
	an2 = 0;


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

	CAMERA->updateCamera(rc.x,rc.y, 0.5, 0.5);
	if (KEYMANAGER->isStayKeyDown(VK_LEFT)&&rc.x>0)
	{
		rc.x -= 5.0f;
	}
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT)&&rc.x<BACKGROUNDX)
	{
		rc.x += 5.0f;
	}
	if (KEYMANAGER->isStayKeyDown(VK_UP)&&rc.y>0)
	{
		rc.y -= 5.0f;
	}
	if (KEYMANAGER->isStayKeyDown(VK_DOWN)&&rc.y<BACKGROUNDY)
	{
		rc.y += 5.0f;
	}
	angle++;
	an2 += 2;
	//rcrc.SetLeftTopPos(5, 5);
	rc.rc = RectMakeCenter(rc.x, rc.y, 50, 50);
	cout << "================================" << endl;
	cout << rc.x <<"X"<< endl;
	cout << rc.y <<"Y"<< endl;
	cout << "================================" << endl;
}

//그리기 전용
void playGround::render()
{	
	Vector2 v(100, 100);
	Vector2	v2(500, 500);

	//백버퍼 초기화
	D2DRENDER->BeginRender(D2D1::ColorF::Black);
	
		
		_backGround->Render(0, 0,2.f,2.f);

		RECT rect;
		rect = RectMakeCenter(10, 10, 50, 50);
		
		D2DRENDER->DrawRectangle
		(
			rc.rc,
			D2DRenderer::DefaultBrush::Red,
			1.f
			//angle
		);
		
		
		//Image* image = ImageManager::GetInstance()->FindImage("TestObject");
		//
		//image->SetAngle(30.f);
		////알파는 0~1사이의 값으로 0은 안보이는거고 1은 반투명하지 않은
		//image->SetAlpha(0.5f);
		////image->SetSize(Vector2(100, 100));
		//image->Render(Vector2(WINSIZEX / 2, WINSIZEY / 2));
		
		Image* frameImage = ImageManager::GetInstance()->FindImage("TestFrameObject");
		
		frameImage->SetAlpha(0.3f);
		frameImage->FrameRender(Vector2(WINSIZEX / 2, WINSIZEY / 2), 0, 0);



	
	//백버퍼에 그린 내용들을 화면에 뿌려라~
	D2DRENDER->EndRender();
}
