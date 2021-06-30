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
	int maxHP;
	float x, y;
	float speed;
	float angle;
	float alpha;
	
	int currentFrameX;
	int currentFrameY;
	int count;

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
	tagPlayer _object;
	tagPlayer _undy;

	int _count;
	int _index;

	//undyne* _undy;

	int _wt;
	int _timer;

	int _blink;
	bool _imageON;

	stageManager* _sm;

	vector<tagPlayer*>			 _vObject;
	vector<tagPlayer*>::iterator _viObject;

	bool _Hcol;

public:
	HRESULT init();
	HRESULT init(float x,float y);
	//HRESULT init(int type, bool exit);
	virtual void release();
	virtual void update();
	virtual void render();

	//bool compare(tagPlayer* a, tagPlayer* b);

	RECT getRect() { return _player.rc; }
	RECT getBRect() { return _player.balpan; }
	bool getBattlechk() { return _player.isBattle; }
	void setBattlechk(bool isBattle) { _player.isBattle = isBattle; }
	bool getChangeScene() { return _player.changeScene; }
	float getX() { return _player.x; }
	float getY() { return _player.y; }
	void setPlayerX(float x) { _player.x = x; }
	void setPlayerY(float y) { _player.y = y; }
	float getAlpha() { return _player.alpha; }
	void setAlpha(float alpha) { _player.alpha = alpha; }

	void setHeart(float x, float y);
	int getHP() { return _heart.currentHP; }
	float getHX() { return _heart.x; }
	float getHY() { return _heart.y; }
	RECT getHRect() { return _heart.rc; }

	void linkStageManager(stageManager* stageManager) { _sm = stageManager; }

	vector<tagPlayer*> getVobject() { return _vObject; }
	
	RECT getPlayerRC() { return _player.rc; }
	RECT getPlayerbalpan() { return _player.balpan; }

	void setBoolH(bool Hcol) { _Hcol = Hcol; }
};
