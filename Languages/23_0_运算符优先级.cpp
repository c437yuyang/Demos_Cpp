// 23_0_运算符优先级.cpp : 定义控制台应用程序的入口点。
//


#include "stdafx.h"
#include <iostream>
using namespace std;


//基本的优先等级需要牢记：指针最优，单目运算高于双目运算，
// 先乘除（取模），后加减，先算数运算，后移位，最后位运算
// ，逻辑运算最最后。相同优先级按结合顺序计算，大多数从左向右，
// 只有单目运算符、条件运算符、赋值运算符是自右向左结合。
//该题中算术运算符*优先级高于赋值运算符 += 和 -= ，
// 所以先算2 * 2 = 4，然后赋值运算符是自右向左结合的，
// 先运算n -= 4即n = n - 4即n = 2 - 4 = -2，
// 然后运算n += -2即n = n + （ - 2） = -2 - 2 = -4.所以选 - 4，答案貌似没有

int main()
{

	{
		//*p++ == *(p++)的，++优先级更高 
	}

	{

	}
	//http://blog.csdn.net/nicky_zs/article/details/4053146
	cout << (5 > 2 > 7 > 8) << endl; //左到右的结合方向，所以0


	int x = 10;
	x += x -= x - x; //从右往左
	cout << x << endl; //20  

	int n = 2;
	n += n -= n*n;
	cout << n << endl;// -4


	//
	{
		struct t
		{
			int x; int *y;
		}*p;
		int a[] = { 1,2 };
		int b[] = { 3,4 };
		struct t c[2] = { 5,a,6,b };
		p = c;
		printf("%d,%d", *(p->y), ++(*p).x); //() , . , ++
	}

  //结合逻辑运算符Demo
	{
		int a = 3, b = 4, c = 5;
		int i = !(a + b) + c - 1 && b + c / 2; //&&(逻辑运算符优先级最低)
		//先(a+b)在取非，再+c-1  右边先b+c/2  最后与
		cout << i << endl; //1
	}

	system("pause");
	return 0;
}
