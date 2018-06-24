// 06_多继承子类的指针指向第一个基类.cpp : 定义控制台应用程序的入口点。
//

#include <stdio.h>
#include <stdarg.h>

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
    printFormat("a|%d|%c|%f", 1, 'c', 2.3f);

    return 0;
}
