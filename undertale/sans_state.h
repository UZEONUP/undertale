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
	float angle;
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
	objectBone _laser_bim[BONEMAX50];

	//=======충돌안함=========
	objectBone _bone2_100[BONEMAX50];
	objectBone _foothold[BONEMAX50];
	objectBone _laser_body[BONEMAX50];
	//==============================
	float _bone_speed;
	bool _isJump;
	float _jumpPower;
public:

	virtual sans_state* inputHandle(sansBattle* sansBattle) = 0;
	virtual	void update(sansBattle* sansBattle) = 0;
	virtual	void enter(sansBattle* sansBattle) = 0;
	virtual void render(sansBattle* sansBattle) = 0;
	virtual void exit(sansBattle* sansBattle) = 0;

	void heart_control(sansBattle* sansBattle, bool gravity_bool, float gravity, float jumpPower);
	void collision(sansBattle* sansBattle, RECT rect);
	void linkSans(sansBattle* sans) { _sanBattle = sans; }

	//충돌부분 get set
	RECT get_bone_20_rc(int index) { return _bone_20[index].rc; }
	RECT get_bone_40_rc(int index) { return _bone_40[index].rc; }
	RECT get_bone_50_rc(int index) { return _bone_50[index].rc; }
	RECT get_bone_100_rc(int index) { return _bone_100[index].rc; }
	RECT get__laser_bim_rc(int index) { return _laser_bim[index].rc; }
};

