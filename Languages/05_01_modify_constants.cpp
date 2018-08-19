#include <iostream>
const int gi = 1;

int main() 
{
	int *pgi = const_cast<int*>(&gi);
	//*pgi = 2; //直接报错
	std::cout << gi << std::endl;
	std::cout << *pgi << std::endl;


	const int i = 10;
	int *pi = const_cast<int*>(&i);
	*pi = 11;
	std::cout << i << std::endl; //还是10，由于C++有常量折叠,C里面就会直接修改掉
	std::cout << *pi << std::endl;
	return 0;
}