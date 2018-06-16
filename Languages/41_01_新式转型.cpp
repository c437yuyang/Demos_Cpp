// 41_新式转型.cpp : 定义控制台应用程序的入口点。
//

#include <iostream>
using namespace std;
void doSomething(double &d) {}

class  Widget
{
public:
	Widget();
	virtual ~Widget();

private:

};

class SpecialWidget :public Widget {};

class SpecialWidget1 {};

Widget::Widget()
{
}

Widget::~Widget()
{
}

int main()
{

	// 1.static_cast类似于旧式转型，但是不能去除常量性(只是底层const不能去除)
	double d = static_cast<double>(5);
	double d1 = 1.1;
	const double d2 = static_cast<const double>(d1); //可以加上常量性

	double dd = static_cast<double>(d2); //普通const和顶层const是可以去掉的
	double * const p1 = &d;
	double * p2 = static_cast<double *>(p1);

	const double * p3 = &d;
	//double *p4 = static_cast<double *>(p3); //报错，不能去除底层const


	// 2.const_cast，移出常量性，包含底层const
	const double d3 = 1.1;
	doSomething(const_cast<double&>(d3));

	// 3.dynamic_cast实现向下安全转型，由父类指针向下转型
	Widget *w = new SpecialWidget;
	//SpecialWidget *w1 = w;//报错
	SpecialWidget *w1 = dynamic_cast<SpecialWidget*>(w); //要求类型必须具有多态性质(虚函数)
	SpecialWidget *w2 = static_cast<SpecialWidget*>(w); //static_cast也可以，不过不一定安全
	//SpecialWidget1 *w11 = dynamic_cast<SpecialWidget*>(w); //没有继承关系也不能转型


	// 4.reinterpret_cast实现低级转型，比如pointer to int 转 int,或者int*直接转换成char *,转换后是很危险的
	int *ip1 = new int(10);
	//int i = p1; //报错
	int i = reinterpret_cast<int>(ip1); //打印出来就是指针的地址值

	// 5.以上四个，除了dynamic_cast旧式操作无法实现(也可以转，只是不检测是否可以正确的转型)
	// 旧式操作都可以实现

	cout << i << endl;

	return 0;
}

//这篇文章总结的不错:https://www.cnblogs.com/carsonzhu/p/5251012.html
//1、static_cast:可以实现C++中内置基本数据类型之间的相互转换，enum、struct、 int、char、float等。它不能进行无关类型(如非基类和子类)指针之间的转换。
//如果涉及到类的话，static_cast只能在有相互联系的类型中进行相互转换,不一定包含虚函数。
//2、const_cast: const_cast操作不能在不同的种类间转换。相反，它仅仅把一个它作用的表达式转换成常量。它可以使一个本来不是const类型的数据转换成const类型的，或者把const属性去掉。
//3、reinterpret_cast : （interpret是解释的意思，reinterpret即为重新解释，此标识符的意思即为数据的二进制形式重新解释，但是不改变其值。）"有着和C风格的强制转换同样的能力"。
//它可以转化任何内置的数据类型为其他任何的数据类型，也可以转化任何指针类型为其他的类型。它甚至可以转化内置的数据类型为指针，无须考虑类型安全或者常量的情形。不到万不得已绝对不用。
//4、dynamic_cast :
//	（1）其他三种都是编译时完成的，dynamic_cast是运行时处理的，运行时要进行类型检查。
//	（2）不能用于内置的基本数据类型的强制转换。
//	（3）dynamic_cast转换如果成功的话返回的是指向类的指针或引用，转换失败的话则会返回NULL。
//	（4）使用dynamic_cast进行转换的，基类中一定要有虚函数，否则编译不通过。
//	需要检测有虚函数的原因：类中存在虚函数，就说明它有想要让基类指针或引用指向派生类对象的情况，此时转换才有意义。
//	这是由于运行时类型检查需要运行时类型信息，而这个信息存储在类的虚函数表（关于虚函数表的概念，详细可见<Inside c++ object model>）中，
//	只有定义了虚函数的类才有虚函数表。
//	（5） 在类的转换时，在类层次间进行上行转换时，dynamic_cast和static_cast的效果是一样的。
//在进行下行转换 时，dynamic_cast具有类型检查的功能，比static_cast更安全。向上转换即为指向子类对象的向下转换，即将父类指针转化子类指针。
//向下转换的成功与否还与将要转换的类型有关，即要转换的指针指向的对象的实际类型与转换以后的对象类型一定要相同，否则转换失败。