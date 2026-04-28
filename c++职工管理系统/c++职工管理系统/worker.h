#pragma once

#if defined(_MSC_VER)
#pragma execution_character_set("utf-8")
#endif

#include <iostream>
#include <string>
using namespace std;

class Worker {
public:
	virtual void showInfo() = 0;
	virtual string getDeptName() = 0;

	int m_Id;
	string m_Name;
	int m_DeptId;
};
