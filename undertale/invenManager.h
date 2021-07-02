#pragma once
#include "singletonBase.h"
#include "stage5.h"

class invenManager : public singletonBase<invenManager>
{
private:
	stage5* _shop;

	vector<tagItemInfo>					vInven;
	vector<tagItemInfo>::iterator		vIterInven;
public:
	invenManager() {};
	~invenManager() {};

	HRESULT init();
	HRESULT init(vector<tagItemInfo> vItem);

	void release();
	void update();
	void render();

	void in();
	void open();
	void close();

	void linkShop(stage5* shop) { _shop = shop; }
};

