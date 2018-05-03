#include <cstdlib>
#include <cstdio>
#include <assert.h>
int main()
{
    char buf[10];
    int  target = 123456;
    snprintf(buf,10,"%d",target); //格式化到指定buffer，比sprintf多一个参数指定大小
    printf("%s\n",buf);
    return 0;
}