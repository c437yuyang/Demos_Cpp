// 32_11_list_splice.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <list>
#include <algorithm>
#include <iostream>

int main()
{
	std::list <int> l1 = { 1,2,3,4,5,5,5,6,10,10,11,12 };
	std::list<int> l2 = { 1,4,6,9 };
	std::list<int> l3 = { 10,11 };

	l2.splice(l2.end(), l1,
		std::find(l1.begin(), l1.end(), 5),
		std::find(l1.rbegin(), l1.rend(), 10).base() //.base()返回逆序的前一个，正序的下一个，因为迭代器区间是左闭右开
	); //把l1中第一个5到最后一个10的范围移动到l2的末尾并从l1中删除

	std::for_each(l1.begin(), l1.end(), [](int val) { std::cout << val << ","; });
	std::cout << std::endl;
	std::for_each(l2.begin(), l2.end(), [](int val) { std::cout << val << ","; });
	std::cout << std::endl;

	l3.splice(l3.begin(), l2); //把l2的所有节点移动到l3的最前面，和insert的区别是，insert是拷贝，splice后，l2的节点也就空了
	std::for_each(l3.begin(), l3.end(), [](int val) { std::cout << val << ","; });
	std::cout << std::endl;

	system("pause");

	return 0;
}

