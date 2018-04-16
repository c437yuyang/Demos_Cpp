// 03_abort和exit.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <cstdlib> //exit和abort, calloc 和malloc这种也是包含在这个头文件里面的

int main()
{

	//system")

	//abort(); //会弹出错误提示
	exit(EXIT_SUCCESS);
	exit(EXIT_FAILURE);

	calloc(10, 4);

	system("pause");
    return 0;
}

