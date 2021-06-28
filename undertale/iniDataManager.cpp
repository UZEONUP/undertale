#include "stdafx.h"
#include "iniDataManager.h"


iniDataManager::iniDataManager()
{
}


iniDataManager::~iniDataManager()
{
}

HRESULT iniDataManager::init()
{
	return S_OK;
}

void iniDataManager::release()
{
}


char* iniDataManager::loadDataString(const char * fileName, const char * subject, const char * title)
{
	char str[1024];
	char dir[1024];

	ZeroMemory(dir, sizeof(dir));
	sprintf_s(dir, "\\%s.ini", fileName);

	GetCurrentDirectory(1024, str);
	strncat_s(str, 1024, dir, 1022);

	char data[1024] = {};
	GetPrivateProfileString(subject, title, "", dataBuffer, 1024, str);

	return dataBuffer;
}
char* iniDataManager::loadDataString2(const char * fileName, const char * subject, const char * title)
{
	char str[1024];
	char dir[1024];

	ZeroMemory(dir, sizeof(dir));
	sprintf_s(dir, "\\%s.ini", fileName);

	GetCurrentDirectory(1024, str);
	strncat_s(str, 1024, dir, 1022);

	char data[1024] = {};
	GetPrivateProfileString(subject, title, "", dataBuffer2, 1024, str);

	return dataBuffer2;
}


int iniDataManager::loadDataInterger(const char * fileName, const char * subject, const char * title)
{
	char str[256];
	char dir[256];

	ZeroMemory(dir, sizeof(dir));
	sprintf_s(dir, "\\%s.ini", fileName);

	GetCurrentDirectory(256, str);
	strncat_s(str, 256, dir, 254);


	return GetPrivateProfileInt(subject, title, 0, str);
}
