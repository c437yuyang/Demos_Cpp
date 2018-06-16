#include <iostream>
using namespace std;

class Parent
{
public:
	Parent()
	{
		printInfo(); //构造函数里调用虚函数，因为基类还没有初始化完全，因此调用的是基类自己的虚函数
	}
	virtual void printInfo()
	{
		cout << "Parent:PrintInfo" << endl;
		print(); //测试构造函数内调用虚函数，这个虚函数再调用虚函数,可以看到输出还是调用的Parent的版本
		//因为虚拟机制本身必须知道这个调用是否源自于一个constructor中
	}
	virtual void print()
	{
		cout << "Parent:print" << endl;
	}
};

class Son :public Parent
{
public:
	Son()
	{
		//printInfo(); //不是说的在子类构造函数调用虚函数，这个是肯定没问题，能够正常调用的
		//但是仍然不建议在这里调用，因为如果涉及到调用成员的内容，那么此时成员还没有被正确初始化，得到的是错误的值
	}
	void printInfo() override
	{
		cout << "Son:PrintInfo()" << endl;
	}

	virtual void print() override
	{
		cout << "Son:print" << endl;
	}

};

int main()
{
	Parent *p = new Son();

	delete p;
	p = nullptr;
	system("pause");

	return 0;
}

