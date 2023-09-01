#include"manager.h"

Manager::Manager(int num, string name, int dept)
{
	this->num = num;
	this->name = name;
	this->dept = dept;
}

void Manager::showinfo()
{
	cout << "职工编号：" << num << "\t"
		<< "职工姓名：" << name << "\t"
		<< "职工部门：" << this->getdept() << "\t"
		<< "职工职责：被BOSS压榨，所以只能撒气在底层员工身上" << endl;

}

string Manager::getdept()
{
	return string("管理");
}
