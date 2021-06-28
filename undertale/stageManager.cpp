#include "stdafx.h"
#include "stageManager.h"

HRESULT stageManager::init()
{
	_stage1 = new startStage;
	_stage1->init();
	linkStageRect(_stage1->getStageRect());

	_stage2 = new stage2;
	_stage3 = new stage3;
	_stage4 = new stage4;
	_stage5 = new stage5;
	_stage6 = new stage6;
	_stage7 = new stage7;
	_undyb = new undybattle;
	//_stage2->init();
	//_stageRect->init();

	sceneManager::getSingleton()->addScene("stage1", new startStage);
	sceneManager::getSingleton()->addScene("stage2", new stage2);
	sceneManager::getSingleton()->addScene("stage3", new stage3);
	sceneManager::getSingleton()->addScene("stage4", new stage4);
	sceneManager::getSingleton()->addScene("stage5", new stage5);
	sceneManager::getSingleton()->addScene("stage6", new stage6);
	sceneManager::getSingleton()->addScene("stage7", new stage7);
	sceneManager::getSingleton()->addScene("undyb", new undybattle);

	sceneManager::getSingleton()->changeScene("stage1");
	cout << "����" << endl;
	return S_OK;
}

void stageManager::release()
{
}

void stageManager::update()
{
	//�׽�Ʈ �� �������� ��ȯ ================================================
	if (keyManager::getSingleton()->isOnceKeyDown(VK_F2))
	{
		sceneManager::getSingleton()->changeScene("stage2");
		_stage2->init();
	}
	if (keyManager::getSingleton()->isOnceKeyDown(VK_F3))
	{
		sceneManager::getSingleton()->changeScene("stage3");
		_stage3->init();
	}
	if (keyManager::getSingleton()->isOnceKeyDown(VK_F4))
	{
		sceneManager::getSingleton()->changeScene("stage4");
		_stage4->init();
	}
	if (keyManager::getSingleton()->isOnceKeyDown(VK_F5))
	{
		sceneManager::getSingleton()->changeScene("stage5");
		_stage5->init();
	}
	if (keyManager::getSingleton()->isOnceKeyDown(VK_F6))
	{
		sceneManager::getSingleton()->changeScene("stage6");
		_stage6->init();
	}
	if (keyManager::getSingleton()->isOnceKeyDown(VK_F7))
	{
		sceneManager::getSingleton()->changeScene("stage7");
		_stage7->init();
	}

	if (keyManager::getSingleton()->isOnceKeyDown(VK_F8))
	{
		sceneManager::getSingleton()->changeScene("undyb");
		_undyb->init();
	}
	//=======================================================================


	if (sceneManager::getSingleton()->isCurrentScene("stage1")) _stage1->update();
	else if (sceneManager::getSingleton()->isCurrentScene("stage2")) _stage2->update();
	else if (sceneManager::getSingleton()->isCurrentScene("stage3")) _stage3->update();
	else if (sceneManager::getSingleton()->isCurrentScene("stage4")) _stage4->update();
	else if (sceneManager::getSingleton()->isCurrentScene("stage5")) _stage5->update();
	else if (sceneManager::getSingleton()->isCurrentScene("stage6")) _stage6->update();
	else if (sceneManager::getSingleton()->isCurrentScene("stage7")) _stage7->update();
	else if (sceneManager::getSingleton()->isCurrentScene("undyb")) _undyb->update();

	if (_stageRect != nullptr) _stageRect->update();
	collision();
	cout << "������Ʈ" << endl;
}

void stageManager::render()
{
	if (sceneManager::getSingleton()->isCurrentScene("stage1")) _stage1->render();
	else if (sceneManager::getSingleton()->isCurrentScene("stage2")) _stage2->render();
	else if (sceneManager::getSingleton()->isCurrentScene("stage3")) _stage3->render();
	else if (sceneManager::getSingleton()->isCurrentScene("stage4")) _stage4->render();
	else if (sceneManager::getSingleton()->isCurrentScene("stage5")) _stage5->render();
	else if (sceneManager::getSingleton()->isCurrentScene("stage6")) _stage6->render();
	else if (sceneManager::getSingleton()->isCurrentScene("stage7")) _stage7->render();
	else if (sceneManager::getSingleton()->isCurrentScene("undyb")) _undyb->render();
}

void stageManager::collision()
{
	RECT temp;

	RECT plRc = _pl->getRect();


	for (int i = 0; i < _stageRect->getvGround().size(); i++)
	{
		RECT groundRect = _stageRect->getvGround()[i].rc;

		if (IntersectRect(&temp, &plRc, &groundRect))
		{
			float width = (temp.right - temp.left);
			float height = (temp.bottom - temp.top);

			float playerX = _pl->getX();
			float playerY = _pl->getY();

			bool _pt;

			//���� ����
			(width > height) ? _pt = false : _pt = true;

			if (_pt) // ����
			{
				//���ʿ� �ֳ�
				if (plRc.left < groundRect.left) _pl->setPlayerX(playerX -= width);
				//�����ʿ� �ֳ�
				if (plRc.right > groundRect.right) _pl->setPlayerX(playerX += width);
			}
			else if (!_pt) //����
			{
				//���� �ֳ�
				if (plRc.top < groundRect.top) _pl->setPlayerY(playerY -= height);
				//�Ʒ��� �ֳ�
				if (plRc.bottom > groundRect.bottom) _pl->setPlayerY(playerY += height);
			}
		}
	}
}
