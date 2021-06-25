#include "stdafx.h"
#include "stageManager.h"

HRESULT stageManager::init()
{
	
	_stage1 = new startStage;
	_stage1->init();
	_stage2 = new stage2;
	//_stage2->init();
	_undybattle = new undybattle;

	sceneManager::getSingleton()->addScene("stage1", new startStage);
	sceneManager::getSingleton()->addScene("stage2", new stage2);
	sceneManager::getSingleton()->addScene("undbattle", new undybattle);


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
	}
	//=======================================================================


	if (sceneManager::getSingleton()->isCurrentScene("stage1")) _stage1->update();
	else if (sceneManager::getSingleton()->isCurrentScene("stage2")) _stage2->update();
	else if (sceneManager::getSingleton()->isCurrentScene("undbattle")) _undybattle->update();

}

void stageManager::render()
{
	if (sceneManager::getSingleton()->isCurrentScene("stage1")) _stage1->render();
	else if (sceneManager::getSingleton()->isCurrentScene("stage2")) _stage2->render();
	else if (sceneManager::getSingleton()->isCurrentScene("undbattle")) _undybattle->render();

}
