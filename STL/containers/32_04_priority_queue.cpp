// 32_04_priority_queue.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <queue>
#include <iostream>
#include <vector>
using namespace std;

struct IntLess :binary_function<const int, const int, bool>
{
public:
	bool operator()(const int lhs, const int rhs) const
	{
		return lhs > rhs;
	}
};

struct MyGreat //使用模板函数使得不限制类型
{
	template<class T>
	constexpr bool operator()(const T _Left, const T _Right) const
	{	// apply operator< to operands
		return (_Left > _Right);
	}
};

template <class T>
struct MyLess1
{
	constexpr bool operator()(const T&left, const T&right) const { return left > right; }
};

struct  Person
{
	int age;
	int salary;
};

struct sortByAgeMin
{
	bool operator()(const Person&lhs, const Person& rhs)
	{
		return lhs.age < rhs.age;
	}
};

struct sortBySalary
{
	bool operator()(const Person&lhs, const Person& rhs)
	{
		return lhs.salary < rhs.salary;
	}
};


int main()
{
	//priority_queue没有迭代器，因此不是标准STL容器
	priority_queue<int> pq; //默认是大根堆，比较器是Less
	pq.push(10);
	pq.push(1);
	pq.push(33);
	pq.push(5);
	pq.push(22); //调试查看内存可以看到就是按照heapinsert的方法来做的
	size_t size = pq.size();
	for (size_t i = 0; i < size; i++)
	{
		cout << pq.top() << endl;
		pq.pop();
	}

	//priority_queue<int, vector<int>, less<int> > min_pq;
	//priority_queue<int, vector<int>, MyLess1<int> > min_pq;
	priority_queue<int, vector<int>, MyGreat> min_pq;
	//priority_queue<int, vector<int>, IntLess > min_pq; //这里传的比较和意义上的比较是反的
	min_pq.push(10);
	min_pq.push(1);
	min_pq.push(33);
	min_pq.push(5);
	min_pq.push(22);
	size = min_pq.size();
	for (size_t i = 0; i < size; i++)
	{
		cout << min_pq.top() << endl;
		min_pq.pop();
	}


	Person p1{ 10,200 };
	Person p2{ 20,100 };
	Person p3{ 5,1000 };

	priority_queue<Person, vector<Person>, sortByAgeMin> pq_age; //按照age形成大根堆
	pq_age.push(p1);
	pq_age.push(p2);
	pq_age.push(p3); 

	return 0;
}

