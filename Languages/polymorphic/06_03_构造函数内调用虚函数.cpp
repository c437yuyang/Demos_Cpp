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
		print(); //���Թ��캯���ڵ����麯��������麯���ٵ����麯��,���Կ���������ǵ��õ�Parent�İ汾
		//��Ϊ������Ʊ������֪����������Ƿ�Դ����һ��constructor��
	}
	virtual void print()
	{
		cout << "Parent:print" << endl;
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

	virtual void print() override
	{
		cout << "Son:print" << endl;
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

