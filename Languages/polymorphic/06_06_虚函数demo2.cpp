// 06_�麯������2.cpp : �������̨Ӧ�ó������ڵ㡣
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
//A::A() 0 //�����ȵ��ø��๹�캯��
//A::test() 0 //���캯���е����麯���������Լ����(A�࣬����)
//A::func() 0 //test()�е����麯��,��Ȼ����A��ģ���ΪB�໹û������ȫ
//B::B() 0 //��B�๹�캯��,m_iVal����ʼ��Ϊ��0��A::A()��
//B::test() 0 //����B���Լ���
//B::func() 1 //�����Լ���


//�ο�:primer 556ҳ
//���캯��������������ִ����ĳ���麯����Ӧ��ִ����֮�����������Ӧ���͵��麯���汾
