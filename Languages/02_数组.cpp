#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
#pragma region 数组相关
	//数组只能在定义的时候赋值组
	{
		//float a[10], x;
		//a = &x; //数组只能在定义的时候赋值，如果定义的是float *a，才能这样

		//int a[3][4] = { 0 };
		//for (int i = 0; i != 12; ++i)
		//{
		//	int w1 = i / 4;
		//	int w2 = i % 4;
		//	a[w1][w2] = i;
		//}
		//int j = a[9]; //不能直接a[9]来访问，a[9]在这里是*(a+9)，是一个一维的数组，不可修改  
	}

	//数组名不可以自加
	{
		int a[4];
		//a++; //报错，数组名是常量
	}

	//二维数组
	{
		int a[2][3] = { 1,2,3,4,5,6 };

		//int a1 = (&a[0] + 1)[2];
		int *p1 = (&a[0] + 1)[1];
		cout << *p1 << endl;
		//int *p = (&a[0] + 1); //表达式的类型是int(*)[3] ,一个指针，指向有三个成员的数组
		int a2 = *(*(a + 1) + 2);//6
		int a3 = ((int *)(&a[0] + 1))[2]; //6
		//&(a[n]) = &(*(a+n)),若a=0,则=a
	}

	//一维数组初始化
	{
		int a[10] = {}; //初始化为了全0,但是这貌似是VC的问题，C++标准没有规定这样也初始化
		int a1[10] = { 10 }; //初始化为了后面全0
		// int a2[10] = { 10,-1,1.1 };// 数组里面本身也是必须要求匹配的类型，VC是对的,MingW会报错
		for_each(a, a + 10, [](int val) { cout << val << " "; });
		// for_each(a2, a2 + 10, [](int val) { cout << val << " "; }); //10 -1 1 0 0 ...,所以就是隐式转型而已
		cout << endl;
	}

	// 二维数组初始化
	{
		using std::printf;
		//int arr[][4]; //还是错的，省去第一维的话必须有赋值数量才能推断
		int arr[][4] = { 1,2,3,4,5,6 }; //正确


		//可以看到二维数组没分配第一维的时候就按照需要来分配，
		//比如第一个就是2，第二个一共5个数，所以第一维需要3，最后总共是6
		//且必须制定分配的列数，行数可以不指定，自动判别
		int a[][2] = { 1,2,3,4 };
		printf("%d\n", sizeof(a) / sizeof(int)); //输出4
		int a1[][2] = { 1,2,3,4,5 };
		printf("%d\n", sizeof(a1) / sizeof(int)); //6()
		int a2[4][2] = { 1,2,3,4,5 };
		printf("%d\n", sizeof(a2) / sizeof(int)); //输出8

		int a3[2][2] = { { 1 },2,3 };
		printf("%d\n", sizeof(a3) / sizeof(int)); //输出4（这个写法是对的）等价于{{1,0},2,3}

												  //新标准的遍历方式可以这样
		int a4[] = { 1,2,3,4,5 };
		for (auto it = begin(a4); it != end(a4); ++it)
		{
			printf("%d\t", *it);
		}
		cout << endl;
		//二维要对每一维再取迭代器
		int a5[2][2] = { 1,2,3,4 };

		for (auto it = begin(a5); it != end(a5); ++it)
		{
			for (auto it1 = begin(*it); it1 != end(*it); ++it1)
			{
				printf("%d\t", *it1);
			}
			cout << endl;

		}
		cout << endl;
	}

#pragma endregion

	system("pause");
	return 0;
}
