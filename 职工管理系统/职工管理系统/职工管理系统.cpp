#include<iostream>
using namespace std;
#include"workmanager.h"

int main()
{
	WorkManager wm;
	int choice;

	while (true)
	{
		wm.showmenu();
		cin >> choice;

		switch (choice)
		{
		case 0:
			wm.Exit();
			break;
		case 1:
			wm.addworker();
			break;
		case 2:
			wm.show_emp();
			break;
		case 3:
			wm.del_emp();
			break;
		case 4:
			wm.modify();
			break;
		case 5:
			wm.check();
			break;
		case 6:
			wm.sort();
			break;
		case 7:
			wm.clear();
			break;
		default:
			cout << "请重新输入正确的选项！" << endl;
			system("pause");
			system("cls");
			break;
		}
	}

	system("pause");
	return 0;
}