
#include<iostream>
#include<string>
#include<vector>
#include<fstream> 
#include<iomanip>
using namespace std;

#include"book.h"
#include"library.h"

Library OneBook;  //定义一个实例
/***********************读取和保存文件函数**************************/
void read()
{
	int i, temp;
	ifstream my1("num.txt");
	my1 >> temp;
	ifstream my("book.txt");
	for (i = 0; i < temp; i++)
	{
		string name, num, auther;

		my >> name >> num >> auther;
		OneBook.addBook(name, num, auther);

	}
}
void save()
{
	ofstream my("book.txt");    //book.txt 用来存储书籍信息
	int i;
	for (i = 0; i < (int)OneBook.getBooks().size(); i++) {
		Book b;
		b = OneBook.getBooks()[i];
		my << b.getName() << "\t" << b.getNum() << "\t" << b.getAuther() << "\t" << "\n";
	}
	ofstream my1("num.txt");   //num.txt用来存储书籍总数量
	my1 << OneBook.getBooks().size();
}

/***********************菜单管理面板函数**************************/
void menu()
{
	int temp;

	cout << "***************************************************************" << endl;
	cout << "***************************************************************" << endl;
	cout << "************                 ENJOY IT              ************" << endl;
	cout << "****************************************************************" << endl;
	cout << "***************************************************************" << endl;
	cout << "************                作者：张龙威            ************" << endl;
	cout << "************                时间：2019.6.30         ************" << endl;
	cout << "************                版本：v 2.0             ************" << endl;
	cout << "***************************************************************" << endl;
	cout << "***************         All Ringhts Reserved!    ***************" << endl;
	cout << "***************************************************************" << endl;

	system("pause");
	system("cls");
	while (1)
	{
		cout << "***************************************************************" << endl;
		cout << "***************************************************************" << endl;
		cout << "$$$$$$$$$$$$              图书管理系统             $$$$$$$$$$$$" << endl;
		cout << "****************************************************************" << endl;
		cout << "***************************************************************" << endl;
		cout << "################################################################" << endl;
		cout << "################################################################" << endl;
		cout << "                           【1】增加图书                         " << endl;
		cout << "                           【2】删除图书                         " << endl;
		cout << "                           【3】显示所有                         " << endl;
		cout << "                           【4】查询图书                         " << endl;
		cout << "                           【5】修改图书                         " << endl;
		cout << "                           【0】退出系统                         " << endl;
		cout << "################################################################" << endl;
		cout << "################################################################" << endl;
		cout << endl;
		cout << "输入要进行的操作：";
		cin >> temp;
		switch (temp) {
		case 1:
			system("cls");
			OneBook.addBook(); save();
			break;
		case 2:system("cls");
			OneBook.deleteBook(); save();
			break;
		case 3:system("cls");
			OneBook.showInfo();
			break;
		case 4:system("cls");
			OneBook.searchbooks();
			break;
		case 5:system("cls");
			OneBook.fixbooks();
			break;
		case 0:
			save();
			exit(1);
			break;
		default:
			cout << "输入错误！" << endl;
			system("pause");
			system("cls");
		}
	}
}

/***********************主函数**************************/
int main()
{
	read();
	system("color b0");
	menu();
	return 0;
}