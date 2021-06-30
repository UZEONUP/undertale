#include "stdafx.h"
#include "saveLoadManager.h"
#include "player.h"

saveLoadManager::saveLoadManager()
{
}

saveLoadManager::~saveLoadManager()
{
}

HRESULT saveLoadManager::init()
{
    return E_NOTIMPL;
}

void saveLoadManager::release()
{
}

void saveLoadManager::update()
{
	save();
	load();
}

void saveLoadManager::render()
{
}

void saveLoadManager::save()
{
	if (KEYMANAGER->isOnceKeyDown('O'))
	{
		char playerHP[128];
		char playerX[128];
		char playerY[128];
		char playerMove[128];

		string sceneName;
		int decX, signX;
		int decY, signY;

		/*
		_fcvt_s(����,sizeof,value,count,dec,sign)
		 @@����
		 ��ȯ ����� ������ ������ �����Դϴ�.
		 sizeInBytes
		 @@���� ũ��(����Ʈ)�Դϴ�.
		 value
		 @@��ȯ�� �����Դϴ�.
		 count
		 @@�Ҽ��� ���� �ڸ����Դϴ�.
		 dec
		 @@����� �Ҽ��� ��ġ�� �������Դϴ�.
		 sign
		 @@����� ��ȣ ǥ�ñ��� �������Դϴ�.

		playerX[64] = _fcvt_s(playerX,sizeof(playerX),_pl->getX(),2,&decX,&signX);
		playerY[64] = _fcvt_s(playerY,sizeof(playerY),_pl->getY(),2,&decY,&signY);

		 */
		sceneName = SCENEMANAGER->getSceneName();
		cout << sceneName << endl;

		playerHP[64] = _itoa_s(_player->getHP(), playerHP, sizeof(playerHP), 10);
		playerX[64] = _itoa_s(_player->getX(), playerX, sizeof(playerX), 10);
		playerY[64] = _itoa_s(_player->getY(), playerY, sizeof(playerY), 10);
		playerMove[64] = _itoa_s(_player->getMoveStop(), playerMove, sizeof(playerMove), 10);

		INIDATA->addData("�÷��̾�", "HP", playerHP);
		INIDATA->addData("�÷��̾�", "x", playerX);
		INIDATA->addData("�÷��̾�", "y", playerY);
		INIDATA->addData("�÷��̾�", "move", playerMove);
		INIDATA->addData("��������", "�̸�", sceneName.c_str());

		INIDATA->iniSave("������");
		int HP = INIDATA->loadDataInt("������", "�÷��̾�", "HP");
		float X = INIDATA->loadDataInt("������", "�÷��̾�", "x");
		float Y = INIDATA->loadDataInt("������", "�÷��̾�", "y");
		int move = INIDATA->loadDataInt("������", "�÷��̾�", "move");
		string name = INIDATA->loadDataStr("������", "��������", "�̸�");

		cout << HP << " : HP " << endl;
		cout << X << " : X " << endl;
		cout << Y << " : Y " << endl;
		cout << move << " : moveStop " << endl;
		cout << name << endl;
		cout << "���̺� �Ϸ�" << endl;
	}
	
}

void saveLoadManager::load()
{
	if (KEYMANAGER->isOnceKeyDown('P'))
	{
		int HP = INIDATA->loadDataInt("������", "�÷��̾�", "HP");
		float X = INIDATA->loadDataInt("������", "�÷��̾�", "x");
		float Y = INIDATA->loadDataInt("������", "�÷��̾�", "y");
		int move = INIDATA->loadDataInt("������", "�÷��̾�", "move");
		string name = INIDATA->loadDataStr("������", "��������", "�̸�");

		cout << HP << " : HP " << endl;
		cout << X << " : X " << endl;
		cout << Y << " : Y " << endl;
		cout << move << " : moveStop " << endl;
		cout << name << endl;

		sceneSet();

		_player->setPlayerX(X);
		_player->setPlayerY(Y);
		_player->setMoveStop(move);

		//��������

		
		cout<< "�ε� �Ϸ�" << endl;
	}
}

void saveLoadManager::sceneSet()
{
	string sceneName = INIDATA->loadDataStr("������", "��������", "�̸�");

	SCENEMANAGER->changeScene(sceneName);
}
