// 18_01_继承保护级别不同的成员.cpp : 定义控制台应用程序的入口点。
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
	//void printfInfo() { cout << A::age << endl; } //不能访问
	void printfInfo() { cout << age << endl; } //输出的就是自己的age
};


int main()
{

	B b;
	b.printfInfo();
	A a;
	a.printfInfo(); //若B不实现printInfo方法，输出都是1，可以看到 printInfo在哪个类，输出的就是哪个类的age

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
		b.print(); //和上面一样print在哪个类，输出的就是哪个类的_a
		printf("%d",b._a);
	}


	system("pause");
	return 0;
}
