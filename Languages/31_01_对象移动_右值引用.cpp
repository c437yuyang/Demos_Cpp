// 31_对象移动_右值引用.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <string>
#include <iostream>
using namespace std;

void f(int& i) { std::cout << "lvalue ref: " << i << "\n"; }
void f(int&& i) { std::cout << "rvalue ref: " << i << "\n"; }




int main()
{
	int i = 1;
	int &r3 = i; //左值引用绑定到表达式(左值)上
	int &&r1 = 42; //右值引用绑定到常量，返回右值的表达式
	int &&r2 = i * 42;
	const int &r4 = 42 * i; //const左值引用可以指向常量

	//可以强制让右值引用绑定到左值上
	int &&r5 = std::move(i);

	cout << r1 << endl;

	{
		//http://blog.csdn.net/wangshubo1989/article/details/49745781
		int i = 77;
		f(i);    // lvalue ref called
		f(99);   // rvalue ref called

		f(std::move(i));  // 显式调用右值版本
		//如果一个表达式的结果是一个暂时的对象，那么这个表达式就是右值
		//如:
		vector<string> v;
		v.push_back(string("aa")); //其中这个临时对象string("aa")就是右值的，调用的push_back也是右值版本的
	}

	

	system("pause");
    return 0;
}

