// 56_01_对象比较相等.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


#include <vector>
#include <iostream>
class Widget
{
public:
	Widget(int i) :age(i) {}

	bool operator==(const Widget& other)
	{
		return other.age == age;
	}

public:
	int age;

};


int main()
{

	Widget w1(10), w2(10);

	std::cout << std::boolalpha << (w1 == w2) << std::endl; //不实现operator==的情况下是不能进行比较的，C++默认只有那四个函数(ctor,dtor,copying两个)自动生成
	//java等其他语言里面是可以比较的，比较内存地址直接是
	system("pause");

	return 0;
}

