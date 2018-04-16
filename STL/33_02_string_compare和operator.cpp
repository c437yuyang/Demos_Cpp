// 33_02_string_compare和operator.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s1 = "aaab";
	string s2 = "aaaba";

	cout << s1.compare(s2) << endl; //-1，返回的是int类型
	cout << (s1 < s2) << endl;//1 operator<返回的是bool类型
	cout << (s1 <= s2) << endl;//1 operator<=返回的是bool类型

	system("pause");
	return 0;
}

