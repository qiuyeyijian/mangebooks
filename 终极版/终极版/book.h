#pragma once
class Book
{

	string name;            //书名
	string num;            //编号（唯一标示）
	string auther;          //作者
public:
	Book() {  }   //无参构造函数
	Book(string name, string num, string auther)
		:name(name), num(num), auther(auther) {
	}  //有参构造函数
	void setInfo(string name, string num, string auther); //设置书籍信息
	string getName() {
		return name;
	}
	string getNum() { return num; }
	string getAuther() {
		return auther;
	}
	void showInfo();        //显示数据信息
	void fixInfo(string p_name, string p_auther);

};


/***********************设置书籍信息函数实现**************************/
void Book::setInfo(string p_name, string p_num, string p_auther)
{
	name = p_name;
	num = p_num;
	auther = p_auther;
}
/***********************展示书籍信息函数实现**************************/
void Book::showInfo()
{
	cout << "###############################" << endl;
	cout << "###############################" << endl;
	cout << "## 书籍编号：" << setiosflags(ios_base::left) << setw(56) << num << endl
		<< "## 书籍名称：" << setw(56) << name << endl
		<< "## 书籍作者：" << setw(56) << auther << endl;
	cout << "###############################" << endl;

}
/***********************修改书籍信息函数实现**************************/
void Book::fixInfo(string p_name, string p_auther)
{
	name = p_name;
	auther = p_auther;
}
