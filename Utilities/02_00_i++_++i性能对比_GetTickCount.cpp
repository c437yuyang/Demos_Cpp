#include <iostream>
#include <time.h>
#include <windows.h>
using namespace std;

void TestCriticalPath();
int main()
{
	TestCriticalPath();

	int nTestTime = 10000000000000;
	DWORD timeStart = GetTickCount();
	for (int i = 0; i != nTestTime; ++i)
	{
		;
	}
	cout << "++i耗时:" << (GetTickCount() - timeStart) << endl;

	timeStart = GetTickCount();
	for (int i = 0; i != nTestTime; i++)
	{
		;
	}
	cout << "i++耗时:" << (GetTickCount() - timeStart) << endl;


	//还需要注意，++i返回的是i的引用，左值
	//而i++返回的是i的值的副本，不能当左值

	int i = 0;
	(++i) += 1;
	//(i++) += 1; //报错，不是左值
	cout << i << endl; //2
	system("pause");
	//经过测试,日了狗一样的竟然i++更快！！！，所以平时就用i++吧；
}


double Poly1(double arr[], double x, long degree)
{
	long i;
	double result = arr[0];
	double xpwr = x;
	for (i = 1; i <= degree; ++i)
	{
		result += arr[i] * xpwr;
		xpwr = x * xpwr;
	}
	return result;
}

double Poly2(double arr[], double x, long degree)
{
	long i;
	double result = arr[degree];
	for (int i = degree - 1; i >= 0; --i)
	{
		result = arr[i] + x*result;
	}
	return result;
}

//这是CSAPP书上的练习题5.5和5.6 表明了有时候自己认为的优化其实是错误的
void TestCriticalPath()
{
	double arr[] = { 1.1,2.2,3.3,4.4,5.5,6.6,7.7,8.8 };
	long degree = 7;
	double x = 3.14151231;
	int nTestTime = 10000000000000;

	DWORD timeStart = GetTickCount();
	for (int i = 0; i != nTestTime; ++i)
	{
		double d = Poly1(arr, x, degree);
	}
	cout << "poly1耗时:" << (GetTickCount() - timeStart) << endl;

	timeStart = GetTickCount();
	for (int i = 0; i != nTestTime; i++)
	{
		double d = Poly2(arr, x, degree);
	}
	cout << "poly2耗时:" << (GetTickCount() - timeStart) << endl;

}