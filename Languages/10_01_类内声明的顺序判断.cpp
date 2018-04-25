#include <iostream>
#include <assert.h>
using namespace std;
typedef int length;
class Point3d
{
public:
	void printInfo(length i) { std::cout << typeid(i).name() << std::endl; }

private:
	typedef long length;

};

int main()
{
	Point3d pt;
	pt.printInfo(10); //可以看到 参数列表的类型是优先使用第一次遇到的时候的定义，之类就是全局范围的int



	return 0;
}
