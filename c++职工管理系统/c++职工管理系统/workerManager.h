#pragma once

#if defined(_MSC_VER)
#pragma execution_character_set("utf-8")
#endif

#include <iostream>
#include <fstream>
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"

#define FILENAME "empFile.txt"

using namespace std;

class WorkerManager {
public:
	WorkerManager();

	void Show_Menu();

	void ExitSystem();

	int m_EmpNum;

	Worker** m_EmpArray;

	void Add_Emp();


	void save();

	bool m_FileIsEmpty;

	int get_EmpNum();

	//初始化员工
	void init_Emp();

	//显示职工
	void Show_Emp();

	//删除职工
	void Del_Emp();

	int IsExist(int id);

	//修改职工
	void Mod_Emp();

	//查找职工
	void Find_Emp();

	//排序职工
	void Sort_Emp();

	//清空文件
	void Clean_File();

	~WorkerManager();
};
