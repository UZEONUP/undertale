#include "stdafx.h"
#include "camera.h"

HRESULT camera::init()
{
	return S_OK;
}

void camera::release()
{
}

void camera::update()
{
}

void camera::render()
{
}

void camera::setCamera(float x, float y)
{
}

void camera::updateCamera(RECT & player, float ratioX, float ratioY)
{
	float x = (player.left + player.right) / 2;
	float y = (player.top+ player.bottom) / 2;

	//���� ��
	if (player.left - (WINSIZEX * ratioX) <= 0)player.left = 0;
	else if (player.right +( WINSIZEX * ratioX) >= BACKGROUNDX)player.left = BACKGROUNDX - WINSIZEX;
	else player.left -= (WINSIZEX * ratioX);
	//���� ��
	if (player.top - (WINSIZEY * ratioY) <= 0)player.top = 0;
	else if (player.top + (WINSIZEY * ratioY) >= BACKGROUNDY)player.top = BACKGROUNDY - WINSIZEY;
	else player.top -= (WINSIZEY * ratioY);

	player = RectMakeCenter(x,y, 50, 50);

	D2DRENDERTARGET->SetTransform(D2D1::Matrix3x2F::Translation(player.left, player.top));
}

void camera::updateCamera(float x, float y, float ratioX, float ratioY)
{
	//���� ��
	if (x - (WINSIZEX * ratioX) <= 0)x = 0;										//��׶��� ����Ʈ���� �Ѿ��
	else if (x + (WINSIZEX * ratioX) >= BACKGROUNDX)x = BACKGROUNDX - WINSIZEX; // ��׶��� ����Ʈ ���� �Ѿ��
	else x -= (WINSIZEX * ratioX);												// �׿�
	//���� ��
	if (y - (WINSIZEY * ratioY) <= 0)y = 0;
	else if (y + (WINSIZEY * ratioY) >= BACKGROUNDY)y = BACKGROUNDY - WINSIZEY;
	else y -= (WINSIZEY * ratioY);

	D2DRENDERTARGET->SetTransform(D2D1::Matrix3x2F::Translation(-x, -y));
}