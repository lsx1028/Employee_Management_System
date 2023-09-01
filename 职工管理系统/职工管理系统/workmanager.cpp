#include"workmanager.h"

WorkManager::WorkManager()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	if (ifs.is_open() != 1)
	{
		cout << "�ļ�������" << endl;
		file_isopen = true;
		this->arrworker = NULL;
		this->emp_num = 0;
		return;
	}

	char ch;
	ifs >> ch;
	if (ch = ifs.eof())
	{

		cout << "�ļ�Ϊ�գ�" << endl;
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
	cout << "ְ������Ϊ��" << number << endl;

	this->arrworker = new Worker*[this->emp_num];
	this->init();

	fs.close();
}

void WorkManager::showmenu()
{
	cout << "**************************************************" << endl;
	cout << "*************��ӭʹ��ְ������ϵͳ��***************" << endl;
	cout << "*******************0.�˳�����ϵͳ*****************" << endl;
	cout << "*******************1.����ְ����Ϣ*****************" << endl;
	cout << "*******************2.��ʾְ����Ϣ*****************" << endl;
	cout << "*******************3.ɾ����ְְ��*****************" << endl;
	cout << "*******************4.�޸�ְ����Ϣ*****************" << endl;
	cout << "*******************5.����ְ����Ϣ*****************" << endl;
	cout << "*******************6.���ձ������*****************" << endl;
	cout << "*******************7.��������ĵ�*****************" << endl;
	cout << "**************************************************" << endl;
	cout << endl;
}

void WorkManager::Exit()
{
	cout << "�˳��ɹ���" << endl;
	exit(-1);
}

void WorkManager::addworker()
{
	cout << "����������Ҫ��ӵ����� ��" << endl;
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

		cout << "�������" << i + 1 << "��ְ���ı�ţ�" << endl;
		cin >> num;

		cout << "�������" << i + 1 << "��ְ����������" << endl;
		cin >> name;
		
		cout << "�������" << i + 1 << "��ְ���ĸ�λ��" << endl;
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
		cout << "�ɹ���ӵ�" << i + 1 << "��ְ����" << endl;
	}
	cout << "�����ϣ�" << endl;
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
	//	cout << "Ա����ţ�" << num << "\t"
	//		<< "Ա��������" << name << "\t"
	//		<< "Ա��ְλ��";
	//	if (dept == 1)
	//	{
	//		cout<< "��Ȼ��Ǯ������Ҫ�����Ǯ������ѹեԱ��" << endl;
	//	}
	//	else if (dept == 2)
	//	{
	//		cout << "��BOSSѹե������ֻ�������ڵײ�Ա������" << endl;
	//	}
	//	else if (dept == 3)
	//	{
	//		cout << "��ѹե����ƹ���" << endl;
	//	}  
	//}
	//ifs.close();

	if (file_isopen)
	{
		cout << "�ļ������ڻ�Ϊ�գ�" << endl;
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
	cout << "��������Ҫ���һ�ɾ����Ա���ı�ţ�" << endl;
	int num;
	cin >> num;
	int i = 0;

	for (int i = 0; i < this->emp_num; i++)
	{
		if (this->arrworker[i]->num == num)
		{
			cout << "�ҵ�����" << endl;
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
		cout << "û���ҵ���" << endl;
		return;
	}

	for (i; i < this->emp_num-1; i++)
	{
		this->arrworker[i] = this->arrworker[i + 1];
		
	}
	this->emp_num--;
	this->arrworker[i]=NULL;
	this->modsave();
	
	cout << "ɾ���ɹ���" << endl;
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
		cout << "û���ҵ���" << endl;
		return;
	}

	cout << "�������µ�ְ����ţ�" << endl;
	cin >> this->arrworker[i]->num;
	cout << "�������µ�ְ��������" << endl;
	cin >> this->arrworker[i]->name;
	cout << "�������µ�ְ�����ţ�" << endl;
	cin >> this->arrworker[i]->dept;

	this->modsave();
	cout << "ɾ���ɹ���" << endl;
	system("pause");
	system("cls");
}

void WorkManager::check()
{
	int i = this->find();
	if (i == -1)
	{
		cout << "û���ҵ���" << endl;
		return;
	}

	this->arrworker[i]->showinfo();
	system("pause");
	system("cls");
}

void WorkManager::sort()
{
	cout << "����������Ҫ������ʽ��" << endl;
	cout << "1----����" << endl;
	cout << "2----����" << endl;
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

	cout << "����ɹ���" << endl;
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
	cout << "��ճɹ���" << endl;
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