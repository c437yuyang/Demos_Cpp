// 46_ascii转义字符.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{

	char *str1 = "\1\11\9"; //可以看到，第二个\11表示的是\t，查表发现是9，而且下面的\011也是\t，说明这里面默认是使用八进制来表示的
	char *str3 = "\1\0119"; //\9就是9
	cout << str1 << endl;

	char *str2 = "\001\011\009";
	cout << str2 << endl;

	char s[] = "\\123456\123456\t";
	printf("%d\n", strlen(s)); //12 ,\123代表一个字符

	char a = '\72'; //按照8进制算
	
	{
		char a = 'a';
		char a1 = '\8';
		'\8' == '8';//true
		char a2 = '\82'; //虽然这里编译正确，但是实际上是错的值最后，这里生成一个0x003832,最后赋值只赋了0x32,切割
		char a3 = 82; //这样才是正确的，指定一个小于等于127的数就行了
	}

	//根据ascii表:输入ctrl+@就是\0就会退出
	//输入回车是\n(换行符) 10
	// 输入ctrl+m 就是输入回车  最后得到的也是10  反映出来就是一个换行符，其实是一个\r（回车）
	while (char c = getchar())
	{
		cout << (int)c << endl;
	}

	system("pause");
    return 0;
}


//总结:
//链接：https://www.nowcoder.com/questionTerminal/055bba09489348439fac5c76ed9c98d8
//来源：牛客网
//转移字符分三种，一般转义字符，八进制转移字符和十六进制转移字符
//转义字符以反斜线'\'开头，后面可以跟三种形式： 
//1. 一个字符。如：char c1 = '\t'  //也就是一般转义字符
//2. 一个八进制数。如：char c2 = '\110'，所以要表示\1的话应该用\001
//3. 一个十六进制数。如：char c3 = '\x0d'
