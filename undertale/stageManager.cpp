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
	SCENEMANAGER->addScene("stage1", new startStage);
	SCENEMANAGER->addScene("stage2", new stage2);
	SCENEMANAGER->addScene("stage3", new stage3);
	SCENEMANAGER->addScene("stage4", new stage4);
	SCENEMANAGER->addScene("stage5", new stage5);
	SCENEMANAGER->addScene("stage6", new stage6);
	SCENEMANAGER->addScene("stage7", new stage7);
	SCENEMANAGER->addScene("undybattle", new undybattle);
	SCENEMANAGER->addScene("sansBattle", new sansBattle);

	SCENEMANAGER->changeScene("stage1");
}

