#include "stdafx.h"
#include "stageManager.h"
#include "player.h"

HRESULT stageManager::init()
{
	
	_stage1 = new startStage;
	_stage1->init();
	_stage2 = new stage2;
	_stage3 = new stage3;
	_stage4 = new stage4;
	_stage5 = new stage5;
	_stage6 = new stage6;
	_stage7 = new stage7;
	_undybattle = new undybattle;

	linkStageRect(_stage1->getStageRect());

	_pl = new player;
	_pl->init();
	this->linkPlayer(_pl);
	_pl->linkStageManager(this);

	//_stage2->init();

	cout << "��" << endl;
	sceneManager::getSingleton()->addScene("stage1", new startStage);
	sceneManager::getSingleton()->addScene("stage2", new stage2);
	sceneManager::getSingleton()->addScene("stage3", new stage3);
	sceneManager::getSingleton()->addScene("stage4", new stage4);
	sceneManager::getSingleton()->addScene("stage5", new stage5);
	sceneManager::getSingleton()->addScene("stage6", new stage6);
	sceneManager::getSingleton()->addScene("stage7", new stage7);
	sceneManager::getSingleton()->addScene("undybattle", new undybattle);

	sceneManager::getSingleton()->changeScene("stage1");

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
		_stage1->release();
		sceneManager::getSingleton()->changeScene("stage2");
		_stage2->init();
		_pl->init();
	}
	if (keyManager::getSingleton()->isOnceKeyDown(VK_F3))
	{
		sceneManager::getSingleton()->changeScene("stage3");
		_stage3->init();
		_pl->init();
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
		sceneManager::getSingleton()->changeScene("undybattle");
		_undybattle->init();
	}
	//=======================================================================


	if (sceneManager::getSingleton()->isCurrentScene("stage1"))
	{
		_stage1->update();

		if (sceneRect(_stage1->getSceneRect()))
		{
			_stage1->release();
			sceneManager::getSingleton()->changeScene("stage2");
			_stage2->init();
			_pl->init();
		}
	}
	else if (sceneManager::getSingleton()->isCurrentScene("stage2"))
	{
		_stage2->update();

		linkStageRect(_stage2->getStageRect());

		if (sceneRect(_stage2->getSceneRect()))
		{
			_stage2->release();
			sceneManager::getSingleton()->changeScene("stage3");
			_pl->init();
			_stage3->init();
		}
	}
	else if (sceneManager::getSingleton()->isCurrentScene("stage3"))
	{
		_stage3->update();

		linkStageRect(_stage3->getStageRect());

		if (sceneRect(_stage3->getSceneRect()))
		{
			_stage3->release();
			sceneManager::getSingleton()->changeScene("stage4");
			_pl->init();
			_stage4->init();
		}
	}
	else if (sceneManager::getSingleton()->isCurrentScene("stage4"))
	{
		_stage4->update();

		linkStageRect(_stage4->getStageRect());

		if (sceneRect(_stage4->getSceneRect()))
		{
			_stage4->release();
			sceneManager::getSingleton()->changeScene("stage5");
			_pl->init();
			_stage5->init();
		}
		else if (sceneRect(_stage4->getSceneRect2()))
		{
			_stage4->release();
			sceneManager::getSingleton()->changeScene("stage6");
			_pl->init();
			_stage6->init();
		}
	}
	else if (sceneManager::getSingleton()->isCurrentScene("stage5"))
	{
		_stage5->update();

		if (KEYMANAGER->isOnceKeyDown('X'))
		{
			_stage5->release();
			sceneManager::getSingleton()->changeScene("stage4");
			_pl->init();
			_stage4->init();
		}
	}
	else if (sceneManager::getSingleton()->isCurrentScene("stage6"))
	{
		_stage6->update();
	}
	else if (sceneManager::getSingleton()->isCurrentScene("stage7")) _stage7->update();
	else if (sceneManager::getSingleton()->isCurrentScene("undybattle")) _undybattle->update();

	_pl->update();

	if (_stageRect != nullptr) _stageRect->update();
	collision();
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
	else if (sceneManager::getSingleton()->isCurrentScene("undybattle")) _undybattle->render();
	_pl->render();
}

void stageManager::collision()
{
	RECT temp;

	RECT plRc = _pl->getBRect();


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

bool stageManager::sceneRect(RECT sceneRect)
{
	RECT t;

	if (IntersectRect(&t, &sceneRect, &_pl->getRect()))
	{
		return true;
	}
	else return false;
}

