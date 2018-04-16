// 37_01_动态分配的数组能否begin和end.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <iterator>
using namespace std;

int main()
{

	int *p = new int[20]();
	int p1[] = { 1,2,34,445 };

	//auto it = begin(p); //报错，看来不能
	auto it1 = begin(p1); //栈上的数组才可以


	system("pause");
    return 0;
}

