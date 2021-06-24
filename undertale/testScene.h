#pragma once
#include "gameNode.h"
#include "battleUI.h"

class testScene :
	public gameNode
{
private:
	battleUI* _bui;

public:

	HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
};

