#pragma once
#define BONEMAX 20
#define BONEMAX50 50

class sansBattle;

struct objectBone
{
	Image* img;
	RECT rc;
	float x, y;
	int width, hieght;
	int currentFrameX;
	int currentFrameY;
};

class sans_state
{
private:
	sansBattle* _sanBattle;
protected:
	//=======충돌부분=========
	objectBone _bone_20[BONEMAX50];
	objectBone _bone_40[BONEMAX50];
	objectBone _bone_50[BONEMAX50];
	objectBone _bone_100[BONEMAX50];
	//=======충돌안함=========
	objectBone _bone2_100[BONEMAX50];
	objectBone _foothold[BONEMAX50];
	//==============================
	float _bone_speed;
	float _gravity = 1.5f;
public:

	virtual sans_state* inputHandle(sansBattle* sansBattle) = 0;
	virtual	void update(sansBattle* sansBattle) = 0;
	virtual	void enter(sansBattle* sansBattle) = 0;
	virtual void render(sansBattle* sansBattle) = 0;
	virtual void exit(sansBattle* sansBattle) = 0;

	void heart_control(sansBattle* sansBattle);
	void linkSans(sansBattle* sans) { _sanBattle = sans; }
};

