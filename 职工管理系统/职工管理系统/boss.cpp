#include"boss.h"

Boss::Boss(int num, string name, int dept)
{
	this->num = num;
	this->name = name;
	this->dept = dept;
}

void Boss::showinfo()
{
	cout << "职工编号：" << num << "\t"
		<< "职工姓名：" << name << "\t"
		<< "职工部门：" << this->getdept() << "\t"
		<< "职工职责：虽然有钱，但想要更多的钱，所以压榨员工" << endl;

}

string Boss::getdept()
{
	return string("傻逼老板");
}