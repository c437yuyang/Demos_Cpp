// 18_01_�̳б�������ͬ�ĳ�Ա.cpp : �������̨Ӧ�ó������ڵ㡣
//
#include <iostream>
using namespace std;

class A {
private:
	
	int age = 1;
public:
	
	void printfInfo() { cout << age << endl; }
};

class B :public A {

private:
	int age = 2;

public:
	//void printfInfo() { cout << A::age << endl; } //���ܷ���
	void printfInfo() { cout << age << endl; } //����ľ����Լ���age
};


int main()
{

	B b;
	b.printfInfo();
	A a;
	a.printfInfo(); //��B��ʵ��printInfo�������������1�����Կ��� printInfo���ĸ��࣬����ľ����ĸ����age

	//Demo2
	{
		class A{
			public:int _a;
			A(){
				_a = 1;
			}
			void print(){printf("%d ",_a);}
		};
		class B:public A{
			public:int _a;
			B(){
				_a = 2;
			}
		};
		B b;
		b.print(); //������һ��print���ĸ��࣬����ľ����ĸ����_a
		printf("%d",b._a);
	}


	system("pause");
	return 0;
}
