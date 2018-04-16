// 36_02_bind2nd.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

// functional_bind2nd.cpp
// compile with: /EHsc
#include <vector>
#include <functional>
#include <algorithm>
#include <iostream>

using namespace std;

// Creation of a user-defined function object
// that inherits from the unary_function base class
class greaterthan15 : unary_function<int, bool>
{
public:
	result_type operator()(argument_type i)
	{
		return (result_type)(i > 15);
	}
};

int main()
{
	vector<int> v1;
	vector<int>::iterator Iter;

	int i;
	for (i = 0; i <= 5; i++)
	{
		v1.push_back(5 * i);
	}

	cout << "The vector v1 = ( ";
	for (Iter = v1.begin(); Iter != v1.end(); Iter++)
		cout << *Iter << " ";
	cout << ")" << endl;

	// Count the number of integers > 10 in the vector
	vector<int>::iterator::difference_type result1a;//本身这里greater(return left>right;)是一个需要传入两个参数的仿函数，而count_if是需要一个参数的仿函数，用bind2nd就可以转换一下就成了（？>10）
	result1a = count_if(v1.begin(), v1.end(), bind2nd(greater<int>(), 10)); //将二元函数的第二个参数绑定为指定值，将二元函数对象转换为一元函数对象。
	cout << "The number of elements in v1 greater than 10 is: "
		<< result1a << "." << endl;

	// Compare counting the number of integers > 15 in the vector
	// with a user-defined function object
	vector<int>::iterator::difference_type result1b;
	result1b = count_if(v1.begin(), v1.end(), greaterthan15());
	cout << "The number of elements in v1 greater than 15 is: "
		<< result1b << "." << endl;

	// Count the number of integers < 10 in the vector
	vector<int>::iterator::difference_type result2;
	result2 = count_if(v1.begin(), v1.end(), bind1st(greater<int>(), 10));//和第一个参数绑定就成了 10>x  因此就是小于10的
	cout << "The number of elements in v1 less than 10 is: "
		<< result2 << "." << endl;

	system("pause");
	return 0;
}
