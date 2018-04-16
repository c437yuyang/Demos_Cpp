// 42_02_char_traits.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string>
#include <assert.h>
#include <iostream>
//char_traits定义了字符间的交互方式，比如提供eq,lt,compare和find四个函数，其实提供的还很多，具体可以F12看源码
//下面的例子实现一个大小写不敏感的ci_string类

struct ci_char_traits :public std::char_traits<char>
{
	static bool eq(char c1, char c2)
	{
		return toupper(c1) == toupper(c2) || tolower(c1) == tolower(c2);
	}
	static bool lt(char c1, char c2)
	{
		return toupper(c1) < toupper(c2);
	}
	static int compare(const char *s1, const char *s2,size_t n)
	{
		return _memicmp(s1, s2, n);
	}
	static const char * find(const char*s, int n, char a)
	{
		while (n-- > 0 && toupper(*s) != toupper(a))
		{
			++s;
		}
		return n >= 0 ? s : 0;
	}

	//std::ostream& operator<<(std::ostream & os) //因为std::cout 实际上是 std::basic_ostream<char,std::char_traits<char>>，因此这个类不能用cout来输出(也可以用.c_str()来实现)，所以得自己改写
	//{
	//	//具体实现不管，只看这个流程
	//}

};
typedef std::basic_string<char, ci_char_traits> ci_string;

std::ostream& operator<<(std::ostream & os,ci_string str)
{
	return os << str.c_str(); //这里必须调用 os << str.c_str()才行，直接调用os << str 之所以不报错，是因为递归调用自身了
}


//当然，这里只是演示这个的使用，实际上不适合把这个大小写不敏感性作为对象的属性来实现，比如stricmp也是作为函数的属性来实现的(具体看书上的例子)
int main()
{

	ci_string s1 = "abcde";
	ci_string s2 = "ABCde";

	assert(s1 == s2);
	std::cout << s1 << std::endl; //



	system("pause");
    return 0;
}

