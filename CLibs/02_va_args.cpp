// 06_多继承子类的指针指向第一个基类.cpp : 定义控制台应用程序的入口点。
//

#include <stdio.h>
#include <stdarg.h>

/*

* `#define va_list char*`
* `#define va_start(ap,arg) (ap=(va_list)&arg+sizeof(arg))` # 把ap设置到第一个变参的位置(自己指定的Arg的后面)
* `#define va_arg(ap,t) (*(t*)(ap+=sizeof(t)-sizeof(t)))` # 就是指针移动自己需要的参数大小的类型而已
* `#define va_end(ap) (ap=(va_list)0)` # 指向null即可，不用delete,是栈上的

*/
void test_va_arg(const char *format, ...)
{
	va_list args;
	va_start(args, format);
	int i = va_arg(args, int);
	double f = va_arg(args, double);
	printf("args:%d,%f\n", i, f);
}


void printFormat(const char *format, ...)
{
	va_list args;
	va_start(args, format);
	char *dst = new char[256];
	//如果要一个一个获取的话，就用va_arg(args,int)这样
	vsnprintf(dst, 256, format, args); //必须先用这个函数生成格式化字符串
	printf(dst);

	//不能直接
	//printf(format, args);

	delete[] dst;
	dst = nullptr;
	va_end(args);
}



//VS里面才能运行，MingW报错
int main()
{
	printFormat("a|%d|%c|%f\n", 1, 'c', 2.3f);
	test_va_arg("test", 1, 2.1);
	return 0;
}
