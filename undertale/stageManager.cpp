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

	//_stage2->init();

	cout << "삼" << endl;
	sceneManager::getSingleton()->addScene("stage1", new startStage);
	sceneManager::getSingleton()->addScene("stage2", new stage2);
	sceneManager::getSingleton()->addScene("stage3", new stage3);
	sceneManager::getSingleton()->addScene("stage4", new stage4);
	sceneManager::getSingleton()->addScene("stage5", new stage5);
	sceneManager::getSingleton()->addScene("stage6", new stage6);
	sceneManager::getSingleton()->addScene("stage7", new stage7);


	sceneManager::getSingleton()->changeScene("stage1");

	return S_OK;
}

void stageManager::release()
{
}

void stageManager::update()
{
	//테스트 용 스테이지 전환 ================================================
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
	/*if (_pl->getChangeScene())
	{
		sceneManager::getSingleton()->changeScene("stage3");
		_stage3->init();
		_pl->init();
	}*/
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


	if (sceneManager::getSingleton()->isCurrentScene("stage1"))
	{
		_stage1->update();

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
			_pl->release();

			sceneManager::getSingleton()->changeScene("stage4");
			exit = false;
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
			_pl->init();
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
			_pl->init(exit);
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

	if (sceneManager::getSingleton()->isCurrentScene("stage1")) _stage1->update();
	else if (sceneManager::getSingleton()->isCurrentScene("stage2")) _stage2->update();
	else if (sceneManager::getSingleton()->isCurrentScene("stage3")) _stage3->update();
	else if (sceneManager::getSingleton()->isCurrentScene("stage4")) _stage4->update();
	else if (sceneManager::getSingleton()->isCurrentScene("stage5")) _stage5->update();
	else if (sceneManager::getSingleton()->isCurrentScene("stage6")) _stage6->update();
	else if (sceneManager::getSingleton()->isCurrentScene("stage7")) _stage7->update();

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
}
