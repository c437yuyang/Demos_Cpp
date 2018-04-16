#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
//void f(int n);
int main()
{
#pragma region 关键字相关
	//ifelse分支问题
	{
		int k1, k2, k3, x;
		k1 = 1;
		k2 = 2;
		k3 = 3;
		x = 15;
		if (!k1) //分支语句每一条是同等的，进了一个就不能再进同一级的分支，所以这里是直接走的else if，没有再走else了
			x--;
		else if (k2)
			x = 4;
		else
			x = 3;
	}

	//switch,default放在前面也会最后执行
	{
		int n = 'c';
		switch (n++)
		{
		default:
			printf("error");
			break; //这里测试是不会执行的了。。
		case 'a':
		case 'A':
		case 'b':
			printf("ab");
			break;
		case 'c':
		case 'C':
			printf("c");
		case 'd':
		case 'D':
			printf("D");
		}
		printf("\n");
	}

	{
		if (4 > 3 > 2) //可以这样用，不过从左到右，4>3 = true true转成1 > 2 ->false 所以不能进if
		{
			cout << "aa" << endl;
		}
	}

	//break后for不会再执行i++
	{
		//int i;
		//for (i=0;i!=8;++i)
		//{
		//	if(i==1) break;
		//}
	}

	{ //取反是连着符号位一起取反的
		int i = 1;
		int j = ~i; //符号位也反了，变成了负数
	}

	//移位运算符:
	{
		//1.负数右移运算高位补1
		//2.运算对象可以是整形或者字符型(这里的整形包含了很多，比如long,short这些都是，其实就是除了double这种前几位是表示指数，后面表示实际的这种表示方法都是可以移位运算符的)
		//3.按位取反只需要一个操作数，其他位运算符是两个操作数
		char a = 'a';
		a << 1;
		unsigned short b = 1;
		b << 1;
	}

	{ //逻辑真值，只要是非0值就可以，double,float都行，不需要是整数
		double d = 1.1;
		if (d)
			cout << "not zero" << endl;
	}

	//无符号数和有符号数
	{
		cout << endl;
		unsigned int i = -2147483647 - 1;
		float a = 0.0;
		//a-1
		unsigned int c = 1u - 2u; //两个无符号数相减，如果小于0，则会产生溢出，这里就成了基本上是最大的无符号数了
		bool b = 1u - 2u < 0;	 //false

		printf("%u\n", i);
	}

	//函数不能嵌套定义
	{
		//void printInfo() { cout << " " << endl; } //报错
	}

	//i++带来的未定义行为:
	//没有指定执行顺序的运算符来说，如果表达式指向并修改了同一个对象，将引发错误并产生未定义的行为。
	{
		int i = 0;
		i = i++;				  //这里是一个未定行为 ，取决于编译器先执行i++返回了当前值之后的自加还是=号
		cout << i << ++i << endl; //也是未定义行为，不知道是先++i还是先i
	}

	{//指针变量直接由整数赋值
		int *i = (int *)1; //但是不能用整数赋值，类型不同，强制转换成(int *)是可以的
		*i = 10; //报错，不能对这种进行赋值
	// int *i = 0; //可以为0，就是NULL
	}

#pragma endregion

	{
		//字符串可以放在除了字符数组之外的数组？
		//答案可以

		class Widget
		{
		  public:
			Widget(const char *str) : _str(str) {}
			string _str;
		};

		Widget w[2] = {"a", "b"};
	}

	//f(5);

	{ //在C语言中变量或函数可以重复声明，但是不能重复定义
		//声明在内部，则这个声明只有内部作用域有效
		void f(int n);
		f(5);
	}
	//f(5); //也不能访问到内部作用域的f

	//C++不允许对内置类型的临时变量进行修改
	{
		int *func();
		//int *p = --func(); // 报错，C++不允许对内置类型的临时变量进行修改
	}
	::system("pause");
	return 0;
}

void f(int n)
{
	printf("%d\n", n);
}
