#include"manager.h"

Manager::Manager(int num, string name, int dept)
{
	this->num = num;
	this->name = name;
	this->dept = dept;
}

void Manager::showinfo()
{
	cout << "ְ����ţ�" << num << "\t"
		<< "ְ��������" << name << "\t"
		<< "ְ�����ţ�" << this->getdept() << "\t"
		<< "ְ��ְ�𣺱�BOSSѹե������ֻ�������ڵײ�Ա������" << endl;

}

string Manager::getdept()
{
	return string("���ȹ���");
}