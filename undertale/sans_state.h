#pragma once
#define BONEMAX 20

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

protected:
	//=======»À´Ù±Í=========
	objectBone _bone_20[BONEMAX];
	objectBone _bone_40[BONEMAX];
	objectBone _bone_50[BONEMAX];
	objectBone _bone_100[BONEMAX];
	//=====================
	float _bone_speed;
public:

	virtual sans_state* inputHandle(sansBattle* sansBattle) = 0;
	virtual	void update(sansBattle* sansBattle) = 0;
	virtual	void enter(sansBattle* sansBattle) = 0;
	virtual void render(sansBattle* sansBattle) = 0;
	virtual void exit(sansBattle* sansBattle) = 0;
};

