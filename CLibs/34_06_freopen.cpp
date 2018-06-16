#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE *stream = freopen("freopen.out", "w", stderr); //将标准错误输出重定向到freopen.out文件
    
    if (stream == NULL)
        fprintf(stdout, "error on freopen\n");
    else
    {
        fprintf(stdout, "successfully reassigned\n");
        fflush(stdout);
        fprintf(stream, "This will go to the file 'freopen.out'\n");
        fprintf(stderr, "Also you can do it like this!\n");
        fclose(stream);
    }

    // windwos下读取文件 freopen.out
    system("type freopen.out");
    getchar();
    return 0;
}