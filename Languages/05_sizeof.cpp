#include <iostream>
#include <assert.h>

int func()
{
	return 1;
}

int main()
{

	//sizeof是运算符


	{//sizeof是在编译的时候计算的，因此可以用来作为数组长度
		int a = 1;
		int arr[sizeof(a)]; 
	}

	//sizeof 变量名可以不加括号，因为不是函数
	{
		int a = 1;
		size_t a1 = sizeof a;
		assert(a1 == 4);
	}

	{
		int a = 6;
		sizeof(a = 8); //
		assert(a == 6); //执行完了还是6因为sizeof不会被执行，编译期计算
	}

	//sizeof(函数()),等价于对其返回值进行求解
	{
		assert(sizeof(func()==4));
	}

    //
    {
    
    }

	system("pause");
	return 0;
}