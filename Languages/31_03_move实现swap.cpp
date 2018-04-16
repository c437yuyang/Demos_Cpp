// 31_03_move实现swap.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class A
{
public:
	// constructor
	explicit A(size_t length)
		: mLength(length), mData(new int[length]) {}

	// move constructor
	A(A&& other)
	{
		mData = other.mData;
		mLength = other.mLength;
		other.mData = nullptr;
		other.mLength = 0;
	}

	// move assignment
	A& operator=(A&& other) noexcept
	{
		mData = other.mData;
		mLength = other.mLength;
		other.mData = nullptr;
		other.mLength = 0;
		return *this;
	}

	size_t getLength() { return mLength; }


	void swap(A& other) //move实现swap
	{
		A temp = std::move(other);
		other = std::move(*this);
		*this = std::move(temp);
	}

	int* get_mData() { return mData; }

private:
	int *mData;
	size_t mLength;
};

int main()
{
	A a(11), b(22);
	cout << a.getLength() << ' ' << b.getLength() << endl;
	cout << a.get_mData() << ' ' << b.get_mData() << endl;
	swap(a, b);
	cout << a.getLength() << ' ' << b.getLength() << endl;
	cout << a.get_mData() << ' ' << b.get_mData() << endl;



	return 0;
}

