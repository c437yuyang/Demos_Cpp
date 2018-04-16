// 44_01_const对象只能调用const成员函数.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class Widget {

public:

	int getID() { return id; }

	int id;

};

int main()
{
	const Widget cw;
	//cw.getID(); //报错，const对象只能调用const成员函数，即使成员函数本身不会修改对象(所以尽量不修改的就声明为const成员)
    return 0;
}

