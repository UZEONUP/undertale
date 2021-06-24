#include "stdafx.h"
#include "playGround.h"

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


	rc.x = 40;
	rc.y = 40;
	rc.rc = RectMakeCenter(rc.x,rc.y, 100, 100);

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
	

	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		rc.x -= 5.0f;
	}
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		rc.x += 5.0f;
	}
	if (KEYMANAGER->isStayKeyDown(VK_UP))
	{
		rc.y -= 5.0f;
	}
	if (KEYMANAGER->isStayKeyDown(VK_DOWN))
	{
		rc.y += 5.0f;
	}
	rc.rc = RectMakeCenter(rc.x, rc.y, 100, 100);
	angle++;
	an2 += 2;
	//rcrc.SetLeftTopPos(5, 5);
}

//그리기 전용
void playGround::render()
{	
	
	Vector2 v(100, 100);
	Vector2	v2(500, 500);

	//백버퍼 초기화
	D2DRENDER->BeginRender(D2D1::ColorF::Black);
	{
		
		_backGround->Render(_backRc.left, _backRc.top, 1, 1, 45.f, 0, 0, 0, 0);

		RECT rect;
		rect = RectMakeCenter(10, 10, 100, 100);
		
		D2DRENDER->DrawRectangle
		(
			rc.rc,
			D2DRenderer::DefaultBrush::Red,
			1.f
			//angle
		);
		
		D2DRENDER->FillRectangle
		(
			rect,
			D2DRenderer::DefaultBrush::Red
			//an2
		);
		ID2D1SolidColorBrush* brush = nullptr;
		D2D1_COLOR_F brushColor = { 1, 0, 1, 1 };
		//D2D1_COLOR_F brushABC = { 1,0,1,1 }; 이런식으로 사용해도 됨
		D2DRENDERTARGET->CreateSolidColorBrush(brushColor, &brush);

		D2DRENDERTARGET->DrawLine
		(
			D2D1::Point2F(v.x,v.y),
			D2D1::Point2F(v2.x,v2.y),
			brush,
			1.f
		);
	
		brush->Release(); //릴리즈로 해주는 이유는 라이브러리생성을 지우는거기 때문
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

		Vector2 t(200, 200);
		Vector2 t2(500, 500);
		
		//LineMake(_hdc, t, t2, angle,200);
	}
	//백버퍼에 그린 내용들을 화면에 뿌려라~
	D2DRENDER->EndRender();
}
