#include"employee.h"

Employee::Employee(int num, string name, int dept)
{
	this->num = num;
	this->name = name;
	this->dept = dept;
}

void Employee::showinfo()
{
	cout << "ְ����ţ�" << num << "\t"
		<< "ְ��������" << name << "\t"
		<< "ְ�����ţ�" << this->getdept() << "\t"
		<< "ְ��ְ�𣺱�ѹե����ƹ���" << endl;

}

string Employee::getdept()
{
	return string("�ײ�Ա��");
}