#pragma once
class Book
{

	string name;            //����
	string num;            //��ţ�Ψһ��ʾ��
	string auther;          //����
public:
	Book() {  }   //�޲ι��캯��
	Book(string name, string num, string auther)
		:name(name), num(num), auther(auther) {
	}  //�вι��캯��
	void setInfo(string name, string num, string auther); //�����鼮��Ϣ
	string getName() {
		return name;
	}
	string getNum() { return num; }
	string getAuther() {
		return auther;
	}
	void showInfo();        //��ʾ������Ϣ
	void fixInfo(string p_name, string p_auther);

};


/***********************�����鼮��Ϣ����ʵ��**************************/
void Book::setInfo(string p_name, string p_num, string p_auther)
{
	name = p_name;
	num = p_num;
	auther = p_auther;
}
/***********************չʾ�鼮��Ϣ����ʵ��**************************/
void Book::showInfo()
{
	cout << "###############################" << endl;
	cout << "###############################" << endl;
	cout << "## �鼮��ţ�" << setiosflags(ios_base::left) << setw(56) << num << endl
		<< "## �鼮���ƣ�" << setw(56) << name << endl
		<< "## �鼮���ߣ�" << setw(56) << auther << endl;
	cout << "###############################" << endl;

}
/***********************�޸��鼮��Ϣ����ʵ��**************************/
void Book::fixInfo(string p_name, string p_auther)
{
	name = p_name;
	auther = p_auther;
}
