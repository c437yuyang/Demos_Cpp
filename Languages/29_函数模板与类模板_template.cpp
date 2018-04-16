// 29_模板template.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class fooo {
public:
	template<class T> //函数模板，调用的时候如果可以根据"参数"进行推断得到类型，那么可以不指定类型进行调用
	void func(T) 
	{
		cout << typeid(T).name() << endl;
	}

	template<class T> //函数模板，调用的时候如果不能根据"参数"进行推断得到类型，那么必须指定类型进行调用
	void func1(int i)
	{
		cout << typeid(T).name() << endl;
	}

};

template <class T>
class Widget 
{
public:
	void printfInfo() 
	{
		cout << t << endl;
	}

	T t;
};

//函数模板必须由编译器根据程序员的调用类型实例化为可执行的函数。

//对于一个实例化了的类模板，其成员函数只有在使用时才被实例化。
//如果一个成员函数没有被使用，则它不会被实例化。

int main(int argc, char * * argv) 
{
	fooo f;
	f.func(100);
	f.func<double>(100.0); //函数模板，调用的时候如果可以根据参数进行推断得到类型，那么可以不指定类型进行调用
	//f.func1(100); //报错，不能根据参数类型推断得到模板类型的时候必须指定类型
	f.func1<double>(100); //输出double


	//Widget w; //报错，类模板必须指定模板类型
	Widget<int> w1;
	w1.printfInfo();

	system("pause");
	return 0;
}



