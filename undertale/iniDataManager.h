#pragma once
#include "singletonBase.h"
#include <vector>



class iniDataManager : public singletonBase<iniDataManager>
{
private:
	

private:
	

	char dataBuffer[256];


public:
	iniDataManager();
	~iniDataManager();

	HRESULT init();
	void release();

	

	char* loadDataString(const char* fileName, const char* subject, const char* title);

	int loadDataInterger(const char* fileName, const char* subject, const char* title);

};

