// 56_01_����Ƚ����.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"


#include <vector>
#include <iostream>
class Widget
{
public:
	Widget(int i) :age(i) {}

	bool operator==(const Widget& other)
	{
		return other.age == age;
	}

public:
	int age;

};


int main()
{

	Widget w1(10), w2(10);

	std::cout << std::boolalpha << (w1 == w2) << std::endl; //��ʵ��operator==��������ǲ��ܽ��бȽϵģ�C++Ĭ��ֻ�����ĸ�����(ctor,dtor,copying����)�Զ�����
	//java���������������ǿ��ԱȽϵģ��Ƚ��ڴ��ֱַ����
	system("pause");

	return 0;
}

