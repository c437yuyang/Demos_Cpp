// 06_虚函数测试5_访问控制符和虚函数.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class Base
{
public:
	virtual void printInfo()
	{
		cout << "base" << endl;
	}

private:
	void printInfo1()
	{
		cout << "base1" << endl;
	}
	virtual void printInfo2()
	{
		cout << "Base:printInfo2()" << endl;
	}

};

class Drived :public Base
{
private:
	void printInfo() override
	{
		cout << "Drived" << endl;
	}
public:
	void printInfo1()
	{
		cout << "Drived1" << endl;
	}
	virtual void printInfo2()
	{
		cout << "derived:printInfo2()" << endl;
	}

};

int main()
{

	//结论:访问控制符与虚函数相结合的时候，不影响虚函数或者访问控制符本身的作用，是啥样就是啥样
	//只是编译时的静态类型取决于父类，因此父类至少得具有访问性才行，子类可能会被破坏封装性。(如printInfo的使用)
	//尽量让父类和子类虚函数的访问性一致应该。



	Base *p = new Drived;
	p->printInfo(); //Derived
					//父类是public，子类是private,通过这种虚函数的方式，能够调用到子类private的方法
	//p->printInfo1(); //报错，父类是private,根本不让访问

	//p->printInfo2(); //报错，父类是private，不让访问，这时p指针找到这个函数的静态函数类型是父类的，遵循父类的标准，因此根本到不了运行时去调用子类的(编译不过)



	system("pause");
	return 0;
}

