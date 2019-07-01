
#include<iostream>
#include<string>
#include<vector>
#include<fstream> 
#include<iomanip>
using namespace std;

#include"book.h"
#include"library.h"

Library OneBook;  //����һ��ʵ��
/***********************��ȡ�ͱ����ļ�����**************************/
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
	ofstream my("book.txt");    //book.txt �����洢�鼮��Ϣ
	int i;
	for (i = 0; i < (int)OneBook.getBooks().size(); i++) {
		Book b;
		b = OneBook.getBooks()[i];
		my << b.getName() << "\t" << b.getNum() << "\t" << b.getAuther() << "\t" << "\n";
	}
	ofstream my1("num.txt");   //num.txt�����洢�鼮������
	my1 << OneBook.getBooks().size();
}

/***********************�˵�������庯��**************************/
void menu()
{
	int temp;

	cout << "***************************************************************" << endl;
	cout << "***************************************************************" << endl;
	cout << "************                 ENJOY IT              ************" << endl;
	cout << "****************************************************************" << endl;
	cout << "***************************************************************" << endl;
	cout << "************                ���ߣ�������            ************" << endl;
	cout << "************                ʱ�䣺2019.6.30         ************" << endl;
	cout << "************                �汾��v 2.0             ************" << endl;
	cout << "***************************************************************" << endl;
	cout << "***************         All Ringhts Reserved!    ***************" << endl;
	cout << "***************************************************************" << endl;

	system("pause");
	system("cls");
	while (1)
	{
		cout << "***************************************************************" << endl;
		cout << "***************************************************************" << endl;
		cout << "$$$$$$$$$$$$              ͼ�����ϵͳ             $$$$$$$$$$$$" << endl;
		cout << "****************************************************************" << endl;
		cout << "***************************************************************" << endl;
		cout << "################################################################" << endl;
		cout << "################################################################" << endl;
		cout << "                           ��1������ͼ��                         " << endl;
		cout << "                           ��2��ɾ��ͼ��                         " << endl;
		cout << "                           ��3����ʾ����                         " << endl;
		cout << "                           ��4����ѯͼ��                         " << endl;
		cout << "                           ��5���޸�ͼ��                         " << endl;
		cout << "                           ��0���˳�ϵͳ                         " << endl;
		cout << "################################################################" << endl;
		cout << "################################################################" << endl;
		cout << endl;
		cout << "����Ҫ���еĲ�����";
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
			cout << "�������" << endl;
			system("pause");
			system("cls");
		}
	}
}

/***********************������**************************/
int main()
{
	read();
	system("color b0");
	menu();
	return 0;
}