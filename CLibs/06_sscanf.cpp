#include <iostream>
#include <assert.h>
int main()
{
    const char *str = "123";
    int num;
    sscanf(str, "%d", &num);

    assert(num == 123);

    return 0;
}