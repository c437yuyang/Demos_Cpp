// 26_03_派生类覆盖基类成员.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class Base {
public:
	int age;
	
};

class Derived:public Base {

public:
	int age;
};


int main()
{
	Derived d;
	d.age = 10;
	d.Base::age = 20;
	cout << d.age << endl << d.Base::age << endl;
	system("pause");
    return 0;
}

