#pragma once
#include "gameNode.h"
#include "asriel.h"

class testScene :public gameNode
{
private:
	asriel* _asriel;

public:
	HRESULT init();
	void release();
	void update();
	void render();

};

