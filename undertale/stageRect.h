#pragma once
#include "gameNode.h"
#include <vector>

struct tagRect
{
	Image* img;
	RECT rc;
	float x, y;
	float width, height;
};

class stageRect : public gameNode
{
	vector<tagRect> _vGround;

public :
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
	void setGround(const float x, const float y, const float width, const float height, const string imageName = "no");

	vector<tagRect> getvGround() { return _vGround; }
};



class objectRect : public gameNode
{
	vector<tagRect> _vObject;

public:
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
	void setObject(const float x, const float y, const float width, const float height, const string imageName = "no");

	vector<tagRect> getvObject() { return _vObject; }
};

