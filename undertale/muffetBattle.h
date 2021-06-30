#pragma once
#include "gameNode.h"
#include <vector>
#include "bullet.h"
#include "battleUI.h"

struct  tagImage
{
	RECT rc;
	Image* img;
	float x, y;
	int currentFrameX;
	float angle;
	bool isFrameImage;
};
enum MUFFET
{
	HEAD,
	HAIR,
	EYE = 3,
	SHOULDER = 8,
	ARM = 10,
	BOTTOM_HAND = 14,
	BOTTOM_HAND_FIST = 16,
	TEAPORT = 18,
	LEG = 20,
	BODY
};
class muffetBattle : public gameNode
{
	tagImage _mfImage;
	bullet* _bullet;
	battleUI* _btUI;

	vector<tagImage> _muffetV;

	int _currentFrameY;
	int _frameCount;
	bool _downMove;

public:
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	void addMuffetImage();

};

