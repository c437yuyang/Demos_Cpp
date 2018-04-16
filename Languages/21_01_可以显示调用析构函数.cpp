#include <iostream>

class Widget
{
public:
	Widget()
	{
		std::cout << "构造函数" << std::endl;
	}

	void PrintInfo()
	{
		std::cout << "hello" << std::endl;
	}

	~Widget()
	{
		std::cout << "析构函数" << std::endl;

	}
};

int main()
{
	{
		Widget w;
		w.~Widget();
		w.PrintInfo();
	} //首先，是可以显式调用的,可以看到会调用两次析构函数,如果没有申请内存这些需要释放的资源的话，其实还好，不会报异常，如果重复释放就会报异常。


	system("pause"); 
	return 0;
}