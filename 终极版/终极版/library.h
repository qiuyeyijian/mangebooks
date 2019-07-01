#pragma once
class Library
{
public:
	Library() {  }
	void addBook();                //向图书馆里加书籍
	void addBook(string name, string num, string auther);
	void deleteBook();              //删除无用书籍
	void searchbooks();             //查询某编号的书
	void fixbooks();                //修改某编号的书籍
	int indexOfNum(string num);     //根据编号得到书在数组中的下标
	vector<Book> getBooks() {
		return books;
	}
	friend void read();
	void showInfo();
private:
	vector<Book> books;       //定义一个容器，包含所有书籍
};


void Library::showInfo()
{
	cout << "***************************************************************" << endl;
	cout << "***************************************************************" << endl;
	cout << "$$$$$$$$$$$$              所有图书信息               $$$$$$$$$$$$" << endl;
	cout << "****************************************************************" << endl;
	cout << "***************************************************************" << endl;
	for (int i = 0; i < (int)books.size(); i++)
	{
		cout << "第" << i + 1 << "本书籍的信息。" << endl;
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
	cout << "$$$$$$$$$$$$                增加界面                $$$$$$$$$$$$" << endl;
	cout << "****************************************************************" << endl;
	cout << "***************************************************************" << endl;
	do {
		cout << "输入书籍名称:";
		cin >> name;
		cout << "输入书籍作者：";
		cin >> auther;
		cout << "输入书籍编号：";
		cin >> num;
		b.setInfo(name, num, auther);
		if (indexOfNum(num) == -1) {
			books.push_back(b);
			cout << "\n添加成功。" << endl;
			cout << "输入1继续增加：";
			cin >> temp;
		}
		else {
			cout << "已存在该编号的书籍，添加失败。" << endl;
			cout << "输入1继续重新增加：";
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
	cout << "$$$$$$$$$$$$                删除界面                $$$$$$$$$$$$" << endl;
	cout << "****************************************************************" << endl;
	cout << "***************************************************************" << endl;
	do {
		cout << "输入要删除的书籍的编号：";
		cin >> num;
		index = indexOfNum(num);
		if (index != -1) {
			cout << "删除的书籍的信息：\n";
			books[index].showInfo();
			books.erase(books.begin() + index);
			cout << "删除成功。" << endl;
			cout << "输入1继续继续删除：";
			cin >> temp;
		}
		else
		{
			cout << "删除失败。未找到编号为" << num << "的书籍。\n";
			cout << "输入1继续继续删除：";
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
	cout << "$$$$$$$$$$$$                查询界面                $$$$$$$$$$$$" << endl;
	cout << "****************************************************************" << endl;
	cout << "***************************************************************" << endl;
	cout << "输入要查找的书籍编号：";
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
		cout << "查询失败，请检查书籍编号是否输入错误！\n";
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
	cout << "$$$$$$$$$$$$                修改界面                $$$$$$$$$$$$" << endl;
	cout << "****************************************************************" << endl;
	cout << "***************************************************************" << endl;
	do {
		cout << "输入要修改的书籍的编号：";
		cin >> num;
		index = indexOfNum(num);
		if (index != -1) {
			cout << "要修改的书籍的信息：\n";
			books[index].showInfo();
			cout << "开始修改：" << endl;
			cout << "输入书籍名称:";
			cin >> name;
			cout << "输入书籍作者：";
			cin >> auther;
			books[index].fixInfo(name, auther);
			cout << "修改成功。" << endl;
			cout << "输入1继续继续修改：";
			cin >> temp;
		}
		else
		{
			cout << "修改失败。未找到编号为" << num << "的书籍。\n";
			cout << "输入1继续继续修改：";
			cin >> temp;
		}
	} while (temp == 1);
	system("pause");
	system("cls");
}
