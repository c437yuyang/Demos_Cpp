// 52_04_thread_futrue.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


// future example
#include <iostream>       // std::cout
#include <future>         // std::async, std::future
#include <chrono>         // std::chrono::milliseconds

// a non-optimized way of checking for prime numbers:
bool is_prime(int x) 
{
	for (int i = 2; i < x; ++i) 
		if (x%i == 0) return false;
	return true;
}

//为什么要用std::async代替线程的创建
//
//std::async是为了让用户的少费点脑子的，它让这三个对象默契的工作。大概的工作过程是这样的：
//std::async先将异步操作用std::packaged_task包装起来，然后将异步操作的结果放到std::promise中，
//这个过程就是创造未来的过程。外面再通过future.get / wait来获取这个未来的结果，怎么样，std::async真的是来帮忙的吧
//你不用再想到底该怎么用std::future、std::promise和std::packaged_task了，std::async已经帮你搞定一切了！
//
//现在来看看std::async的原型
//
//async(std::launch::async | std::launch::deferred, f, args...)
//1
//第一个参数是线程的创建策略，有两种策略，默认的策略是立即创建线程：
//std::launch::async：在调用async就开始创建线程。
//std::launch::deferred：延迟加载方式创建线程。调用async时不创建线程，直到调用了future的get或者wait时才创建线程。
//第二个参数是线程函数，第三个参数是线程函数的参数。

int main()
{
	{
		// call function asynchronously:
		std::future<bool> fut = std::async(is_prime, 444444443);

		// do something while waiting for function to set future:
		std::cout << "checking, please wait";
		std::chrono::milliseconds span(100);
		while (fut.wait_for(span) == std::future_status::timeout)
			std::cout << '.' << std::flush;

		bool x = fut.get();     // retrieve return value

		std::cout << "\n444444443 " << (x ? "is" : "is not") << " prime.\n";
	}

	{
		std::future<int> future = std::async(std::launch::async, []() {
			std::this_thread::sleep_for(std::chrono::seconds(3));
			return 8;
		});
		std::cout << "waiting...\n";
		std::future_status status;
		do {
			status = future.wait_for(std::chrono::seconds(1));
			if (status == std::future_status::deferred) {
				std::cout << "deferred\n";
			}
			else if (status == std::future_status::timeout) {
				std::cout << "timeout\n";
			}
			else if (status == std::future_status::ready) {
				std::cout << "ready!\n";
			}
		} while (status != std::future_status::ready);

		std::cout << "result is " << future.get() << '\n';
	}

	system("pause");
	return 0;
}