//关于条件变量的说明:https://www.cnblogs.com/codingmengmeng/p/7249082.html
#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include <condition_variable>

std::mutex mutex;
std::condition_variable cv;
std::string data;
bool ready = false;
bool processed = false;

void worker_thread() {

	std::cout << "worker thread created, wait for main thread sends data\n";

	// Wait until main() sends data
	std::unique_lock<std::mutex> lk(mutex);
	cv.wait(lk, [] {return ready; });

	// after the wait, we own the lock.
	std::cout << "Worker thread is processing data\n";
	data += " after processing";

	// Send data back to main()
	processed = true;
	std::cout << "Worker thread signals data processing completed\n";

	// Manual unlocking is done before notifying, to avoid waking up
	// the waiting thread only to block again (see notify_one for details)
	lk.unlock();
	cv.notify_one();
}

int main() {
	std::thread worker(worker_thread);
	std::this_thread::sleep_for(std::chrono::seconds(1));
	data = "Example data";
	// send data to the worker thread
	{
		std::lock_guard<std::mutex> lk(mutex);
		ready = true;
		std::cout << "main() signals data ready for processing\n";
	}
	cv.notify_one();

	// wait for the worker
	{
		std::unique_lock<std::mutex> lk(mutex);
		cv.wait(lk, [] {return processed; });
	}
	std::cout << "Back in main(), data = " << data << '\n';

	worker.join();
	return 0;
}