// 32_05_heap.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


#include <iostream>  
#include <algorithm>  //make_heap等
#include <vector>  
using namespace std;

bool PredFunc(int val1, int val2)
{
	return val1 < val2; //默认就是这个，但是是最大堆，stl里面很多这个都是反的
	//return val1 > val2; //最小堆
}

int main()
{
	{
		
		int myints[] = { 10,20,30,5,15 };
		vector<int> v(myints, myints + 5);

		//默认是最大堆
		make_heap(v.begin(), v.end(), PredFunc); //make_heap相当于build_heap(不是heapify,heapify是保证了左右子树都是堆的情况下，而是从非叶节点的那一层开始往上heapify)
		cout << "initial max heap   : " << v.front() << endl;
		
		pop_heap(v.begin(), v.end(), PredFunc); 
		v.pop_back(); //pop_heap 把堆顶元素移动到队尾,之后再自己pop_back即可。
		cout << "max heap after pop : " << v.front() << endl;

		v.push_back(99);
		push_heap(v.begin(), v.end(),PredFunc); //先push_back,在push_heap,相当于heap_insert(只能在末尾)
		cout << "max heap after push: " << v.front() << endl;

		sort_heap(v.begin(), v.end(),PredFunc); //利用堆排序，最大堆则是从小到大，最小堆就是从大到小

		cout << "final sorted range :";
		for (unsigned i = 0; i < v.size(); i++) 
			cout << " " << v[i];

		cout << endl;

	}

	{
		std::vector<int> foo{ 9,5,2,6,4,1,3,8,7 };

		if (!std::is_heap(foo.begin(), foo.end()))
			std::make_heap(foo.begin(), foo.end());

		cout << "after make heap:" << endl;
		for (int i = 0; i != foo.size(); ++i)
		{
			cout << foo[i] << " ";
		}
		cout << endl;

		std::cout << "Popping out elements:";
		while (!foo.empty()) {
			std::pop_heap(foo.begin(), foo.end());   // moves largest element to back
			std::cout << ' ' << foo.back();         // prints back
			foo.pop_back();                         // pops element out of container
		}
		std::cout << '\n';
	}

	return 0;
}