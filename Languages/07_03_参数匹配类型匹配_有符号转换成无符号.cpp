// 24_0_参数匹配_类型转换.cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include <iostream>
using namespace std;

void f1(int a) { cout << a << endl; }
void f1(float a) { cout << a << endl; }

int main()
{
	//f1(0.5); //默认的小数是double类型，既匹配int，也匹配float
	
	f1(0.5f); //正确

	f1(1 + 'a'); //匹配int
	f1('c'); //匹配Int

	//demo1
	{
		int a = 'A' + 1.6; //1.6转型成1，'A'是65，最终66

		int j = 0; //调试占位符而已
	}


	//无符号数与有符号数进行混合运算的时候，有符号数会自动转换成无符号数
	{
		int n = -1;//无符号数:4294967295
		unsigned int i = 10;
		cout << (i < n) << endl; //true,-1转换为无符号数后反而是一个很大的值
	}

	system("pause");
    return 0;
}
