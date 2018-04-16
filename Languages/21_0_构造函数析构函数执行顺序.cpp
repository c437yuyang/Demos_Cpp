// 21_0_构造函数析构函数执行顺序.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;







int main()
{

	//Demo1
	{
		class B
		{
		public:
			B(void)
			{cout << "B\t";}
			~B(void)
			{cout << "~B\t";}
		};
		struct C
		{
			C(void)
			{cout << "C\t";}
			~C(void)
			{cout << "~C\t";}
		};
		struct D : B
		{
			D() { cout << "D\t"; }
			~D() { cout << "~D\t"; }
		private: C c;
		};

		D d; //B C D ~D ~ C ~B
		// 	D继承自B, 基类的构造函数先执行，没有疑问。
		// 	C是D的成员变量，在D的构造函数体开始前(如果在成员初始值列表内就会用成员初始值列表进行呢初始化，否则默认初始化)，会对其进行初始化所以执行C的构造函数。
		// 	最后执行D的构造函数。
		// 	析构函数执行的顺序与构造相反。
	}
	


	//Demo2
	{
		class A1
		{
		public:
			A1() { cout << "A1" << endl; }
			~A1() { cout << "~A" << endl; }
			A1(const A1& a1) { cout << "A1:(const A1&)" << endl; }
		};

		class B1 :public A1
		{
		public:
			B1(A1&a1) :_ra1(a1),_a1(a1)//会调用拷贝构造函数
			{ cout << "B1" << endl; }
			~B1() { cout << "~B1" << endl; }
		private:
			A1& _ra1; //引用就只是复制
			A1 _a1; //
		};
		std::cout << std::endl;
		A1 a;
		B1 b(a);//A1()(父类构造) A1(const A&)(成员变量_a1,拷贝构造) B1(子类构造) ，析构相反顺序就行了
	}


	//demo3
	{
		class B1
		{
		public:
			B1(int i)
			{
				cout << "B1" << " " << i << "&";
			}
		};

		class B2
		{
		public:
			B2()
			{
				cout << "B2" << "&";
			}
		};

		class C :public B1, public B2
		{
		public:
			C(int a, int b, int c) :
				B1(a), //调用B1构造函数，而不是初始化成员变量
				m1(b)
			{ //如果把B1(a)注释掉会报错，因为B1没有默认构造函数，需要显示调用它的构造函数并且传递参数才行


			  //如果你的基类只有无参构造函数，那么，派生类初始化时会默认调用。
			  //如果你的基类中自定义了带参数的构造函数，"必须"在派类构造函数后使用初始化表调用父类构造函数。
			  //所以这里的初始化顺序其实是:两个基类构造函数B1(int),B2(),然后C的初始值列表，m1(b)初始化m1，然后m2默认初始化,然后C的构造函数语句
				indiv = c;
				cout << "C " << indiv << "&";
			}
		private:
			B1 m1;
			B2 m2;
			int indiv;
		};

		C c(1, 2, 3); //B1 1&B2&B1 2&B2&C 3&

	}


	//Demo4
	//当基类构造函数需要外部传递参数才能进行初始化时，派生类必须显式定义构造函数，
	//为基类传递参数；基类如果不需要传递参数，派生类可以不用显式定义构造函数。
	{
		class Parent
		{
		public:
			Parent(int i) :val(i)
			{

			}
			int val;
		};

		class Derived :public Parent
		{
		//public:
		//	//必须定义一个构造函数,并且调用Parent(i)
		//	Derived():Parent(1){}
		//  直接下面这样的话
			//Derived() {} //报错，提示没有可用的默认构造函数

		};
		//Derived d; //如果不定义构造函数去调用Parent(int)的话报错
		//其实不用管那么多，意思就是构造函数并不会被继承。
	}



	system("pause");
	return 0;
}

//总结来说:初始化顺序:
//1.基类构造函数
//2.声明的成员进行初始化，按照声明的顺序，并且回去查找初始值列表中是否有，如果有则调用，没有则默认初始化（所以初始值列表出现，并没有改变初始化的顺序）
//3.自身构造函数内语句