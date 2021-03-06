// inheritanceTest.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>

using namespace std;

class CPerson
{
public:
	CPerson(int iAge, char *sName)
	{
		this->iAge = iAge;
		strcpy_s(this->sName, 32, sName);
	}

private:
	int iAge;
	char sName[32];
};

class CWorker : public CPerson
{
public:
	CWorker(int iAge, char *sName, char * sEmploymentStatus)
		: CPerson(iAge, sName)
	{
		strcpy_s(this->sEmploymentStatus, 32, sEmploymentStatus);
	}
	virtual char * WhoAmI()
	{
		return "I am a worker";
	}
private:
	char sEmploymentStatus[32];
};

int main()
{
    return 0;
}

