#include <iostream>
using namespace std;

class Parent
{
public:
	Parent()
	{
		printInfo(); //���캯��������麯������Ϊ���໹û�г�ʼ����ȫ����˵��õ��ǻ����Լ����麯��
	}
	virtual void printInfo()
	{
		cout << "Parent:PrintInfo" << endl;
	}
};

class Son :public Parent
{
public:
	Son()
	{
		//printInfo(); //����˵�������๹�캯�������麯��������ǿ϶�û���⣬�ܹ��������õ�
		//������Ȼ��������������ã���Ϊ����漰�����ó�Ա�����ݣ���ô��ʱ��Ա��û�б���ȷ��ʼ�����õ����Ǵ����ֵ
	}
	void printInfo() override
	{
		cout << "Son:PrintInfo()" << endl;
	}
};

int main()
{
	Parent *p = new Son();

	delete p;
	p = nullptr;
	system("pause");

	return 0;
}

