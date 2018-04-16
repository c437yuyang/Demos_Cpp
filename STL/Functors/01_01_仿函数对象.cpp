// 01_仿函数对象.cpp : 定义控制台应用程序的入口点。
//

#include <iostream>
#include <vector>
#include <algorithm>
//一个类如果重写了operator()的话就是仿函数
//仿函数的基类有两个:unary_function 和 binary_function
//仿函数的优点主要是速度更快(调用operator())，函数指针的调用方法涉及到指针调用因此很慢。
//传递谓词的地方，都可以用仿函数替代，但是传递仿函数的地方，谓词是不能替代的


template<class T>
struct plus
{
	T operator()(const T&x, const T& y)
	{
		return x + y;
	}
};

//另一种做法
struct minus
{
	template<class T>
	T operator()(const T&x, const T&y)
	{
		return x - y;
	}
};

struct PrintFunctor
{
	//两种都可以，不需要返回bool值了这里
	
	//template<class T>
	//void operator()(const T& val)
	//{
	//	std::cout << val << " ";
	//}

	template<class T>
	bool operator()(const T& val)
	{
		std::cout << val << " ";
		return true;
	}

};

template<class T>
void PrintFunc(const T& val)
{
	std::cout << val << " ";
}


int main()
{
	plus<int> plusObj;
	std::cout << plusObj(1, 2) << std::endl;
	std::cout << plus<int>() (1, 2) << std::endl; //使用临时对象
	std::cout << minus()(3, 4) << std::endl;


	std::vector<int> v1 = { 1,2,3,4,5 };

	std::vector<int>::value_type i1 = 1;
	std::for_each(v1.begin(), v1.end(), PrintFunctor());
	std::cout << std::endl;
	std::for_each(v1.begin(), v1.end(), PrintFunc<int>); //也可以



	system("pause");
	return 0;
}

