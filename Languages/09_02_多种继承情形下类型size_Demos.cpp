// 09_02_���ּ̳е�size.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include <iostream>
#include <assert.h>
using namespace std;

//https://blog.csdn.net/u013630349/article/details/47057929

//��Exp.002-���ؼ̳С�

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
		//��Exp.001-��̳С�
		class A
		{
		  public:
			int a;
		}; //sizeof(A)=4

		class B : virtual public A
		{
		  public:
			int b;
		}; //sizeof(B)=4(A����)+4(���ָ��)+4(�Լ�����)=12

		class C : virtual public B
		{
		}; //sizeof(c)= 12(B����)+4(���ָ��) = 16����������Ϊֱ�Ӽ̳У���ôsizeof(c)=12

		printf("%d\n", sizeof(C));
		//������������Ҫ�����̳л����������Ŀռ��С��Ӱ�죬�����ָ������̳���Ϊ�����������Щ�ռ�ĸı䡣
	}

	//��Exp.002-���ؼ̳С�
	{
		class A
		{
		  public:
			int a;
		}; //sizeof(A) = 4

		class B : virtual public A
		{
		}; // sizeof(B) =4(A����)+4(���ָ��)=8

		class C : virtual public A
		{
		}; //sizeof(C) =4+4=8

		class D : public B, public C
		{
		};
		//sizeof(D)=8+8-4=12 ������Ҫע��Ҫ��ȥ4����ΪB��Cͬʱ�̳�A��ֻ��Ҫ����һ��A�ĸ����ͺ��ˣ�sizeof(D)=4(A�ĸ���)+4(B�����)+4(C�����)=12
		printf("%d\n", sizeof(D));
		//������������Ҫ��ע class D �����ݿռ��С����������̳ж���������ָ���Լ�������ռ��Ӱ�졣
	}

	//��Exp.003-��ͨ�̳У����У����ࡢ�麯������
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

		cout << "A=" << sizeof(A) << endl; //result=1  ������ռ�ռ�Ĵ�СΪ 1
		cout << "B=" << sizeof(B) << endl; //result=8  1+4   ���� 8
		cout << "C=" << sizeof(C) << endl; //result=8  1+1+4 ���� 8
		cout << "D=" << sizeof(D) << endl; //result=12 C�ĸ���+D����=8+4=12
		cout << "E=" << sizeof(E) << endl; //result=20 B�ĸ���+C�ĸ���+E����=8+8+4=20
										   //��û�м̳е�ʱ�򣬴����麯������Ҫ������ָ�룬����ж��Ҳֻ��Ҫ����һ������Ϊֻ��һ����ָ�룻
										   //�ڶ�����ͨ�̳У���D����E���Լ����麯������СΪ0����Ϊ����û�����
										   //�۶�����̳��У��������д���һ�������麯����ʱ�����������һ�����ָ���Լ����������Ҫ��4��
	}

	//��Exp.004 - ��̳У����ؼ̳к��麯������
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
		}; //4����+4��ָ��+4����+4(��̳�+�麯������ָ���һ��)=16

		class Base2 : virtual public CommonBase
		{
		  public:
			virtual void dump1() {}
			virtual void dump2() {}

		  private:
			int b2;
		}; //ͬ��16

		class Derived : public Base1, public Base2
		{
		  public:
			void print2() {}
			void dump2() {}

		  private:
			int d;
		}; //16+16-4+4=32

		//���������������̳е��࣬�������麯��Ҳ����������Ӵ洢�ռ䣬�������̳е��࣬û���麯�������һ����ָ��ռ䣬���麯�����۶��ٸ��������������ָ��ռ䡣
	}

	//��Exp.005-��̳����麯����
	{
		class A
		{
		  public:
			virtual void aa() {}
			virtual void aa2() {}

		  private:
			char ch[3];
		}; // 1+4 = ���� = 8

		class B : virtual public A
		{
		  public:
			virtual void bb() {}
			virtual void bb2() {}
		}; // 8��������+4(��̳�)+4����ָ�룩 = 16

		cout << "A's size is " << sizeof(A) << endl; //        4+4=8
		cout << "B's size is " << sizeof(B) << endl; //        A�ĸ���+4+4=16

		//���������������̳е��࣬�������麯��Ҳ����������Ӵ洢�ռ䣬�������̳е��࣬û���麯�������һ����ָ��ռ䣬���麯�����۶��ٸ��������������ָ��ռ䡣
	}

	return 0;
}
