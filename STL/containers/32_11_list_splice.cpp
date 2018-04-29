// 32_11_list_splice.cpp : �������̨Ӧ�ó������ڵ㡣
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
		std::find(l1.rbegin(), l1.rend(), 10).base() //.base()���������ǰһ�����������һ������Ϊ����������������ҿ�
	); //��l1�е�һ��5�����һ��10�ķ�Χ�ƶ���l2��ĩβ����l1��ɾ��

	std::for_each(l1.begin(), l1.end(), [](int val) { std::cout << val << ","; });
	std::cout << std::endl;
	std::for_each(l2.begin(), l2.end(), [](int val) { std::cout << val << ","; });
	std::cout << std::endl;

	l3.splice(l3.begin(), l2); //��l2�����нڵ��ƶ���l3����ǰ�棬��insert�������ǣ�insert�ǿ�����splice��l2�Ľڵ�Ҳ�Ϳ���
	std::for_each(l3.begin(), l3.end(), [](int val) { std::cout << val << ","; });
	std::cout << std::endl;

	system("pause");

	return 0;
}

