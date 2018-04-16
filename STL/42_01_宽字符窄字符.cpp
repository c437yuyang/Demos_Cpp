// 42_01_宽字符窄字符.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <windows.h>
//#include <WinNls.h> //直接包含windows.h，包含这个要报错
using namespace std;

int main()
{

	//总结:直接用窄字符一样的可以输出正确的非ascii码的值，string类型输出的时候要指定为.cstr()，不然找不到\0
	//但是可以查看string里每一个成员的值就发现其实是有乱码的(printf和cout做了处理)

	//这里只讨论char*和wchar_t*两种数据类型，string和wstring用.cstr()取得一样的操作
	
	char *str = "ab我们cde"; //虽然单看每个字节是乱码，其实是因为采用的是GB2312编码
	wchar_t *wstr = L"ab我们cde"; //宽字符貌似输出都
	
	setlocale(LC_ALL, ""); //必须加这个，宽字符才能正确输出
	printf("%s\n", str);
	printf("%s\n", wstr); //这个不行，只输出a，然后是\0
	printf("%ws\n", wstr); //%ws,%S,%ls都是输出宽字符
	printf("%ls\n", wstr); 
	printf("%S\n", wstr); 
	wprintf(L"%s\n", wstr); //也正常
	wprintf(L"%ls\n", wstr); //也正常

	//因为wchar_t可以用任何encoding的方式来存储字符，比如unicode,ANSI,UCS-2等等
	//而wprintf是直接按照字节顺序输出，所有windows提供了将wchar_t转换成窄字符(多字节表示方式)的函数

	int len = WideCharToMultiByte(CP_ACP, 0, wstr, -1, NULL, 0, NULL, false); //len=10,汉字算两个字符，结尾\0也算一个
	char* strW2A = new char[len];
	if (len != 0) 
	{
		WideCharToMultiByte(CP_ACP, 0, wstr, -1, strW2A, len, NULL, false);
	}
	if(strW2A!=NULL)
		printf("%s\n", strW2A);
	delete[] strW2A;


	system("pause");
    return 0;
}

