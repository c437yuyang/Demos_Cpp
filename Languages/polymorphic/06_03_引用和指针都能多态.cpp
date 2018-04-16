// 06_虚函数测试3_引用和指针.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;


class  A
{
public:
	virtual void  printInfo() { cout << "Baseed" << endl; }
private:

};

class B:public A
{
public:
	void  printInfo() { cout << "Extented" << endl; }
private:

};



int main()
{
	A a;
	B b;
	A &refA = b;
	A *pA = &b; //可以看到指针和引用都会产生多态效果
	//vector
	refA.printInfo();
	pA->printInfo();

	system("pause");
    return 0;
}
