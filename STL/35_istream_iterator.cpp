// 35_istream_iterator.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


// istream_iterator_istream_iterator.cpp
// compile with: /EHsc
#include <iterator>
#include <vector>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>

int main()
{
	using namespace std;

#pragma region istream_iterator结合copy从cin读入数据
	//// Used in conjunction with copy algorithm
	//// to put elements into a vector read from cin
	//vector<int> vec(4);
	//vector<int>::iterator Iter;

	//cout << "Enter 4 integers separated by spaces & then\n"
	//	<< " a character ( try example: '2 4 6 8 a' ): "; //istream_iterator遇到错误的类型会直接停止，不是跳过！
	//istream_iterator<int> intvecRead(cin);

	//// Default constructor will test equal to end of stream
	//// for delimiting source range of vecor
	//copy(intvecRead, istream_iterator<int>(), vec.begin()); //istream_iterator<int>()表示结尾
	//cin.clear();

	//cout << "vec = ";
	//for (Iter = vec.begin(); Iter != vec.end(); Iter++)
	//	cout << *Iter << " "; cout << endl;
	////再结合ostream_iterator从cout输出
	//copy(vec.begin(), vec.end(), ostream_iterator<int>(cout));
	//cout << endl;
	//copy(vec.begin(), vec.end(), ostream_iterator<int>(cout, " "));
#pragma endregion

#pragma region istream_iterator从文件读入数据
	
	//ifstream ifs("ints.dat");
	//istream_iterator<int> dataBegin(ifs);
	//istream_iterator<int> dataEnd;
	////vector<int> v1(dataBegin,dataEnd);
	//vector<int> v2;
	//for (auto it = dataBegin;it!=dataEnd;++it) //其实也就是一个迭代器，可以解引用和自加等等
	//	v2.push_back(*it);

#pragma endregion


#pragma region istream_iterator快速使用介绍
	istream_iterator<int> it1(cin);
	istream_iterator<int> it2;

	while (it1 != it2) //只有当输入不是符合条件的值的时候才停止
	{
		cout << *it1 << " ";
		it1++;
	}
	cin.clear();

	istream_iterator<string> it11(cin);
	istream_iterator<string> it21;

	while (it11 != it21) //windows输入ctrl+z才能结束，linux必须输入ctrl+d
	{
		cout << *it11 << " ";
		it11++;
	}

	char ch;
	while ((ch = getchar()) != '\0') //必须输入ctrl+@('\0')才能结束，这个所有系统都是一样的
	{
		cout << ch << endl;
	}


#pragma endregion


}
