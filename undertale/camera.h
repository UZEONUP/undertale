#pragma once
#include "image.h"
#include "singletonBase.h"

class camera : public singletonBase<camera>
{

public:
	HRESULT init();
	void release();
	void update();
	void render();

	void setCamera(float x, float y);
	void updateCamera(RECT& player, float ratioX, float ratioY);
	void updateCamera(float x,float y, float ratioX, float ratioY);
};

