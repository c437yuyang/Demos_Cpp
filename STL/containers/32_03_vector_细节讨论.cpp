// 32_03_vector容器.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>
#include <windows.h>
using namespace std;



#pragma region 几种遍历方式
typedef vector<int> vInt;
void traverse_vec_operator(const vInt & v)//方法一，采用下标访问
{
	int i;
	int j;
	for (i = 0; i < v.size(); i++)
	{
		j = v[i];
	}
}

void traverse_vec_at(const vInt & v)//方法一，采用下标访问
{
	int i;
	int j;
	for (i = 0; i < v.size(); i++)
	{
		j = v.at(i);
	}
}

void traverse_vec_iterator(const vInt &v)//方法二，采用迭代器访问
{
	int i;
	for (vInt::const_iterator iter = v.begin(); iter != v.end(); iter++)
	{
		i = *iter;
	}
}

void traverse_vec_iterator_no_end(const vInt &v)//方法二，采用迭代器访问,但是提前设置好end
{
	auto end = v.end();
	int i;
	for (vInt::const_iterator iter = v.begin(); iter != end; iter++)
	{
		i = *iter;
	}
}

void traverse_vec_algorithm(const vInt &v)//方法三，将容器的内容复制到cout绑定的迭代器
{
	int i = 0;
	for_each(v.begin(), v.end(), [&](int val) {i = val; });
}

class AAA
{
public:
	void MakeFull2()
	{
	}
};


#pragma endregion



class A {
public:
	A(int i1) :i(i1) {};
	int i;

	bool operator==(const A&rhs) const //必须是const版本的const 成员函数才行!!!!!
	{
		return this->i == rhs.i;
	}
};



int main()
{

#pragma region vector推入成员时内存分配示例
	//结论:容量不够的时候，推入新的才会增加容量
	//数据量较少时(VS是小于3个的时候)是每次都加1，后面VS里面每次是增加当前容量的一半
	//在mingw里面是每次增加当前容量一倍大小
	vector<int> v;
	cout << "初始容量:" << v.size() << "," << v.capacity() << endl; //0,0
	for (int i = 0; i != 20; ++i)
	{
		v.push_back(1);
		cout << "加入1后:" << v.size() << "," << v.capacity() << endl; //0,0
	}

#pragma endregion

#pragma region vetor判断相等，其实<等其他符号也是一样的道理
	vector<int> vec1 = { 1,2,3,4,5 };
	vector<int> vec2 = { 1,2,3,4,5 };

	for (auto it = vec1.begin(); it != vec1.end(); ++it)
	{
		cout << *it << endl;
	}

	cout << (vec1 == vec2) << endl; //可以看到是相等的



	vector<string> vec3 = { string("aaa"),string("bbb"),string("ccc") };
	vector<string> vec4 = { string("aaa"),string("bbb"),string("ccc") };
	for (auto it = vec3.begin(); it != vec3.end(); ++it)
	{
		cout << (*it).c_str() << endl;
	}
	cout << (vec3 == vec4) << endl; //可以看到是相等的

	cout << (string("s1") == string("s1")) << endl; //相等
	cout << (string("s1").compare(string("s1"))) << endl;//输出0，表示相等


	vector<A> vec5 = { A(1),A(2),A(3) };
	vector<A> vec6 = { A(1),A(2),A(3) };

	cout << (vec5 == vec6) << endl; //直接无法运行，没有改写==
#pragma endregion

#pragma region 正确释放vector的内存
	{
		//vector<T>在clear后，不影响capacity,要同时清空capacity应该:
		vector<string> v;
		v.push_back("aa");
		v.push_back("bb");
		v.clear();
		vector<string>(v).swap(v);
	}



#pragma endregion

	//vector容器遍历效率测试
	//debug模式下:从快到慢:at、for_each、opertor[]、iterator_no_end、iterator
	//release模式可能直接给优化了，判断到你根本没用这个变量？具体看反汇编才知道
	{
		int nCount = 1000000;
		std::vector< int > vAAA(nCount,1);

		// 时间
		int start, end;


		start = GetTickCount();
		size_t count = vAAA.size();
		for (size_t i = 0; i < count; ++i)
			traverse_vec_operator(v);
		end = GetTickCount();
		std::cout << end - start << std::endl;

		start = GetTickCount();
		for (size_t i = 0; i < count; ++i)
			traverse_vec_at(v);
		end = GetTickCount();
		std::cout << end - start << std::endl;


		start = GetTickCount();
		for (size_t i = 0; i < count; ++i)
			traverse_vec_iterator(v);
		end = GetTickCount();
		std::cout << end - start << std::endl;

		start = GetTickCount();
		for (size_t i = 0; i < count; ++i)
			traverse_vec_iterator_no_end(v);
		end = GetTickCount();
		std::cout << end - start << std::endl;


		start = GetTickCount();
		for (size_t i = 0; i < count; ++i)
			traverse_vec_algorithm(v);
		end = GetTickCount();
		std::cout << end - start << std::endl;

	}

	system("pause");
	return 0;
}

