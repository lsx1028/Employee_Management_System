#pragma once
#include<iostream>
using namespace std;
#include"worker.h"

class Manager :public Worker
{
public:

	Manager(int num, string name, int dept);

	void showinfo();

	string getdept();
};