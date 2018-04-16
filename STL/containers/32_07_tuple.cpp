// 32_07_tuple.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <tuple>
#include <string>
#include <boost/tuple/tuple.hpp>
#include <iostream>
using namespace std;

int main()
{
	typedef std::tuple<int, string, double> stdTuple;
	typedef boost::tuple<int, string, double> boostTuple;
	stdTuple tp1(10, "s", 1.0);
	//myTp tp1(10, "a"); //std的版本不支持默认构造
	boostTuple tp2(10, "a"); //boost的版本支持默认构造
	
	
	stdTuple tp3 = tp1; //拷贝构造

	int x = 10;
	std::tuple<int &> tp4(x); //可以有引用，但是必须附初值

	//工厂函数
	std::tuple<int, string, double> tp5 = std::make_tuple(1, "a", 1.0);

	//cout << tp5.get<0>() << endl; //vs不支持。。

	boost::tuple<int, string, double> tp6 = boost::make_tuple(1, "a", 1.0);
	cout << tp6.get<0>() << endl; //boost的版本支持
	//cout << tp6 << endl; //不支持

	//总结:还是别用了，真难用，一般来说pair或者struct更好用

	/*tp1[0] = 1;*/ //不能下标操作

	system("pause");
    return 0;
}

