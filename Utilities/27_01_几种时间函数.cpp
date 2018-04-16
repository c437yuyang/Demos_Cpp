// 27_01_时间函数.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <time.h>
#include <iostream>
#include <windows.h>
int main()
{
	time_t t;
	time_t time1;
	t = clock();//就是该程序从启动到函数调用占用CPU的时间
	time(&time1); //为获取系统时间
	localtime(&time1);  //将一个UTC时间转为本地时间，还是一个整数

	GetTickCount();

	system("pause");
    return 0;
}

