// 43_01_allocator.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <memory>
#include <string>
using namespace std;

class Widget
{
public:
	Widget(int id1) :id(id1) { cout << "Widget ctor" << endl; }
	~Widget() { cout << "Widget dtor" << endl; }

	void printInfo() { cout << "Widget:" << id << endl; }
	int id;
};

int main()
{
	//系统标准allocator的使用
	allocator<Widget> waloc;
	Widget *const p = waloc.allocate(10); //先分配内存，原始内存，未构造，分配了10个widget大小的内存
	auto q = p;
	waloc.construct(q++, 1); //已有内存的情况下构造对象
	waloc.construct(q++, 2);
	waloc.construct(q++, 3);

	for (int i = 0; i != 3; ++i)
	{
		p[i].printInfo();
	}

	q = p;
	waloc.destroy(q++); //destroy只是把对象析构了，内存没有释放(可以看自己析构函数做了什么就知道了)
	waloc.destroy(q++);
	waloc.destroy(q++);

	//析构了还是可以输出(对象还在)？
	for (int i = 0; i != 3; ++i)
	{
		p[i].printInfo();
	}
	q = p;
	waloc.construct(q++, 4);
	waloc.construct(q++, 5);
	waloc.construct(q++,6);

	for (int i = 0; i != 3; ++i)
	{
		p[i].printInfo();
	}

	waloc.deallocate(p, 10);  //deallocate才是释放内存

	for (int i = 0; i != 3; ++i) //释放了内存在输出就是错误的了
	{
		p[i].printInfo();
	}
	system("pause");
	return 0;
}



