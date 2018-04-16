#include <iostream>
#include <time.h>
#include <windows.h>

using namespace std;

class A
{
public:
	A() { cout << "A默认构造函数!" << endl; }
	A(int i) :m_a(i) { cout << "A带1个参数构造函数" << endl; }
	A(int i,int j) :m_a(i),m_b(j) { cout << "A带2个参数构造函数" << endl; }

	int m_a;
	int m_b;
	~A() { cout << "A析构函数!" << endl; }
};


int main()
{
	int *p1 = new int[10]; //未进行初始化 
	int *p3 = new int[10](); //空括号，进行默认值初始化
	int *p2 = new int[10]{ 1,2,3,4,56 }; //列表初始化，不够的进行值初始化

	//A *pA = new A[5](10); //报错
	A *pA = new A[5](); //调用5次默认构造函数,new里面不能调用带参数的构造函数!
	cout << endl;
	A *pA4 = new A[5];//也是调用5次默认构造函数
	A *pA3 = new A; //调用默认构造函数
	A *pA1 = new A(10); //但是单个对象的时候可以调用带参数的构造函数
	cout << pA1->m_b << endl; //可以看到若默认初始化是为未定义的值的
	A *pA2 = new A(10, 20);


	int *p4 = new int(10);
	cout << *p4 << endl;
	//对于内置类型，new的数组可用delete也可用delete[]
	//但是对于引用类型,delete和delete就不能混用了,原因是内置类型不需要调用析构函数，引用类型必须调用多次析构函数才可以

	A *pA5 = new A[5];
	delete []pA5; //调用delete的话还会报错，必须delete[] ，调用五次构造函数和析构函数

	system("pause");
}