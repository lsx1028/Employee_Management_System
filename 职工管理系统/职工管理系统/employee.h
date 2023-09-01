#pragma once
#include<iostream>
using namespace std;
#include"worker.h"

class Employee :public Worker
{
public:

	Employee(int num, string name, int dept);
	
	void showinfo();

	string getdept();
};   