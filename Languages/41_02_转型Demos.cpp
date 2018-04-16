#include <iostream>

//这里的例子都来自exceptional C++ 条款44
class A { public: virtual ~A(); };
A::~A() {}

class B :private virtual A {};
class C :public A {};
class D :public B, public C {};

A a1; B b1; C c1; D d1;
const A a2;
const A&ra1 = a1;
const A&ra2 = a2;
char c;

//f()中看的是每种旧式转换可以替换成的新式转换
void f()
{
	A *pa; B *pb; C *pc;

	pa = (A*)&ra2; //常量引用取地址仍然是const的指针
	auto p = &ra2; //用auto 关键字可以看到，p的类型现在是const A*
	pa = const_cast<A *>(&ra2); //a2是const对象，使用这个指针将导致未定义的结果

	pb = (B*)&c1; //这里的C和B类型是无关的，因此需要使用reinterpret_cast
	pb = reinterpret_cast<B*>(&c1);

	pc = (C*)&d1; //D继承自C 可以直接用父类的指针指向
	//比如这样
	pc = &d1;//下面的也都可以转型(向上转型)
	pc = static_cast<C*>(&d1); //static_cast 只要两个类有关系就可以
	pc = dynamic_cast<C*>(&d1); //dynamic_cst也可以向上转型
	pc = reinterpret_cast<C*>(&d1); //reinterpret_cast 最强，啥都能干
}

//下面的g()函数看的是每个转型的正确性
void g()
{
	//unsigned char * puc = static_cast<unsigned char *>(&c); //错误，两者是完全不相干的类型
	//应该:
	unsigned char * puc = reinterpret_cast<unsigned char *>(&c);

	auto p = &c;
	char * p1;
	//signed char * psc = static_cast<signed char *> (p1); //还是不行，两者无关，就算是char* 和 signed char * 也是无关的。。

	void *pv = static_cast<void *>(&b1);
	pv = &b1;
	B* pb1 = static_cast<B*>(pv);

	A*pa1 = const_cast<A*>(&ra1); //const_cast去掉常量属性，其实这种方法不太好，建议通过mutable关键字来改善

	A *pa2 = const_cast<A*>(&ra2); //是可以去掉，但是因为a2对象是const的(编译器针对常量对象或许会做优化)，因此如果这里去掉了后再来使用这个对象，会产生未定义的值

	B *pb3 = dynamic_cast<B*>(&c1); //运行时，dynamic_cast会把pb3的值设置为NULL,因为两个类没有关系其实，这里实在要转换的话只能使用reinterpret_cast

	//A *pa3 = dynamic_cast<A*> (&b1); //报错，虽然b从A继承，但是不是public继承，因此报错，这里g()如果是B的 友元函数即可。这里用reinterpret_cast仍然可以，后面就不说了。





}


int main()
{

	f();
	g();
	return 0;
}

