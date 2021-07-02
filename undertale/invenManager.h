#pragma once
#include "singletonBase.h"
#include "stage5.h"

class invenManager : public singletonBase<invenManager>
{
private:
	stage5* _shop;

	vector<tagItemInfo>				_vInven;
	vector<tagItemInfo>::iterator	_vIterInven;

	bool _open;

	RECT _inven;
	int _invenMax; //최대 용량


public:
	invenManager() {};
	~invenManager() {};

	HRESULT init();

	void release();
	void update();
	void render();

	void in(tagItemInfo item);
	void open();
	void close();

	void linkShop(stage5* shop) { _shop = shop; }
};

