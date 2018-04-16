// 25_0_类型极值.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

constexpr int size1(int i) //
{
	return i*i;
}

int main()
{
	int arr[size1(3)];
	const int i = 3;
	int arr1[i*i];

	short s1 = 65537; //short最大表示65535(2进制全部1),65536(2进制全部0,溢出)就是0,65537就是1
	cout << s1 << endl; //1
	s1 = 32767; //最大正数，除了符号位，全部1
	s1 = 32768; //最小负数，符号位1，全部0，-32768

	short s2 = 65535; //65535是所有位全部为1，就是-1
	cout << s2 << endl; //输出的时候，编译器知道认为是signed类型，所以第一位当符号位，输出-1

	unsigned short s3 = 65535;
	cout << s3 << endl; //65535

	system("pause");
    return 0;
}
