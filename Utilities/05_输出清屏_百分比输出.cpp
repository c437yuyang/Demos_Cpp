#include <iostream>
#include <fstream>
#include <thread>
#include <chrono>
#include <string>

//static const std::string clear = "\r" + std::string(80, ' ') + "\r";
static const std::string clear = "\r"; //直接\r就可以了

//实现同一位置输出百分比
int main() {
	std::cout << "Hello, World!" << std::endl;
	std::cout << "Hello, World1!" << std::endl;
	std::ofstream tty("/dev/tty", std::ios_base::out);
	for (int i = 0; i < 1000; ++i) {
		//        std::cout <<clear << "percent:" << "%..." << i << std::endl;
		//        tty << clear << i << "%" << std::flush; //linux才能用，不能在CLion里面执行，看不到，要自己在bash里面执行
		std::cout << clear << i << "%" << std::flush; //这样就windows也能用了，Clion里面执行也能用
		std::this_thread::sleep_for(std::chrono::milliseconds(1));
	}
	std::cout << std::endl << "finished" << std::endl;

	return 0;
}