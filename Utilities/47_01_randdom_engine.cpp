// 47_01_11新标准随机数.cpp : 定义控制台应用程序的入口点。
//

#include <random>
#include <iostream>
#include <map>
using namespace std;

inline int randInt(int m, int n)
{
	//srand(0); //这个一定要写在外面
	return rand() % (n - m + 1) + m; //产生m-n的随机数
}

int main()
{
	srand(0);
#pragma region 旧式
	int m = 10, n = 30;
	int nTestTime = 1000000;
	map<int, int> hist;
	for (int i = 0; i != nTestTime; ++i)
		++hist[randInt(m, n)];
	for (auto it = hist.begin(); it != hist.end(); ++it)
		cout << it->first << ":" << it->second / (double)nTestTime << endl;
		//验证可知确实是均匀分布的

#pragma endregion

#pragma region 例子1, 就和以前的rand差不多
	std::default_random_engine e;
	std::cout << e.min() << "," << e.max() << std::endl; //1-int_max
	for (size_t i = 0; i < 10; i++)
	{
		cout << e() << endl;
	}
		//默认情况下，引擎产生的随机数范围在default_randm_engine::min()和default_random_engine::max()之间。
#pragma endregion

#pragma region 例2 : 产生5 - 20的均匀分布
		//std::default_random_engine e;
		//std::uniform_int_distribution<int> u(5, 20); //注意是int,double会报错
		////int的也可以产生unsigned类型的
		//std::uniform_real_distribution<double> u_d(2.0, 30.0);
		//for (size_t i = 0; i < 10; i++) {
		//	//cout << u(e) << endl;   //注意,传递的是e对象
		//	cout << u_d(e) << endl;
		//}
#pragma endregion

#pragma region gamma分步
	// std::default_random_engine e;
	std::gamma_distribution<> u(1.0, 2.0);
	for (size_t i = 0; i < 10; i++)
	{
		cout << u(e) << endl; //注意,传递的是e对象
	}
#pragma endregion

	system("pause");
	return 0;
}
