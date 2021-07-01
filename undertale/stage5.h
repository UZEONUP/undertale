#pragma once
#include "gameNode.h"
#include "stage4.h"

enum ITEM
{
	ITEM_POTION
};

struct tagItemInfo
{
	ITEM itemKind;
	RECT rc;
	const char* name;
	const char* description;
	int ablity;
	int price;
};

class stage5 : public gameNode
{
private:
	vector<tagItemInfo>			_vItem;
	vector<tagItemInfo>			_vIterItem;

	Image* _backGround;

	RECT _shopRect;

	int i;

public :
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	void shopSet();
	void itemSet();
	void itemOut();

};

