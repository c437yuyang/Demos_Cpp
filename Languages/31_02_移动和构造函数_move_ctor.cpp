// 31_02_移动和构造函数_move_ctor.cpp : 定义控制台应用程序的入口点。
//

//http://blog.csdn.net/wangshubo1989/article/details/49748703

#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
class A
{
public:

	// Simple constructor that initializes the resource.
	explicit A(size_t length)
		: mLength(length), mData(new int[length])
	{
		std::cout << "A(size_t). length = "
			<< mLength << "." << std::endl;
	}

	// Destructor.
	~A()
	{
		std::cout << "~A(). length = " << mLength << ".";

		if (mData != NULL) 
		{
			std::cout << " Deleting resource.";
			delete[] mData;  // Delete the resource.
		}

		std::cout << std::endl;
	}

	// Copy constructor.（拷贝构造函数也可以使用初始值列表）
	A(const A& other)
		: mLength(other.mLength), mData(new int[other.mLength]) //这种写法，666
	{
		std::cout << "A(const A&). length = "
			<< other.mLength << ". Copying resource." << std::endl;

		std::copy(other.mData, other.mData + mLength, mData);
	}

	// Copy assignment operator.
	A& operator=(const A& other)
	{
		std::cout << "operator=(const A&). length = "
			<< other.mLength << ". Copying resource." << std::endl;

		if (this != &other) { //这种写法是判断地址，省去了自己再实现operator==或者实现一个相等判断的函数
			delete[] mData;  // Free the existing resource.
			mLength = other.mLength;
			mData = new int[mLength];
			std::copy(other.mData, other.mData + mLength, mData);
		}
		return *this;
	}

	// Move constructor.
	A(A&& other) : mData(NULL), mLength(0)
	{
		std::cout << "A(A&&). length = "
			<< other.mLength << ". Moving resource.\n";

		// Copy the data pointer and its length from the 
		// source object.
		mData = other.mData;
		mLength = other.mLength;

		// Release the data pointer from the source object so that
		// the destructor does not free the memory multiple times.
		other.mData = NULL;
		other.mLength = 0;
	}

	// Move assignment operator.
	A& operator=(A&& other)
	{
		std::cout << "operator=(A&&). length = "
			<< other.mLength << "." << std::endl;

		if (this != &other) {
			// Free the existing resource.
			delete[] mData;

			// Copy the data pointer and its length from the 
			// source object.
			mData = other.mData;
			mLength = other.mLength;

			// Release the data pointer from the source object so that
			// the destructor does not free the memory multiple times.
			other.mData = NULL;
			other.mLength = 0;
		}
		return *this;
	}

	// Retrieves the length of the data resource.
	size_t Length() const
	{
		return mLength;
	}

	int * Data()const 
	{
		return mData;
	}

private:
	size_t mLength; // The length of the resource.
	int* mData;     // The resource.
};
int main()
{
	{
		A a1(10);

		A &&rra = std::move(a1);

		A a2 = rra;
		A a3(rra);
		A a4 = std::move(a1); //只有这样才是用的move ctor,上面两种方式都是用的copy ctor

	}

	//move带来的好处:
	//vector众所周知，C++11后对vector也进行了一些优化。
	//例如vector::push_back()被定义为了两种版本的重载，
	//一个是cosnt T&左值作为参数，一个是T&&右值作为参数。例如下面的代码：
	{
		std::vector<A> v;
		v.push_back(A(25)); //可以看到这里因为是临时对象，立刻调用了析构函数但析构函数中的length = 0,代表是用的move ctor
		cout << "==" << endl;
		v.push_back(A(75));
		//上面两个push_back()都会调用push_back(T&&)版本，因为他们的参数为右值(临时对象，即将被销毁)。这样提高了效率。

		A a1(30); //但是非临时对象的这种再去push_back的话，就是左值，因为编译器无法判断你这个值之后是不是还要使用，就只能调用拷贝构造函数了
		v.push_back(a1);
		cout << endl;

		//似乎push_back(T&&)永远是最佳选择，但是一定要记住： 
		//push_back(T&&) 使得参数为空。如果我们想要保留参数的值，我们这个时候需要使用拷贝，而不是移动。

	}

	{
		std::vector<A> v;
		A a2(31);
		//v.push_back(std::move(a2)); //强制调用移动构造函数
		//之后的析构函数里面，输出的length是0，也就是说调用move ctor后，a2就成了空壳了。

		//方法2
		// calls push_back(T&&)
		v.push_back(static_cast<A&&>(a2));

	}
	
	{
		//std::swap这里从运行的结果来看也是调用的move ctor和move assignment
		//下一个例子模拟了这个操作
		A a1(10);
		A a2(20);

		cout << a1.Length() << " " << a2.Length() << endl;
		cout << a1.Data() << " " << a2.Data() << endl;

		std::swap(a1, a2);

		cout << a1.Length() << " " << a2.Length() << endl;
		cout << a1.Data() << " " << a2.Data() << endl;
	}

	system("pause");
    return 0;
}

