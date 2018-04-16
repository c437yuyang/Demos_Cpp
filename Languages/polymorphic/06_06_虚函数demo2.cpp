// 06_虚函数测试2.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class A
{
public:
	A() :m_iVal(0)
	{
		std::cout << "A::A()" << m_iVal << " " << std::endl;
		test();
	}
	virtual void func()
	{
		std::cout << "A::func()" << m_iVal << " " << std::endl;
	}
	virtual void test()
	{
		std::cout << "A::test()" << m_iVal << " " << std::endl;
		func();
	}
public:
	int m_iVal;
};
class B : public A
{
public:
	B()
	{
		std::cout << "B::B()" << m_iVal << " " << std::endl;
		test();
	}

	virtual void test()
	{
		std::cout << "B::test()" << m_iVal << " " << std::endl;
		func();
	}

	virtual void func()
	{
		++m_iVal;
		std::cout << "B::func()" << m_iVal << " " << std::endl;
	}
};
int main(int argc, char* argv[])
{
	A*p = new B;
	p->test();
	system("pause");
	return 0;
}
//
//A::A() 0 //子类先调用父类构造函数
//A::test() 0 //构造函数中调用虚函数，调用自己类的(A类，父类)
//A::func() 0 //test()中调用虚函数,仍然调用A类的，因为B类还没构造完全
//B::B() 0 //到B类构造函数,m_iVal被初始化为了0在A::A()中
//B::test() 0 //调用B类自己的
//B::func() 1 //调用自己的


//参考:primer 556页
//构造函数或析构函数里执行了某个虚函数，应该执行与之所属类型相对应类型的虚函数版本
