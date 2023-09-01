#pragma once
#include<iostream>
using namespace std;
#include"worker.h"

class Boss :public Worker
{
public:

	Boss(int num, string name, int dept);

	void showinfo();

	string getdept();
};