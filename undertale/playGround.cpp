#include "stdafx.h"
#include "playGround.h"

playGround::playGround()
{
}


playGround::~playGround()
{
}

//�ʱ�ȭ �Լ�
HRESULT playGround::init()
{
	gameNode::init(true);
	_player = new player;
	_player->init();

	_backRc = RectMake(0, 0, WINSIZEX, WINSIZEY);
	

	ImageManager::GetInstance()->AddImage("TestObject", L"TrapObject.png");
	ImageManager::GetInstance()->AddFrameImage("TestFrameObject",
		L"Bomb.png", 3, 1);
	
	ImageManager::GetInstance()->AddImage("���۽�������", L"���������̹���/start stage.png");
	_backGround = ImageManager::GetInstance()->FindImage("���۽�������");


	rc.x = 40;
	rc.y = 40;
	rc.rc = RectMakeCenter(rc.x,rc.y, 100, 100);

	angle = 0;
	an2 = 0;

	
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
	_player->update();

	
	rc.rc = RectMakeCenter(rc.x, rc.y, 100, 100);
	angle++;
	an2 += 2;


	//rcrc.SetLeftTopPos(5, 5);
}

//�׸��� ����
void playGround::render()
{	
	Vector2 v(100, 100);
	Vector2	v2(500, 500);

	//����� �ʱ�ȭ
	D2DRENDER->BeginRender(D2D1::ColorF::Black);
	{
		
		_backGround->Render(_backRc.left, _backRc.top, 2.f, 2.f);

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
		//D2D1_COLOR_F brushABC = { 1,0,1,1 }; �̷������� ����ص� ��
		D2DRENDERTARGET->CreateSolidColorBrush(brushColor, &brush);

		D2DRENDERTARGET->DrawLine
		(
			D2D1::Point2F(v.x,v.y),
			D2D1::Point2F(v2.x,v2.y),
			brush,
			1.f
		);
	
		brush->Release(); //������� ���ִ� ������ ���̺귯�������� ����°ű� ����
		//Image* image = ImageManager::GetInstance()->FindImage("TestObject");
		//
		//image->SetAngle(30.f);
		////���Ĵ� 0~1������ ������ 0�� �Ⱥ��̴°Ű� 1�� ���������� ����
		//image->SetAlpha(0.5f);
		////image->SetSize(Vector2(100, 100));
		//image->Render(Vector2(WINSIZEX / 2, WINSIZEY / 2));
		
		Image* frameImage = ImageManager::GetInstance()->FindImage("TestFrameObject");
		
		frameImage->SetAlpha(0.3f);
		frameImage->FrameRender(WINSIZEX / 2, WINSIZEY / 2, 0, 0);

		Vector2 t(200, 200);
		Vector2 t2(500, 500);

		LineMake(_hdc, t, t2, angle,200);

		_player->render();

		
	}
	//����ۿ� �׸� ������� ȭ�鿡 �ѷ���~
	D2DRENDER->EndRender();
}
