// 22_0_������ʹ��麯��.cpp : �������̨Ӧ�ó������ڵ㡣
//
#include <iostream>
#include <string>
using namespace std;

class A
{
  public:
	virtual void printInfo() = 0;
	void printName() { cout << name << endl; }
	string name = "yxp";
};

class B : public A
{
  public:
	B() { this->name = "yxp,B"; }
	void printInfo()
	{
		A::printInfo(); //���Ҵ��麯�����Ա����ã���̬����(��ΪҲ��ʼ�����˶���)һ��
		cout << this->name << endl;
	}
};

void A::printInfo() //���麯��Ҳ�����ж��壬ֻ�ǲ���������
{
	std::cout << "A::printName()" << std::endl;
}

int main()
{

	//A a; //���д��麯��������������࣬��������������Ķ��󣬲������ڷ���ֵ�Ͳ���(����ָ�������)

	//ֻ������ָ�룬����ָ�������࣬ʵ�ֶ�̬

	A *a = new B;
	a->printInfo();
	system("pause");

	return 0;
}
