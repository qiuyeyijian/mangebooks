#pragma once
class Library
{
public:
	Library() {  }
	void addBook();                //��ͼ�������鼮
	void addBook(string name, string num, string auther);
	void deleteBook();              //ɾ�������鼮
	void searchbooks();             //��ѯĳ��ŵ���
	void fixbooks();                //�޸�ĳ��ŵ��鼮
	int indexOfNum(string num);     //���ݱ�ŵõ����������е��±�
	vector<Book> getBooks() {
		return books;
	}
	friend void read();
	void showInfo();
private:
	vector<Book> books;       //����һ�����������������鼮
};


void Library::showInfo()
{
	cout << "***************************************************************" << endl;
	cout << "***************************************************************" << endl;
	cout << "$$$$$$$$$$$$              ����ͼ����Ϣ               $$$$$$$$$$$$" << endl;
	cout << "****************************************************************" << endl;
	cout << "***************************************************************" << endl;
	for (int i = 0; i < (int)books.size(); i++)
	{
		cout << "��" << i + 1 << "���鼮����Ϣ��" << endl;
		books[i].showInfo();
	}
	system("pause");
	system("cls");
}
int Library::indexOfNum(string num)
{
	int i;
	for (i = 0; i < (int)books.size(); i++)
	{
		if (books[i].getNum() == num)
			return i;
	}
	return -1;
}
void Library::addBook()
{
	Book b;
	int temp;
	string name, num, auther;
	cout << "***************************************************************" << endl;
	cout << "***************************************************************" << endl;
	cout << "$$$$$$$$$$$$                ���ӽ���                $$$$$$$$$$$$" << endl;
	cout << "****************************************************************" << endl;
	cout << "***************************************************************" << endl;
	do {
		cout << "�����鼮����:";
		cin >> name;
		cout << "�����鼮���ߣ�";
		cin >> auther;
		cout << "�����鼮��ţ�";
		cin >> num;
		b.setInfo(name, num, auther);
		if (indexOfNum(num) == -1) {
			books.push_back(b);
			cout << "\n��ӳɹ���" << endl;
			cout << "����1�������ӣ�";
			cin >> temp;
		}
		else {
			cout << "�Ѵ��ڸñ�ŵ��鼮�����ʧ�ܡ�" << endl;
			cout << "����1�����������ӣ�";
			cin >> temp;
		}
	} while (temp == 1);
	system("pause");
	system("cls");
}
void Library::addBook(string name, string num, string auther)
{
	Book b;
	b.setInfo(name, num, auther);
	books.push_back(b);
}
void Library::deleteBook()
{
	int index, temp;
	string num;
	cout << "***************************************************************" << endl;
	cout << "***************************************************************" << endl;
	cout << "$$$$$$$$$$$$                ɾ������                $$$$$$$$$$$$" << endl;
	cout << "****************************************************************" << endl;
	cout << "***************************************************************" << endl;
	do {
		cout << "����Ҫɾ�����鼮�ı�ţ�";
		cin >> num;
		index = indexOfNum(num);
		if (index != -1) {
			cout << "ɾ�����鼮����Ϣ��\n";
			books[index].showInfo();
			books.erase(books.begin() + index);
			cout << "ɾ���ɹ���" << endl;
			cout << "����1��������ɾ����";
			cin >> temp;
		}
		else
		{
			cout << "ɾ��ʧ�ܡ�δ�ҵ����Ϊ" << num << "���鼮��\n";
			cout << "����1��������ɾ����";
			cin >> temp;
		}
	} while (temp == 1);
	system("pause");
	system("cls");
}
void Library::searchbooks()
{
	string num;
	cout << "***************************************************************" << endl;
	cout << "***************************************************************" << endl;
	cout << "$$$$$$$$$$$$                ��ѯ����                $$$$$$$$$$$$" << endl;
	cout << "****************************************************************" << endl;
	cout << "***************************************************************" << endl;
	cout << "����Ҫ���ҵ��鼮��ţ�";
	cin >> num;
	int index;
	index = indexOfNum(num);
	if (index != -1)
	{
		books[index].showInfo();
		system("pause");
		system("cls");
	}
	else
	{
		cout << "��ѯʧ�ܣ������鼮����Ƿ��������\n";
		system("pause");
		system("cls");
	}
}

void Library::fixbooks()
{
	int index, temp;
	string num;
	string name, auther;
	cout << "***************************************************************" << endl;
	cout << "***************************************************************" << endl;
	cout << "$$$$$$$$$$$$                �޸Ľ���                $$$$$$$$$$$$" << endl;
	cout << "****************************************************************" << endl;
	cout << "***************************************************************" << endl;
	do {
		cout << "����Ҫ�޸ĵ��鼮�ı�ţ�";
		cin >> num;
		index = indexOfNum(num);
		if (index != -1) {
			cout << "Ҫ�޸ĵ��鼮����Ϣ��\n";
			books[index].showInfo();
			cout << "��ʼ�޸ģ�" << endl;
			cout << "�����鼮����:";
			cin >> name;
			cout << "�����鼮���ߣ�";
			cin >> auther;
			books[index].fixInfo(name, auther);
			cout << "�޸ĳɹ���" << endl;
			cout << "����1���������޸ģ�";
			cin >> temp;
		}
		else
		{
			cout << "�޸�ʧ�ܡ�δ�ҵ����Ϊ" << num << "���鼮��\n";
			cout << "����1���������޸ģ�";
			cin >> temp;
		}
	} while (temp == 1);
	system("pause");
	system("cls");
}
