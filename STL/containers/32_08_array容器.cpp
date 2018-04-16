// 32_08_array容器.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <array>
#include <iostream>
using std::array;
using std::cout;
using std::endl;

int main()
{

	//与vector不同的是，array对象的长度是固定的，使用了静态存储区，即存储在栈上，效率跟数组相同，但是更加的安全。
	{
		const int n = 5;
		array<int, n> arr = { 1,2,3,4 };
	}


	//array相比于数组最大的优势就是可以将一个array对象赋值给另一个array对象
	{
		std::array<double, 4> ad = { 1.2, 2.1, 3.1, 4.1 };
		std::array<double, 4> ad1;
		ad1 = ad;
	}
	system("pause");
    return 0;
}

