#pragma once

#if defined(_MSC_VER)
#pragma execution_character_set("utf-8")
#endif

#include <iostream>
#include <string>
#include "worker.h"
using namespace std;

class Employee:public Worker {
public:
	Employee(int id,string name,int dId);

	virtual void showInfo();

	virtual string getDeptName();
};
