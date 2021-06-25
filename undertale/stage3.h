#pragma once
#include "gameNode.h"
#include "stageRect.h"

class stage3 : public gameNode
{
	stageRect* _setRect;

	Image* _backGround;
	
public :
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
};

