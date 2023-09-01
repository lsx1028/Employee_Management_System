#pragma once
#include<iostream>
using namespace std;

class Worker
{
public:

	virtual void showinfo() = 0;
	virtual string getdept() = 0;

	int num;

	string name;

	int dept;
};