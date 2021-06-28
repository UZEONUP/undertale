#pragma once
#include "gameNode.h"
#include "undyne.h"
#include <vector>

enum STATE
{
	LEFT,
	RIGHT,
	UP,
	DOWN,
	LEFT_MOVE,
	RIGHT_MOVE,
	UP_MOVE,
	DOWN_MOVE
};

struct tagPlayer
{
	Image* img;
	RECT rc;
	RECT balpan;
	STATE state;
	int currentHP;
	float x, y;
	float speed;
	float angle;
	
	int currentFrameX;
	int currentFrameY;

	bool isBattle;
	bool deletepl;
	bool changeScene;
};

class stageManager;

class player :
	public gameNode
{
private:
	tagPlayer _player;
	tagPlayer _heart;
	tagPlayer* _object;


	int _count;
	int _index;

	undyne* _undy;

	int _wt;
	int _timer;

	int _blink;
	bool _imageON;

	stageManager* _sm;

	vector<tagPlayer*>			 _vObject;
	vector<tagPlayer*>::iterator _viObject;

public:
	HRESULT init();
	HRESULT init(float x, float y);
	virtual void release();
	virtual void update();
	virtual void render();


	RECT getRect() { return _player.rc; }
	RECT getBRect() { return _player.balpan; }
	bool getBattlechk() { return _player.isBattle; }
	void setBattlechk(bool isBattle) { _player.isBattle = isBattle; }
	bool getChangeScene() { return _player.changeScene; }
	float getX() { return _player.x; }
	float getY() { return _player.y; }
	void setPlayerX(float x) { _player.x = x; }
	void setPlayerY(float y) { _player.y = y; }

	void setHeart(float x, float y);
	float getHX() { return _heart.x; }
	float getHY() { return _heart.y; }
	RECT getHRect() { return _heart.rc; }

	void linkStageManager(stageManager* stageManager) { _sm = stageManager; }

	vector<tagPlayer*> getVobject() { return _vObject; }

};
