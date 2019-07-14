#include <thread>  
#include <mutex>  
#include <iostream>
//using namespace std;
const int N = 1000000; //编译的时候要加 -pthread,VS里面可以运行
int num(0);
std::mutex m;
void run() {
	for (int i = 0; i < N; i++) {
		//m.lock(); //注释加锁部分可以看到会出错
		//num++;
		//m.unlock();

		//同样的效果
		std::unique_lock<std::mutex> ul(m); //ctor自动调用m.lock(),dtor中自动调用m.unlock()
		num++;
	}
}
int main() {
	clock_t start = clock();
	std::thread t1(run);
	std::thread t2(run);
	t1.join();
	t2.join();
	clock_t end = clock();
	std::cout << "num=" << num << ",用时 " << end - start << " ms" << std::endl;
	return 0;
}