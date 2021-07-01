#include "stdafx.h"
#include "stageManager.h"
#include "player.h"

HRESULT stageManager::init()
{
	sceneSet();


	return S_OK;
}

void stageManager::release()
{
}

void stageManager::update()
{
	SCENEMANAGER->update();
	SAVELOADMANAGER->update();
}

void stageManager::render()
{
	SCENEMANAGER->render();
}

void stageManager::sceneSet()
{
	sceneManager::getSingleton()->addScene("title", new title);
	sceneManager::getSingleton()->addScene("stage1", new startStage);
	sceneManager::getSingleton()->addScene("stage2", new stage2);
	sceneManager::getSingleton()->addScene("stage3", new stage3);
	sceneManager::getSingleton()->addScene("stage4", new stage4);
	sceneManager::getSingleton()->addScene("stage5", new stage5);
	sceneManager::getSingleton()->addScene("stage6", new stage6);
	sceneManager::getSingleton()->addScene("stage7", new stage7);
	sceneManager::getSingleton()->addScene("undybattle", new undybattle);

	sceneManager::getSingleton()->changeScene("undybattle");
}

