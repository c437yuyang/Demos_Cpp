// 52_04_thread_futrue.cpp : �������̨Ӧ�ó������ڵ㡣
//
//�úÿ����������  https://www.cnblogs.com/qicosmos/p/3534211.html

// future example
#include <iostream> // std::cout
#include <future>   // std::async, std::future
#include <chrono>   // std::chrono::milliseconds

// a non-optimized way of checking for prime numbers:
bool is_prime(int x)
{
	for (int i = 2; i < x; ++i)
		if (x % i == 0)
			return false;
	return true;
}

//ΪʲôҪ��std::async�����̵߳Ĵ���
//�̱߳Ͼ������ڱȽϵͲ�εĶ�������ʱ��ʹ����Щ���㣬������ϣ����ȡ�̺߳����ķ��ؽ����ʱ��
//�ҾͲ���ֱ��ͨ��thread.join()�õ��������ʱ�ͱ��붨��һ�����������̺߳�����ȥ�����������ֵ��Ȼ��join,
//���õ��������������ǱȽϷ����ġ�c++11�ṩ���첽�ӿ�std::async��ͨ������첽�ӿڿ��Ժܷ���Ļ�ȡ�̺߳�����ִ�н����
//std::async���Զ�����һ���߳�ȥ�����̺߳�����������һ��std::future�����future�д洢���̺߳������صĽ����
//��������Ҫ�̺߳����Ľ��ʱ��ֱ�Ӵ�future�л�ȡ���ǳ����㡣
//
//std::async��Ϊ�����û����ٷѵ����ӵģ���������������Ĭ���Ĺ�������ŵĹ��������������ģ�
//std::async�Ƚ��첽������std::packaged_task��װ������Ȼ���첽�����Ľ���ŵ�std::promise�У�
//������̾��Ǵ���δ���Ĺ��̡�������ͨ��future.get / wait����ȡ���δ���Ľ������ô����std::async���������æ�İ�
//�㲻�����뵽�׸���ô��std::future��std::promise��std::packaged_task�ˣ�std::async�Ѿ�����㶨һ���ˣ�
//
//����������std::async��ԭ��
//
//async(std::launch::async | std::launch::deferred, f, args...)
//1
//��һ���������̵߳Ĵ������ԣ������ֲ��ԣ�Ĭ�ϵĲ��������������̣߳�
//std::launch::async���ڵ���async�Ϳ�ʼ�����̡߳�
//std::launch::deferred���ӳټ��ط�ʽ�����̡߳�����asyncʱ�������̣߳�ֱ��������future��get����waitʱ�Ŵ����̡߳�
//�ڶ����������̺߳������������������̺߳����Ĳ�����

int main()
{
	{
		// call function asynchronously:
		std::future<bool> fut = std::async(is_prime, 444444443);

		// do something while waiting for function to set future:
		std::cout << "checking, please wait";
		std::chrono::milliseconds span(100);
		while (fut.wait_for(span) == std::future_status::timeout) //get�ǵȴ����õ�����ֵ��wait()�������ȴ���waitfor()���з���״̬�ĳ�ʱ�ȴ�
			std::cout << '.' << std::flush;

		bool x = fut.get(); // retrieve return value

		std::cout << "\n444444443 " << (x ? "is" : "is not") << " prime.\n";
	}

	{
		std::future<int> future = std::async(std::launch::async, []() {
			std::this_thread::sleep_for(std::chrono::seconds(3));
			return 8;
		});
		std::cout << "waiting...\n";
		std::future_status status;
		do
		{
			status = future.wait_for(std::chrono::seconds(1));
			if (status == std::future_status::deferred)
			{
				std::cout << "deferred\n"; //��û��ʼ
			}
			else if (status == std::future_status::timeout)
			{
				std::cout << "timeout\n"; //������ʱ(���ڽ�����)
			}
			else if (status == std::future_status::ready)
			{
				std::cout << "ready!\n"; //�Ѿ����
			}
		} while (status != std::future_status::ready);

		std::cout << "result is " << future.get() << '\n';
	}

	{
		std::future<int> future = std::async(std::launch::deferred, []() {
			std::this_thread::sleep_for(std::chrono::seconds(3));
			return 8;
		});

		future.wait(); //wait()�������ȴ�
		auto ret = future.get(); //���ǿ����÷���ֵ
		std::cout << "ret is " << ret << std::endl;
	}

	system("pause");
	return 0;
}