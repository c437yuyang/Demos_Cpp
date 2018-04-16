// 06_构造函数内调用虚函数.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class Parent
{
public:
	Parent()
	{
		printInfo(); //构造函数里调用虚函数，因为基类还没有初始化完全，因此调用的是基类自己的虚函数
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
		printInfo();
	}
	void printInfo()override
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

