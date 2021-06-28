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

	_un = new undyne;
	_un->init();
	

	//_stage2->init();

	cout << "삼" << endl;
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

	RECT temp;
	if (IntersectRect(&temp, &_pl->getRect(), &_un->getRect()))
		_pl->setBattlechk(true);

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
			
			sceneManager::getSingleton()->changeScene("stage2");
			_stage2->init();
			_pl->init();
		}
	}
	else if (sceneManager::getSingleton()->isCurrentScene("stage2")) _stage2->update();
	else if (sceneManager::getSingleton()->isCurrentScene("stage3")) _stage3->update();
	else if (sceneManager::getSingleton()->isCurrentScene("stage4")) _stage4->update();
	else if (sceneManager::getSingleton()->isCurrentScene("stage5")) _stage5->update();
	else if (sceneManager::getSingleton()->isCurrentScene("stage6")) _stage6->update();
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

