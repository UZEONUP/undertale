#include "stdafx.h"
#include "stageManager.h"
#include "player.h"

HRESULT stageManager::init()
{
	_title = new title;
	_title->init();
	_stage1 = new startStage;
	_stage2 = new stage2;
	_stage3 = new stage3;
	_stage4 = new stage4;
	_stage5 = new stage5;
	_stage6 = new stage6;
	_stage7 = new stage7;
	_undybattle = new undybattle;


	_pl = new player;
	_pl->init();
	this->linkPlayer(_pl);
	_pl->linkStageManager(this);

	/*_un = new undyne;
	_un->init();*/
	
	exit = false;
	returnStage3 = false;

	//_stage2->init();

	cout << "삼" << endl;
	sceneManager::getSingleton()->addScene("title", new title);
	sceneManager::getSingleton()->addScene("stage1", new startStage);
	sceneManager::getSingleton()->addScene("stage2", new stage2);
	sceneManager::getSingleton()->addScene("stage3", new stage3);
	sceneManager::getSingleton()->addScene("stage4", new stage4);
	sceneManager::getSingleton()->addScene("stage5", new stage5);
	sceneManager::getSingleton()->addScene("stage6", new stage6);
	sceneManager::getSingleton()->addScene("stage7", new stage7);
	sceneManager::getSingleton()->addScene("undybattle", new undybattle);

	sceneManager::getSingleton()->changeScene("title");

	return S_OK;
}

void stageManager::release()
{
}

void stageManager::update()
{
	
	if (keyManager::getSingleton()->isOnceKeyDown(VK_F8))
	{
		sceneManager::getSingleton()->changeScene("undybattle");
		_undybattle->init();
	}

	float x = _pl->getX();
	float y = _pl->getY();
	float angle;

	/*RECT temp;
	if (IntersectRect(&temp, &_pl->getRect(), &_un->getRect()))
		_pl->setBattlechk(true);*/

	if (_pl->getBattlechk())
	{
		_pl->setHeart(x, y);
	}
	//=======================================================================

	if (sceneManager::getSingleton()->isCurrentScene("title"))
	{
		_title->update();
		if (keyManager::getSingleton()->isOnceKeyDown('Z'))
		{
			_title->release();
			_pl->release();

			sceneManager::getSingleton()->changeScene("stage1");
			_stage1->init();
			_pl->init();
		}
	}
	if (sceneManager::getSingleton()->isCurrentScene("stage1"))
	{
		_stage1->update();

		linkStageRect(_stage1->getStageRect());

		if (sceneRect(_stage1->getSceneRect()))
		{
			_stage1->release();
			_pl->release();

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
			_pl->release();
			returnStage3 = true;
			sceneManager::getSingleton()->changeScene("stage3");
			_pl->init(1, returnStage3);
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
			_pl->release();

			sceneManager::getSingleton()->changeScene("stage4");
			exit = false;
			returnStage3 = false;
			_pl->init();
			_stage4->init();
		}
		else if (sceneRect(_stage3->getSceneRect2()))
		{
			_stage3->release();
			_pl->release();

			sceneManager::getSingleton()->changeScene("stage6");
			_pl->init();
			_stage6->init();
		}
	}
	else if (sceneManager::getSingleton()->isCurrentScene("stage4"))
	{
		_stage4->update();

		linkStageRect(_stage4->getStageRect());

		if (sceneRect(_stage4->getSceneRect()))
		{
			_stage4->release();
			_pl->release();

			sceneManager::getSingleton()->changeScene("stage5");
			_pl->init();
			_stage5->init();
		}
		else if (sceneRect(_stage4->getSceneRect2()))
		{
			_stage4->release();
			_pl->release();

			sceneManager::getSingleton()->changeScene("stage3");
			returnStage3 = false;
			_pl->init(1,returnStage3);
			_stage3->init();
		}
	}
	else if (sceneManager::getSingleton()->isCurrentScene("stage5"))
	{
		_stage5->update();

		if (KEYMANAGER->isOnceKeyDown('X'))
		{
			_stage5->release();
			_pl->release();

			sceneManager::getSingleton()->changeScene("stage4");
			exit = true;
			_pl->init(2,exit);
			_stage4->init();
		}
	}
	else if (sceneManager::getSingleton()->isCurrentScene("stage6"))
	{
		_stage6->update();

		linkStageRect(_stage6->getStageRect());

		if (sceneRect(_stage6->getSceneRect()))
		{
			_stage6->release();
			_pl->release();

			sceneManager::getSingleton()->changeScene("stage7");
			_pl->init();
			_stage7->init();
		}

	}
	else if (sceneManager::getSingleton()->isCurrentScene("stage7"))
	{
		_stage7->update();

		linkStageRect(_stage7->getStageRect());

	}
	else if (sceneManager::getSingleton()->isCurrentScene("undybattle")) _undybattle->update();

	
	_pl->update();

	if (_stageRect != nullptr) _stageRect->update();
	if (!sceneManager::getSingleton()->isCurrentScene("title") &&
		!sceneManager::getSingleton()->isCurrentScene("undybattle"))
	{
		collision();
	}
}

void stageManager::render()
{
	if (sceneManager::getSingleton()->isCurrentScene("title")) _title->render();
	else if (sceneManager::getSingleton()->isCurrentScene("stage1")) _stage1->render();
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

			//수직 수평
			(width > height) ? _pt = false : _pt = true;

			if (_pt) // 수평
			{
				//왼쪽에 있나
				if (plRc.left < groundRect.left) _pl->setPlayerX(playerX -= width);
				//오른쪽에 있나
				if (plRc.right > groundRect.right) _pl->setPlayerX(playerX += width);
			}
			else if (!_pt) //수직
			{
				//위에 있나
				if (plRc.top < groundRect.top) _pl->setPlayerY(playerY -= height);
				//아래에 있나
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

