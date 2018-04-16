// 40_memcpy和for赋值速度比较.cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"

#include <iostream>
#include <time.h>
#include <windows.h>
using namespace std;
int main() {

	int nTestTime = 10000;
	DWORD timeStart = GetTickCount();
	int nTestSize = 65536*2;
	byte *p = new byte[nTestSize]();
	byte *p1 = new byte[nTestSize]();

	for (int i = 0; i != nTestTime; ++i)
	{
		for (int j = 0; j != nTestSize; ++j)
		{
			p1[j] = p[j];
		}
	}
	cout << "for循环拷贝byte" << nTestSize << "个" << nTestTime << "次耗时:" << (GetTickCount() - timeStart) << endl;

	timeStart = GetTickCount();
	for (int i = 0; i != nTestTime; i++)
	{
		memcpy_s(p1, nTestSize, p, nTestSize);
	}
	cout << "memcpy_s耗时:" << (GetTickCount() - timeStart) << endl;
	//可以看到速度差距还是非常大的
	system("pause");

}