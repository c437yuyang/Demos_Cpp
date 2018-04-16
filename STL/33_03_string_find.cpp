// 33_03_string_find.cpp : 定义控制台应用程序的入口点。
//



#include "stdafx.h"
#include <string>
#include <iostream>
using namespace std;

int main()
{

	string s1 = "abcde";
	
	cout << (int)s1.find("bcf") << endl; //-1
	cout << (int)s1.find("f") << endl; //-1
	cout << (int)s1.rfind("def") << endl; //-1 
	cout << (int)s1.find_last_of("def") << endl; //4

	//总结，find和rfind是要求完全包含字符串，但是findxxxofxxx只要求包含字符串里任何一个字符，注意of

	string s2 = "E:\\a";
	cout << (int)s2.find("\\/") << endl;
	cout << (int)s2.find_last_of("\\/") << endl;

	system("pause");
    return 0;
}

