// 33_01_字符串数字转换.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;


template<class T>
std::string Value2String(const T& val)
{
	std::ostringstream oss;
	oss << val;
	return oss.str();
}

template<class T>
T String2Value(const std::string &str)
{
	return String2Value(str.c_str());
}

template<class T>
T String2Value(const char * str)
{
	std::istringstream iss(str);
	T res;
	iss >> res;
	return res;
}

int main()
{
	char a[10], b[10];
	_itoa_s(21, a, 10);
	_itoa_s(21, b, 2);

	char *d;
	//d = _itoa(10, a, 10);

	cout << a << endl;//21
	cout << b << endl;//01011


	//数字转换成字符串,itoa,sprintf,stringstream,to_string
	char buf[10];
	//sprintf(buf, "%d", 20);
	//cout << buf << endl;

	//字符串转换成数字:stringstream,atoi,stoi(stof,stod)
	size_t size = 10;

	cout << stof(string("1.35"), &size) << endl;// 最简单的直接不要第二个参数,默认size是0

	cout << stoi("01111", &size, 2) << endl; //stoi可以用其他进制,stof不行

	cout << Value2String(1.25) << endl;

	cout << String2Value<float>("1.25") << endl;

	return 0;
}