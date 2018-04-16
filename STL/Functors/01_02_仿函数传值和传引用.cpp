#include "stdafx.h"
#include <iostream>  
#include <list>  
#include <algorithm>  
#include <iterator>

using namespace std;

void PRINT_ELEMENTS(list<int>& lt)
{
	list<int>::iterator it;
	for (it = lt.begin(); it != lt.end(); it++)
	{
		cout << *it << " , ";
	}
	cout << endl;
}

class IntSequence
{
private:
	int value;
public:
	IntSequence(int initValue) : value(initValue)
	{
	}

	int operator()()
	{
		return value++;
	}
};

int main()
{
	//传值的做法
	{
		list<int> col;
		IntSequence seq(1);
		generate_n(back_inserter(col), 4, seq); //默认是传值的，因此不会改变仿函数的状态，所以下面输出还是从1开始
		PRINT_ELEMENTS(col);
		generate_n(back_inserter(col), 4, IntSequence(42));
		PRINT_ELEMENTS(col);
		generate_n(back_inserter(col), 4, seq); //可以看到输出还是 1 2 3 4
		PRINT_ELEMENTS(col);
		generate_n(back_inserter(col), 4, seq);
		PRINT_ELEMENTS(col);
	}


	//传引用的做法
	{
		list<int> col1;
		IntSequence seq(1);
		//采用引用类型  
		generate_n<back_insert_iterator<list<int>>, int, IntSequence&>(
			back_inserter(col1),
			4,
			seq);
		//1 2 3 4;  
		PRINT_ELEMENTS(col1);

		//相当于重新构建一个对象从42开始插入4个元素  
		generate_n(back_inserter(col1),
			4,
			IntSequence(42));
		//1 2 3 4; 42 43 44 45   
		PRINT_ELEMENTS(col1);

		//前面使用的是引用类型，所以seq的内部状态已经被改变了  
		//插值从上次完成后的5开始  
		//注意：这次调用仍然使用的是传值类型  
		generate_n(back_inserter(col1),
			4,
			seq);
		//1 2 3 4; 42 43 44 45; 5 6 7 8   
		PRINT_ELEMENTS(col1);

		//上一次调用使用的是传值类型，所以这次还是从5开始插值      
		generate_n(back_inserter(col1),
			4,
			seq);
		//1 2 3 4; 42 43 44 45; 5 6 7 8; 5 6 7 8             
		PRINT_ELEMENTS(col1);
	}


	system("pause");
	return 0;
}
