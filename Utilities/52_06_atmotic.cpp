#include <thread>
#include <atomic>
#include <iostream>
const int N = 10000000;
std::atomic_int num{0}; //不会发生线程冲突，线程安全

void run()
{
	for (int i = 0; i < N; i++)
		// num++;
		num = num + 1;
}
int main()
{
	clock_t start = clock();
	std::thread t1(run);
	std::thread t2(run);
	t1.join();
	t2.join();
	clock_t end = clock();
	std::cout << "num=" << num << ",用时 " << end - start << " ms" << std::endl; //比直接用metex要慢得多
	return 0;
}