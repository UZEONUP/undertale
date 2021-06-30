#pragma once
#include "gameNode.h"
#include "battleUI.h"
#define BONEMAX 10

struct sansObject
{
	Image* img;
	RECT rc;
	float x, y;
	int width, hieght;
	int currentFrameX;
	int currentFrameY;
};

class sansBattle : public gameNode
{
private:
	battleUI* _ui;

	//========»÷Áî==========
	sansObject _sans_head;
	sansObject _sans_sweat;
	sansObject _sans_body;
	sansObject _sans_legs;
	sansObject _sans_attack;
	//======================

	//=======»À´Ù±Í=========
	sansObject _bone_20[BONEMAX];
	sansObject _bone_40[BONEMAX];
	sansObject _bone_50[BONEMAX];
	sansObject _bone_100[BONEMAX];
	//=====================
	bool _isattack;
	bool _isMove;

	int _pattern;

public:

	sansBattle();
	~sansBattle();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	void setAttack1(int pattern);
	void updateAttack1(int pattern);
};

