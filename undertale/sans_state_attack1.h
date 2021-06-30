#pragma once
#include "sans_state.h"
#include "sansBattle.h"
#include "sans_state_idle.h"

class sansBattle;

class sans_state_attack1 : public sans_state
{
private:


	float _bone_speed;

public:

	virtual sans_state* inputHandle(sansBattle* sansBattle);
	virtual void enter(sansBattle* sansBattle);
	virtual void update(sansBattle* sansBattle);
	virtual void render(sansBattle* sansBattle);
	virtual void exit(sansBattle* sansBattle);
};

