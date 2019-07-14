// 52_03_thread_joinable.cpp : 定义控制台应用程序的入口点。
//

#include <iostream>       // std::cout
#include <thread>         // std::thread

void mythread()
{
	// do stuff...
}

//一旦 detached, 就不能再join 
int main()
{
	std::thread foo;
	std::thread bar(mythread);

	std::cout << "Joinable after construction:\n" << std::boolalpha;
	std::cout << "foo: " << foo.joinable() << '\n';
	std::cout << "bar: " << bar.joinable() << '\n';

	if (foo.joinable()) foo.join();
	if (bar.joinable()) bar.join();

	std::cout << "Joinable after joining:\n" << std::boolalpha;
	std::cout << "foo: " << foo.joinable() << '\n';
	std::cout << "bar: " << bar.joinable() << '\n';

	return 0;
}
