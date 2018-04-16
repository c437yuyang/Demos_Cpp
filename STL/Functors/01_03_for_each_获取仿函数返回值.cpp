// 01_03_for_each_获取仿函数返回值.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>  
#include <vector>  
#include <algorithm>  
using namespace std;

class MeanValue
{
private:
	long num;
	long sum;
public:
	MeanValue() : num(0), sum(0)
	{
	}
	void operator() (int elem)
	{
		num++;
		sum += elem;
	}

	double value()
	{
		return static_cast<double>(sum) / static_cast<double>(num);
	}
};

int main()
{
	vector<int> col1;
	for (int i = 1; i <= 8; ++i)
	{
		col1.push_back(i);
	}
	MeanValue mv1;
	MeanValue mv = for_each(col1.begin(), col1.end(),mv1); //for_each返回一个对象保存了操作后的值
	//MeanValue mv = for_each(col1.begin(), col1.end(), MeanValue()); //或者 传递一个临时对象
	//for_each(col1.begin(), col1.end(), MeanValue().operator()); //或者这样也可以
	cout << mv1.value() << endl; //可以看到mv1本身还是没变
	cout << "Mean Value: " << mv.value() << endl;
	system("pause");
	return 0;
}