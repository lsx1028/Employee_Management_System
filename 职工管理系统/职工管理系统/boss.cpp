#include"boss.h"

Boss::Boss(int num, string name, int dept)
{
	this->num = num;
	this->name = name;
	this->dept = dept;
}

void Boss::showinfo()
{
	cout << "ְ����ţ�" << num << "\t"
		<< "ְ��������" << name << "\t"
		<< "ְ�����ţ�" << this->getdept() << "\t"
		<< "ְ��ְ����Ȼ��Ǯ������Ҫ�����Ǯ������ѹեԱ��" << endl;

}

string Boss::getdept()
{
	return string("ɵ���ϰ�");
}