
//参考自 More Effective C++
//4.4 M8:operator new 和 new operator
// 1.new 一个对象的时候，调用的是new operator,这个是系统的操作符，不能修改
// 2.new Widget()  (此时就是调用的new operator)的内部会调用operator new,再调用构造函数，所以
// operator new的作用就类似于malloc，负责分配内存，但是完全和构造函数无关
// 3.placement new的作用是对于已经分配好的raw内存，显式调用构造函数构造对象再返回其指针
// 4.如果想要定制堆对象创建的内存分配过程，可以重写operator new

//以下来自https://www.cnblogs.com/luxiaoxun/archive/2012/08/10/2631812.html

//new operator/delete operator就是new和delete操作符，而operator new / operator delete是函数。
//
//new operator
//（1）调用operator new分配足够的空间，并调用相关对象的构造函数
//（2）不可以被重载
//
//operator new
//（1）只分配所要求的空间，不调用相关对象的构造函数。当无法满足所要求分配的空间时，则
//->如果有new_handler，则调用new_handler，否则
//->如果没要求不抛出异常（以nothrow参数表达），则执行bad_alloc异常，否则
//->返回0
//（2）可以被重载
//（3）重载时，返回类型必须声明为void*
//（4）重载时，第一个参数类型必须为表达要求分配空间的大小（字节），类型为size_t
//（5）重载时，可以带其它参数
//
//delete 与 delete operator类似，delete operator先调用析构函数，再调用operator delete删除内存
//
//new operator与delete operator的行为是不能够也不应该被改变，这是C++标准作出的承诺。
//而operator new与operator delete和C语言中的malloc与free对应，只负责分配及释放空间。
//但使用operator new分配的空间必须使用operator delete来释放，而不能使用free，因为它们对内存使用的登记方式不同。
//反过来亦是一样。你可以重载operator new和operator delete以实现对内存管理的不同要求
//但你不能重载new operator或delete operator以改变它们的行为。
//
//为什么有必要写自己的operator new和operator delete？
//答案通常是：为了效率。缺省的operator new和operator delete具有非常好的通用性
//它的这种灵活性也使得在某些特定的场合下，可以进一步改善它的性能.
//尤其在那些需要动态分配大量的但很小的对象的应用程序里，情况更是如此。
//具体可参考《Effective C++》中的第二章内存管理。

#include "stdafx.h"
#include <iostream>
#include <string>
#include <new>
using namespace std;

class X
{
public:
	X() { cout << "constructor of X" << endl; }
	~X() { cout << "destructor of X" << endl; }

	static void* operator new(size_t size) //operator new 应该声明为静态(即使没有使用static进行声明，但是仍然是静态的，但即使如此依然表现得跟虚函数一样),重载了operator new的话就要重载相应的operator delete
	{
		cout << "operator new size: " << size << endl;
		return ::operator new(size);
	}

	static void* operator new(size_t size, string str) //可以重载,但是因为本身placement new就是operator new的一个特殊版本，因此重载了operator new就不能使用placement new了
	{
		cout << "operator new size " << size << " with string " << str << endl;
		return ::operator new(size);
	}

	static void operator delete(void* pointee)
	{
		cout << "operator delete" << endl;
		::operator delete(pointee);
	}

	static void operator delete(void* pointee, string str) //这个函数其实一般情况下不会被调用,只有当构造函数报异常的时候才会调用对应的这个版本
		//如果不定义这个版本，在对应版本的operator new 报异常的时候就根本不会调用析构函数。。
		//所以只有当报异常的时候，这个版本的作用才会体现出来。
		//参考自:https://www.cnblogs.com/cly-blog/p/5984660.html
	{
		cout << "operator delete with string" << endl; 
		::operator delete(pointee);
	}



private:
	int num;
};

int main()
{
	X *px = new("A new class") X;
	X *px1 = new X;
	delete px; //还是会调用单参数版本的operator delete
	delete px1;

	X*px2 = (X *)operator new(sizeof(X)); //调用的全局的
	X*px3 = (X *)X::operator new(sizeof(X)); //调用的X的静态函数
	
	//但是在重载了operator new的情况下，就没法构造对象了吗? (不能使用placement new了)
	//但是可以使用new operator啊！！！，所以重载这个用于调试很有用
	//X* px4 = new((void *)px3) X();

	//参见:http://blog.csdn.net/wudaijun/article/details/9273339

	return 0;
}
