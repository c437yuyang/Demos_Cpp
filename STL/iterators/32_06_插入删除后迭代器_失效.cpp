// 32_06_插入删除迭代器.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
//http://www.cnblogs.com/blueoverflow/p/4923523.html#_label2
#include <vector>
#include <list>
#include <unordered_set>
#include <iostream>

//vector:
//vector的迭代器在内存重新分配时将失效（它所指向的元素在该操作的前后不再相同）。
//当把超过capacity()-size()个元素插入vector中时，内存会重新分配，所有的迭代器都将失效；
//否则，指向当前元素以后的任何元素的迭代器都将失效。
//当删除元素时，指向被删除元素以后的任何元素的迭代器都将失效。

//list:
//增加任何元素都不会使迭代器失效。删除元素时，除了指向当前被删除元素的迭代器外，其它迭代器都不会失效。

//deque:
//增加任何元素都将使deque的迭代器失效。在deque的中间删除元素将使迭代器失效。
//在deque的头或尾删除元素时，只有指向该元素的迭代器失效。

//序列容器
//删除元素，返回指向被删除元素下一个的迭代器
//插入元素，返回插入的位置的元素迭代器

//关联容器
//删除和插入，不返回迭代器


int main()
{
	std::vector<int> v1 = { 1,2,3,4,5,6 };

	std::list<int> l1 = { 1,2,3,4,5 };

	auto it = l1.erase(++(l1.begin())); //删除返回被删除之后的元素
	it = l1.insert(++(l1.begin()), 2); //插入返回插入位置元素的迭代器

	std::unordered_set<int> us1 = { 3,2,1,4,33 };
	for (auto it = us1.begin(); it != us1.end(); ++it)
	{
		std::cout << *it << std::endl; //可以看到顺序是乱的，是按照hash函数计算的来的
	}

	us1.insert(1);
	int i = us1.erase(33); //删除存在的返回1
	int j = us1.erase(34); //不存在的返回0

  //从容器中删除特定值demo
  {
      std::vector<int>array;
    array.push_back(100);
    array.push_back(300);
    array.push_back(300);
    array.push_back(500);
    std::vector<int>::iterator itor;
    for (itor = array.begin(); itor != array.end(); itor++)
    {
      if (*itor == 300)
      {
        itor = array.erase(itor); //erase了过后指向下一个
      }
    }
    for (itor = array.begin(); itor != array.end(); itor++)
    {
      std::cout << *itor << " ";
    }
    //其实也可以用remove_if,然后配合erase,详情看effective stl
  }


	return 0;
}

