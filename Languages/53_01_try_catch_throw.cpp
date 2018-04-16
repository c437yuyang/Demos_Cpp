// 53_01_try_catch.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stack>
#include <iostream>
using std::stack;


int main()
{

	stack<int> s;
	s.push(1);

	s.pop();
	//s.pop(); //这时VS会报assertion failed 如果继续的话，就会提示触发了一个断点。
	//如果是release的话就不会报错。。。


	
	try //try住的话也不行，如果是其他语言比如C# 就是抛出的异常。说明STL的实现不是通过异常的
	{
		//s.pop(); //stl中Pop都是不返回值的，都是得自己去用top获取，为了异常安全性，具体参加exceptional c++  条款10
		////虽然C#和java中的pop都是可以直接返回的、
		//s.top(); //可以看到top返回的是引用，所以内部的实现中
	}
	catch (...)
	{
		throw;
	}

	//测试throw
	{
		if (true)
		{
			throw "aa"; //throw的时候会弹出提示框(貌似只有debug可以)，如果点继续则会继续执行，如果点中断就不会了
		}
		std::cout << "aaa" << std::endl; //
	}

    return 0;
}

