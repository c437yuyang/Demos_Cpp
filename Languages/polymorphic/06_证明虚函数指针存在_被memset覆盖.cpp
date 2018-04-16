// 06_证明虚函数指针存在_被memset覆盖.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class parent
{
public:
	virtual void output();
};
void parent::output()
{
	printf("parent!");
}

class son : public parent
{
public:
	virtual void output();
};
void son::output()
{
	printf("son!");
}

int main()
{

	son s;
	memset(&s, 0, sizeof(s));
	parent& p = s;
	p.output(); //运行时错误，虚函数指针被覆盖0了

	system("pause");
    return 0;
}

