#include"workmanager.h"

WorkManager::WorkManager()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	if (ifs.is_open() != 1)
	{
		cout << "文件不存在" << endl;
		file_isopen = true;
		this->arrworker = NULL;
		this->emp_num = 0;
		return;
	}

	char ch;
	ifs >> ch;
	if (ch = ifs.eof())
	{

		cout << "文件为空！" << endl;
		file_isopen = true;
		this->arrworker = NULL;
		this->emp_num = 0;
		return;
	}
	ifs.close();

	ifstream fs;
	fs.open(FILENAME, ios::in);
	int num;
	string name;
	int dept;
	int number = 0;
	while (fs >> num && fs >> name && fs >> dept)
	{
		number++;
	}
	this->emp_num = number;
	cout << "职工人数为：" << number << endl;

	this->arrworker = new Worker*[this->emp_num];
	this->init();

	fs.close();
}

void WorkManager::showmenu()
{
	cout << "**************************************************" << endl;
	cout << "*************欢迎使用职工管理系统！***************" << endl;
	cout << "*******************0.退出管理系统*****************" << endl;
	cout << "*******************1.增加职工信息*****************" << endl;
	cout << "*******************2.显示职工信息*****************" << endl;
	cout << "*******************3.删除离职职工*****************" << endl;
	cout << "*******************4.修改职工信息*****************" << endl;
	cout << "*******************5.查找职工信息*****************" << endl;
	cout << "*******************6.按照编号排序*****************" << endl;
	cout << "*******************7.清空所有文档*****************" << endl;
	cout << "**************************************************" << endl;
	cout << endl;
}

void WorkManager::Exit()
{
	cout << "退出成功！" << endl;
	exit(-1);
}

void WorkManager::addworker()
{
	cout << "请输入您想要添加的人数 ：" << endl;
	int addsize;
	cin >> addsize;

	Worker **newspace = new Worker*[this->emp_num + addsize];

	if (this->arrworker != NULL)
	{
		for (int i = 0; i < this->emp_num; i++)
		{
			newspace[i] = arrworker[i];
		}
	}

	for (int i = 0; i < addsize; i++)
	{
		int num;
		string name;
		int dept;
		Worker* worker = NULL;
		system("cls");

		cout << "请输入第" << i + 1 << "名职工的编号：" << endl;
		cin >> num;

		cout << "请输入第" << i + 1 << "名职工的姓名：" << endl;
		cin >> name;
		
		cout << "请输入第" << i + 1 << "名职工的岗位：" << endl;
		cout << "1--Boss" << endl;
		cout << "2--Manager" << endl;
		cout << "3--Employee" << endl;
		cin >> dept;
		
		switch (dept)
		{
		case 1:
			worker = new Boss(num, name, dept);
			break;
		case 2:
			worker = new Manager(num, name, dept);
			break;
		case 3:
			worker = new Employee(num, name, dept);
			break;
		default:
			break;
		}

		newspace[this->emp_num + i] = worker;
		cout << "成功添加第" << i + 1 << "个职工！" << endl;
	}
	cout << "添加完毕！" << endl;
	delete [] this->arrworker;
	this->arrworker = newspace;

	this->emp_num += addsize;

	this->save();
	file_isopen = false;

	system("pause");
	system("cls");
}

void WorkManager::save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);
	
	for (int i=0; i < this->emp_num;i++)
	{
		ofs << this->arrworker[i]->num << "  "
			<< this->arrworker[i]->name << "  "
			<< this->arrworker[i]->dept << endl; 
	}

	ofs.close();
}


void WorkManager::init()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int num;
	string name;
	int dept;

	int index = 0;
	while (ifs >> num && ifs >> name && ifs >> dept)
	{
		Worker* worker1 = NULL;
		if (dept == 1)
		{
			worker1 = new Boss(num, name, dept);
		}
		else if (dept == 2)
		{
			worker1 = new Manager(num, name, dept);
		}
		else if (dept == 3)
		{
			worker1 = new Employee(num, name, dept);
		}
		this->arrworker[index] = worker1;
		index++;
	}
	ifs.close();
}

void WorkManager::show_emp()
{
	//ifstream ifs;
	//ifs.open(FILENAME, ios::in);
	//int num;
	//string name;
	//int dept;
	//while (ifs >> num && ifs >> name && ifs >> dept)
	//{
	//	cout << "员工编号：" << num << "\t"
	//		<< "员工姓名：" << name << "\t"
	//		<< "员工职位：";
	//	if (dept == 1)
	//	{
	//		cout<< "虽然有钱，但想要更多的钱，所以压榨员工" << endl;
	//	}
	//	else if (dept == 2)
	//	{
	//		cout << "被BOSS压榨，所以只能撒气在底层员工身上" << endl;
	//	}
	//	else if (dept == 3)
	//	{
	//		cout << "被压榨，苦逼工作" << endl;
	//	}  
	//}
	//ifs.close();

	if (file_isopen)
	{
		cout << "文件不存在或为空！" << endl;
	}
	else
	{
		cout << this->emp_num << endl;
		for (int i = 0; i < this->emp_num; i++)
		{
			this->arrworker[i]->showinfo();
		}
	}
	system("pause");
	system("cls");
}

int WorkManager::find()
{
	cout << "请输入您要查找或删除的员工的编号：" << endl;
	int num;
	cin >> num;
	int i = 0;

	for (int i = 0; i < this->emp_num; i++)
	{
		if (this->arrworker[i]->num == num)
		{
			cout << "找到啦！" << endl;
			return i;
		}
	}
	return -1;
}

void WorkManager::del_emp()
{
	int i = this->find();

	if (i == -1)
	{
		cout << "没有找到捏！" << endl;
		return;
	}

	for (i; i < this->emp_num-1; i++)
	{
		this->arrworker[i] = this->arrworker[i + 1];
		
	}
	this->emp_num--;
	this->arrworker[i]=NULL;
	this->modsave();
	
	cout << "删除成功！" << endl;
	system("pause");
	system("cls");
}

void WorkManager::modsave()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::trunc);

	for (int i = 0; i < this->emp_num; i++)
	{
		ofs << this->arrworker[i]->num << "  "
			<< this->arrworker[i]->name << "  "
			<< this->arrworker[i]->dept << endl;
	}

	ofs.close();
}


void WorkManager::modify()
{
	int i = this->find();

	if (i == -1)
	{
		cout << "没有找到捏！" << endl;
		return;
	}

	cout << "请输入新的职工编号：" << endl;
	cin >> this->arrworker[i]->num;
	cout << "请输入新的职工姓名：" << endl;
	cin >> this->arrworker[i]->name;
	cout << "请输入新的职工部门：" << endl;
	cin >> this->arrworker[i]->dept;

	this->modsave();
	cout << "删除成功！" << endl;
	system("pause");
	system("cls");
}

void WorkManager::check()
{
	int i = this->find();
	if (i == -1)
	{
		cout << "没有找到捏！" << endl;
		return;
	}

	this->arrworker[i]->showinfo();
	system("pause");
	system("cls");
}

void WorkManager::sort()
{
	cout << "请输入您需要的排序方式：" << endl;
	cout << "1----升序" << endl;
	cout << "2----降序" << endl;
	int choice = 0;
	cin >> choice;

	if (choice == 1)
	{
		for (int i = 0; i < this->emp_num; i++)
		{
			int minindex = i;
			for (int j = i; j < this->emp_num; j++)
			{
				if (this->arrworker[minindex]->num > this->arrworker[j]->num)
				{
					minindex = j;
				}
			}
			swap(this->arrworker[i], this->arrworker[minindex]);
		}
	}
	else if (choice == 2)
	{
		for (int i = 0; i < this->emp_num; i++)
		{
			int maxindex = i;
			for (int j = i; j < this->emp_num; j++)
			{
				if (this->arrworker[maxindex]->num < this->arrworker[j]->num)
				{
					maxindex = j;
				}
			}
			swap(this->arrworker[i], this->arrworker[maxindex]);
		}
	}

	cout << "排序成功！" << endl;
	this->modsave();

	system("pause");
	system("cls");
}

void WorkManager::clear()
{
	for (int i=this->emp_num; i > 0; i--)
	{
		this->arrworker[i] = this->arrworker[i - 1];
		this->arrworker[i] = NULL;
	}
	this->emp_num=0;
	this->modsave();
	file_isopen = 1;
	cout << "清空成功！" << endl;
	system("pause");
	system("cls");
}

WorkManager::~WorkManager()
{
	if (this->arrworker != NULL)
	{
		delete[] this->arrworker;
		this->arrworker = NULL;
	}
}