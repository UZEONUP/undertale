#pragma once
#include "gameNode.h"
struct inGameHeart
{
	Image* img;
	RECT rc;
	int currentHP;
	int maxHP;
	float x, y;
	float speed;

	int currentFrameX;
	int currentFrameY;


	bool isBattle;

};

enum heartColor
{
	RED,
	GREEN,
	BLUE,
	PURPLE
};

class heart :	public gameNode
{
private:
	inGameHeart _iGH;
	heartColor _hC;
public:
	HRESULT init(int color);
	virtual void release();
	virtual void update();
	virtual void render();

};

