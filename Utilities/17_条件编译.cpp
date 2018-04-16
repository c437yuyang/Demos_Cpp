// 17_条件编译.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

#define condition1 0

int main()
{

	cout << condition1 << endl;

#if condition1 //只有condition1的值为逻辑真的时候才会执行下面的
	cout << "condition1" << endl;
#endif

#if condition1==0 //condition1的值为逻辑假的时候
	cout << "condition1 假" << endl;
#else				//condition1的值为逻辑真的时候
	cout << "condition1 真" << endl;
#endif


#ifdef condition1
	cout << "condition1 is defined" << endl;
#endif // condition1


#ifndef condition1
	cout << "condition1 is not defined" << endl;
#endif // !condition1




	system("pause");
    return 0;
}
