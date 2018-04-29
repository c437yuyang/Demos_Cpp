// 06_多继承子类的指针指向第一个基类.cpp : 定义控制台应用程序的入口点。
//

#include <iostream>

using namespace std;


class Point
{
public:
	//int x() const { return x_; } //不知道怎么处理const,暂时先不管
	//int y() const { return y_; }

	int x() { return x_; }
	int y() { return y_; }
	static void printInfo() { std::cout << "Point::printInfo()" << std::endl; }
	virtual int z() { return z_; }
private:
	int x_ = -1, y_ = -2, z_ = 3;
};

int main()
{
	//normal member function
	int (Point::* pmf)(); //声明一个指向Point类内的成员函数指针
	pmf = &Point::x; //返回的是函数在内存中真正的地址，但是必须有this指针才能调用
	Point p;
	int ret_x = (p.*pmf)(); //这样调用
	std::cout << ret_x << std::endl;

	//static member function 就不需要this指针，类型也就是普通的函数指针
	void(*psf)() = &Point::printInfo;
	psf(); //可以直接和一般函数一样调用


	//virtual member function
	auto offset = &Point::z; //可以看到对虚函数取地址，类型是int Point::* 取出来是一个offset
	int ret_z = (p.*offset)();

	return 0;
}

