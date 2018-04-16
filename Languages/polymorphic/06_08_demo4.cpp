#include "stdafx.h"
#include <iostream>

using namespace std;

class CA
{
public:
	virtual void f1()
	{
		cout << "CA:f1()" << endl;
		f2();
	}
	void f2()
	{
		cout << "CA:f2()" << endl;
	}
};


class CB :public CA
{
public:
	void f1()
	{
		cout << "CB:f1()" << endl;
		f2();
	}
	void f2()
	{
		cout << "CB:f2()" << endl;
	}
};

class CC :public CB
{
public:
	virtual void f2()
	{
		cout << "CC:f2()" << endl;
	}
};
int main()
{
	CC c;
	CA *pA = &c;

	//这种情况还比较特殊，如果不能发生多态行为了，是不会把它当做CA的指针的，在CB内就是CB调的
	pA->f1(); //f1()里面的f2()调用就是调用CB类内的了，在哪里，就用哪个对象来考虑多态，而不是回去再从CA开始考虑
			  //如果CB的f2()是virtual的就会调用CC的f2()最终

	system("pause");
	return 0;
}