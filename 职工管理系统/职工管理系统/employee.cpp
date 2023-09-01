#include"employee.h"

Employee::Employee(int num, string name, int dept)
{
	this->num = num;
	this->name = name;
	this->dept = dept;
}

void Employee::showinfo()
{
	cout << "职工编号：" << num << "\t"
		<< "职工姓名：" << name << "\t"
		<< "职工部门：" << this->getdept() << "\t"
		<< "职工职责：被压榨，苦逼工作" << endl;

}

string Employee::getdept()
{
	return string("底层员工");
}