// 36_03_mem_fun_t_成员函数适配器.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
// Ex13-21.cpp : Defines the entry point for the console application.
//
#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;
struct B
{
	virtual void print() = 0;
};
struct D1 :public B
{
	void print()
	{
		cout << "I'm a D1." << endl;
	}
	D1() {}
	D1(const D1&d1) { cout << "拷贝函数" << endl; }

};
struct D2 :public B
{
	void print()
	{
		cout << "I'm a D2." << endl;
	}
};
void main(int argc, char* argv[])
{
	vector<B*> v;
	v.push_back(new D1);
	v.push_back(new D2);
	v.push_back(new D2);
	v.push_back(new D1);
	for_each(v.begin(), v.end(), mem_fun(&B::print));//private的话也不违背，这里直接就不能访问了
	for_each(v.begin(), v.end(), [](B* p) { p->print(); }); //这里类型不能是const,不然必须调用const版本成员函数，这样调用也可以，但是相对不是那么简洁了。

	//vector<D1> v1;
	//v1.push_back(D1());
	//v1.push_back(D1());
	//for_each(v1.begin(), v1.end(), mem_fun(&D1::print)); //报错，只能传递D1*，不能传递本身的对象，所以用着还不如直接用函数方便感觉。 可能是以前不支持lambda表达式的原因吧


	//const 版本就是类似的
	//mem_fun_ref 就是容器里面装的是B本身，不是B的指针的时候用
	//这种mem_fun转过来的函数其实都是还是一个参数，mem_fun就是自己类的指针(就是传值?)，mem_fun_ref就是类的对象本身(传的引用吧),mem_fun_1就可以使用含有参数的成员函数
	vector<vector<int>*> v2;
	v2.push_back(new vector<int>(5));
	v2.push_back(new vector<int>(3));
	v2.push_back(new vector<int>(4));
	transform(v2.begin(), v2.end(), ostream_iterator<int>(cout, " "), mem_fun(&vector<int>::size));
	cout << endl;

	system("pause");

}
