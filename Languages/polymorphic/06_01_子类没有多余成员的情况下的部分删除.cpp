// 06_多态_子类没有多余成员的情况下的部分删除.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
//第一步：在程序里定下一下宏（建议定义在stdafx.h头文件中）
#ifdef _DEBUG
//for memory leak check
#define _CRTDBG_MAP_ALLOC //使生成的内存dump包含内存块分配的具体代码为止
#include <stdlib.h> 
#include <crtdbg.h>
#define CheckMemoryLeak _CrtSetDbgFlag( _CrtSetDbgFlag( _CRTDBG_REPORT_FLAG )| _CRTDBG_LEAK_CHECK_DF)
#endif 

//总结:子类即使在没有需要专门写析构函数的成员的情况下，父类也必须声明虚析构函数，否则直接delete指向子类的父类指针还是会报错

using namespace std;
class A
{
public:
	virtual void f()
	{
		printf("A\n");
	}
	//virtual void f() = 0;
	virtual ~A() {
		cout << "~A()" << endl;
	}
};

class B : public A
{
public:
	void f()
	{
		printf("B\n");
	}
	~B() {
		cout << "~B()" << endl;
	}

};

int main()
{
#ifdef _DEBUG
	CheckMemoryLeak;
#endif
	A *a = new B;
	a->f();
	delete a; //只有基类声明了虚析构函数才会调用子类的析构函数

	system("pause");
	return 0;
}
