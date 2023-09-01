#pragma once
#include<iostream>
using namespace std;
#include"boss.h"
#include"manager.h"
#include"employee.h"
#include<fstream>
#include<algorithm>

#define FILENAME "Employeebook.txt"

class WorkManager
{
public:
	bool file_isopen = false;

	WorkManager();

	void showmenu();

	void Exit();

	Worker** arrworker;

	int emp_num;

	void addworker();

	void save();

	void init();

	void show_emp();

	int find();

	void del_emp();

	void modsave();

	void modify();

	void check();

	void sort();

	void clear();

	~WorkManager();
};