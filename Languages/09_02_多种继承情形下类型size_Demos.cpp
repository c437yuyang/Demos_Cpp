// 09_02_各种继承的size.cpp : 定义控制台应用程序的入口点。
//

#include <iostream>
#include <assert.h>
using namespace std;

//https://blog.csdn.net/u013630349/article/details/47057929

//【Exp.002-多重继承】

int main()
{

	{
		class A
		{
		}; //1
		class A1
		{
		}; //1
		class B : public A, public A1
		{

		}; //1
		assert(sizeof(A)==sizeof(A1)==sizeof(B)==1);
	}

	{
		//【Exp.001-虚继承】
		class A
		{
		  public:
			int a;
		}; //sizeof(A)=4

		class B : virtual public A
		{
		  public:
			int b;
		}; //sizeof(B)=4(A副本)+4(虚表指针)+4(自己变量)=12

		class C : virtual public B
		{
		}; //sizeof(c)= 12(B副本)+4(虚表指针) = 16，如果这里改为直接继承，那么sizeof(c)=12

		printf("%d\n", sizeof(C));
		//解析：这里需要理解虚继承基类对派生类的空间大小的影响，理解虚指针在虚继承中为子类带来了哪些空间的改变。
	}

	//【Exp.002-多重继承】
	{
		class A
		{
		  public:
			int a;
		}; //sizeof(A) = 4

		class B : virtual public A
		{
		}; // sizeof(B) =4(A副本)+4(虚表指针)=8

		class C : virtual public A
		{
		}; //sizeof(C) =4+4=8

		class D : public B, public C
		{
		};
		//sizeof(D)=8+8-4=12 这里需要注意要减去4，因为B和C同时继承A，只需要保存一个A的副本就好了，sizeof(D)=4(A的副本)+4(B的虚表)+4(C的虚表)=12
		printf("%d\n", sizeof(D));
		//解析：这里需要关注 class D 的数据空间大小，理解多重虚继承对派生类虚指针以及派生类空间的影响。
	}

	//【Exp.003-普通继承（含有：空类、虚函数）】
	{
		class A
		{
		};

		class B
		{
			char ch;
			virtual void func0() {}
		};

		class C
		{
			char ch1;
			char ch2;
			virtual void func() {}
			virtual void func1() {}
		};

		class D : public A, public C
		{
			int d;
			virtual void func() {}
			virtual void func1() {}
		};

		class E : public B, public C
		{
			int e;
			virtual void func0() {}
			virtual void func1() {}
		};

		cout << "A=" << sizeof(A) << endl; //result=1  空类所占空间的大小为 1
		cout << "B=" << sizeof(B) << endl; //result=8  1+4   对齐 8
		cout << "C=" << sizeof(C) << endl; //result=8  1+1+4 对齐 8
		cout << "D=" << sizeof(D) << endl; //result=12 C的副本+D本身=8+4=12
		cout << "E=" << sizeof(E) << endl; //result=20 B的副本+C的副本+E本身=8+8+4=20
										   //①没有继承的时候，存在虚函数则需要加上虚指针，如果有多个也只需要加上一个，因为只有一个虚指针；
										   //②对于普通继承，类D和类E中自己的虚函数，大小为0，因为，它没有虚表；
										   //③对于虚继承中，派生类中存在一个或多个虚函数的时候，它本身就有一个虚表，指向自己的虚表，所以要加4。
	}

	//【Exp.004 - 虚继承（多重继承和虚函数）】
	{
		class CommonBase
		{
			int co;
		}; // size = 4

		class Base1 : virtual public CommonBase
		{
		  public:
			virtual void print1() {}
			virtual void print2() {}

		  private:
			int b1;
		}; //4副本+4虚指针+4自身+4(虚继承+虚函数构成指针多一个)=16

		class Base2 : virtual public CommonBase
		{
		  public:
			virtual void dump1() {}
			virtual void dump2() {}

		  private:
			int b2;
		}; //同理16

		class Derived : public Base1, public Base2
		{
		  public:
			void print2() {}
			void dump2() {}

		  private:
			int d;
		}; //16+16-4+4=32

		//解析：如果不是虚继承的类，即便有虚函数也不会因此增加存储空间，如果是虚继承的类，没有虚函数就添加一个虚指针空间，有虚函数不论多少个，就添加两个虚指针空间。
	}

	//【Exp.005-虚继承与虚函数】
	{
		class A
		{
		  public:
			virtual void aa() {}
			virtual void aa2() {}

		  private:
			char ch[3];
		}; // 1+4 = 补齐 = 8

		class B : virtual public A
		{
		  public:
			virtual void bb() {}
			virtual void bb2() {}
		}; // 8（副本）+4(虚继承)+4（虚指针） = 16

		cout << "A's size is " << sizeof(A) << endl; //        4+4=8
		cout << "B's size is " << sizeof(B) << endl; //        A的副本+4+4=16

		//解析：如果不是虚继承的类，即便有虚函数也不会因此增加存储空间，如果是虚继承的类，没有虚函数就添加一个虚指针空间，有虚函数不论多少个，就添加两个虚指针空间。
	}

	return 0;
}
