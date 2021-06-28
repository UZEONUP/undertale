#pragma once
#include "gameNode.h"
#include "dialouge.h"

struct rc_control 
{
	RECT rc;
	int x, y;
};
class battleUI : public gameNode
{
private:
	dialouge* _di;

	rc_control _main_rc;

	Image* _menu_off[4];
	Image* _menu_on[4];
	Image* _heart;

	bool isTalk;
	int _menu_count;

public:
	battleUI();
	~battleUI();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

};

