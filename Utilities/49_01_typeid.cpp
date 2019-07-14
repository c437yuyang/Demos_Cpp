// 49_01_typeid.cpp : 定义控制台应用程序的入口点。
//

#include <iostream>  
#include <typeinfo>
using namespace std;

class Base {};
class Derived : public Base {};

int main()
{
	Base b, *pb;
	pb = NULL;
	Derived d;

	cout << typeid(int).name() << endl //
		<< typeid(int *).name() << endl //int *
		<< typeid(int &).name() << endl //int 
		<< typeid(unsigned).name() << endl
		<< typeid(long).name() << endl
		<< typeid(unsigned long).name() << endl
		<< typeid(char).name() << endl
		<< typeid(unsigned char).name() << endl
		<< typeid(float).name() << endl
		<< typeid(double).name() << endl
		<< typeid(string).name() << endl
		<< typeid(Base).name() << endl
		<< typeid(b).name() << endl
		<< typeid(pb).name() << endl
		<< typeid(Derived).name() << endl
		<< typeid(d).name() << endl
		<< typeid(type_info).name() << endl;
	//MSVC得到的是类型名称，但mingw个g++得到的是变量的名称

	return 0;
}

