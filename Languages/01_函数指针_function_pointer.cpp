#include <iostream>
#include <functional>
typedef  void(*func)(int); //三种声明方式
using func1 = void(*)(int);
void (*func2)(int); //这种是直接定义了一个指针了就
std::function<void(int)> func3; //C++风格

void printInt(int i)
{
	std::cout << i << std::endl;
}
int main()
{
	func func_1;
	func_1 = printInt;
	func_1(2);

	func1 func1_1;
	func1_1 = printInt;
	func1_1(2);

	func2 = printInt;
	func2(2);
	


	func3 = printInt;
	func3(2);


	return 0;
}