#include "stdafx.h"
#include <iostream>

using namespace std;
class Base
{
	int x;
public:
	Base(int b) : x(b) {}
	virtual void display()
	{
		cout << x << endl;
	}
};
class Derived : public Base
{
	int y;
public:
	Derived(int d) : Base(d), y(d) {}
	void display()
	{
		cout << y << endl;
	}
};
int main()
{
	Base b(2);
	Derived d(3);
	b.display();//2
	d.display();//3
	Base *p = &d;
	p->display();//Ðéº¯Êý,3
	system("pause");
	return 0;
}