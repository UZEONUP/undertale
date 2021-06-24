#pragma once
#include "gameNode.h"

struct rc_control 
{
	RECT rc;
	int x, y;
};
class battleUI : public gameNode
{
private:

	rc_control _main_rc;

	Image* _menu_off[4];
	Image* _menu_on[4];
	Image* _heart;

	int _menu_count;

public:
	battleUI();
	~battleUI();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

};

