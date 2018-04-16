// 26_02_final和override关键字.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;


class Base {
public:
	virtual void mf1() const final;
	virtual void mf2() const;
};


class Derived:public Base {
public:
	//void mf1() const; //报错，无法重写final修饰的函数
	//void mf2() override; //报错，必须形式完全一样，包括const
	void mf2() const override; //正确
};


class NoDerived final{

};

//class Derived1 :public NoDerived {};  //final修饰的类不能被继承

int main()
{

	system("pause");
    return 0;
}

