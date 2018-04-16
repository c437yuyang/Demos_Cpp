// 39_01_main函数被调用.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

static int time = 0;

int main()
{
	cout << "main " << endl;
	time++;
	if (time > 10) //可以通过static变量或者全局变量来控制
	{
		return 0;
	}
	main(); //可以显式递归调用的
	return 0;
}

