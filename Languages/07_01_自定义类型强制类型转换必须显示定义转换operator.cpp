// 07_01_强制类型转换.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class Widget
{
public:
	int _val = 1;
	operator int()// 必须定义了运算符才能够强制转换，隐式转换的话就是有一个非explicit的构造函数，接受一个int类型的参数
	{
		return _val;
	}
};

int main()
{
	Widget w;
	int i = static_cast<int>(w);
	cout << i << endl;


    return 0;
}

