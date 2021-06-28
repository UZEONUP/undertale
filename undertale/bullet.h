#pragma once
#include "gameNode.h"
#include <vector>

struct tagBullet
{
	RECT rc;
	Image* img;
	float x, y;
	float angle;
	float fireX, fireY;
	float speed;
	bool isFire;
	
};
class bullet :
	public gameNode
{
};

