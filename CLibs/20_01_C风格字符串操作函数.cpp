// 20_01_C风格字符串操作函数.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string.h>
#include <iostream>
using namespace std;

int main()
{
	char *s1 = "abcde";
	char s2[] = "aaaaaaa";


	strcpy(s2, s1); //拷贝过去过后，会在后面加上\0

	char s3[10] = "z\0zzzzz";

	strcat(s3, s1); //strcat 把字符串连接到上一个字符串首个\0的位置,连接完成后，会在最后加上\0，其实倒也不是加上\0，因为你str2本身最后就有\0

	cout << s1 << endl;
	cout << s3 << endl;
	system("pause");
    return 0;
}

