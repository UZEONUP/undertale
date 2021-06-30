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
	int damage;

};
class bullet :
	public gameNode
{
private:
	vector<tagBullet>			_vBullet;
	vector<tagBullet>::iterator _viBullet;
	tagBullet _bullet;
	const char* _imageName;
	
public:

	bullet() {};
	~bullet() {};

	HRESULT init(const char* imageName);
	void release();
	void update();
	void render();

	void fire();
	void move();

	void removeBullet();

	void hit(int damage);



};

