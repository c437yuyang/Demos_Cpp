

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{

	//精度问题
	{
		//小数点后的位权应该是2的负数次方才没有误差，其它的情况都有误差。

		double d1 = 0.1;

		double d2 = pow(10, 30);
		double d3 = 0.5;
		double d4 = 0.25;
		//double d41 = 0.26;
		double d5 = 0.125;
		double d6 = 0.111;
		cout << d1 << endl; //从调试窗口可以看到是0.10000000000000001，但是cout出来的是0.1
		if (d1 == 0.1)
		{
			cout << "d1 == 0.1" << endl; //但是这里仍然会执行，说明==号内部是做了处理的
		}
		if (d1 == 0.10000000000000001)
		{
			cout << "d1 == 0.10000000000000001" << endl; //执行
		}
		if (d1 == 0.1000000000001) //少两个0这个就不执行了
		{
			cout << "d1 == 0.1000000000001" << endl; //不会执行，具体是怎么个处理法？
		}
		if (d1 == 0.100000000000000001) //多一位精度(0)是要执行的
		{
			cout << "d1 == 0.100000000000000001" << endl; //执行
		}
		cout << d2 << endl;


		double d7 = 0.0;
		if (d7 == 0.0) cout << "d7 = 0.0" << endl; //也是可以直接判断的，是VS做了处理？
	}
	
	//double、float也可以自增自减
	{
		double d1 = 1.1;
		double d2 = d1++; //d1 = 2.1
	}

	system("pause");
	return 0;
}
