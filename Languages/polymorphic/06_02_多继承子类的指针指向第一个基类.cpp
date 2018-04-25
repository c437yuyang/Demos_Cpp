// 06_多继承子类的指针指向第一个基类.cpp : 定义控制台应用程序的入口点。
//

#include <iostream>
using namespace std;

class Point3d
{
public:
	//virtual ~Point3d() {}
public:
	static Point3d origin;
	float x, y, z;
};

Point3d Point3d::origin;


int main()
{

	//这样是错的，输出都是1
	std::cout << &Point3d::x << std::endl;
	std::cout << &Point3d::y << std::endl;
	std::cout << &Point3d::z << std::endl;


	//输出成员在类内的偏移量
	//详情见深度搜索C++对象模型中的P131页
	printf("%p\n", &Point3d::x); //4
	printf("%p\n", &Point3d::y); //8
	printf("%p\n", &Point3d::z); //C


	//输出实际地址
	Point3d pt;
	printf("%p\n", &pt); //xxx0
	printf("%p\n", &pt.x); //xxx4
	//printf("%p\n", &pt.x - &Point3d::x); //理论上这样能够得到对象的起始地址，实际上编译会报错的，因为&Point3d::x的类型是float Point3d *,不能强制转换。。
	printf("%p\n", &pt.y); //xxx8
	printf("%p\n", &pt.z); //xxx12
	//可以看到VC里面，虚函数指针是放在头部的，注释掉虚析构函数可以验证
	//MingW里面，虚函数指针是放在尾部的
	//GCC也是在尾部的

	//所以多重继承这个东西，很取决于编译器
	return 0;
}

