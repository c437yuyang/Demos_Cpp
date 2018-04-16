// 34_02_cout的高级用法.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>
using namespace  std;
int main()
{


	bool a = false;

	//指定将bool按照格式输出
	cout << a << endl; //0
	cout << boolalpha << a << endl; // false


	cout << hex << 10 << endl; //a
	cout << showbase << hex << 10 << endl; //0xa
	cout << uppercase <<showbase << hex << 10 << endl; //0xA
	cout << dec << 0x10 << endl; //16
	cout << scientific << 3.14159 << endl; //3.141590e+00
	cout << fixed << 3.14159 << endl; //浮点数格式，没啥变化

	

	cout << nouppercase << "ABbcA" << endl; //不是给这种用的，只有输出数值里面的 0x 和e 的两部分有用


	//设置精度
	double d = 3.141592768;
	cout.precision(3); //3.14
	cout << d << endl;

	system("pause");
    return 0;
}

