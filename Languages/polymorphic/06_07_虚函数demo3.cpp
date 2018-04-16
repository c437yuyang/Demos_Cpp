// 06_虚函数测试4.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class Base
{
public:
	Base(int j) : i(j) {}
	virtual~Base() {}
	void func1()
	{
		i *= 10;
		func2();
	}
	int getValue()
	{
		return  i;
	}
protected:
	virtual void func2()
	{
		i++;
	}
protected:
	int i;
};
class Child : public Base
{
public:
	Child(int j) : Base(j) {}
	void func1()
	{
		i *= 100;
		func2();
	}
protected:
	void func2()
	{
		i += 2;
	}
};
int main()
{
	Base * pb = new Child(1);
	pb->func1(); //func1()不是虚函数，所以调用父类的func1()
				 //func1()里面调用func2()，由于func2()是虚函数，所以就调用子类的func2了
				//其实这样理解:这个函数的调用者是一个指针，所以到哪一步能够多态，就会产生多态效果，而跟所处的环境是没有关系的
	delete pb;
}

