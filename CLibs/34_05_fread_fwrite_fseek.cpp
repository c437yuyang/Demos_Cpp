// 34_05_fread_fwrite_fseek.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


#include <stdio.h>

int main()

{

	FILE *fp;  //定义一个文件指针fp

	int i, a[6] = { 1,2,3,4,5,6 }, k;  //定义数组和临时变量

	fp = fopen("data.dat", "w+b");  //打开一个可读可写文件，如果文件不存在则创建之，以二进制的方式操作

	for (i = 0; i < 6; i++)  //循环六次

	{

		fseek(fp, 0L, 0);  //将文件指针指向文件的开头,因此每次都写在了最开始

		fwrite(&a[5 - i], sizeof(int), 1, fp);  //将数组从后面开始的字符依次写入到fp所指的文件中

	}

	rewind(fp);//将文件指针指向文件的开头

	fread(&k, sizeof(int), 1, fp);  //读取文件中的一个int型数据，写入到k变量中

	fclose(fp);  //关闭文件指针

	printf("%d", k);  //打印k的值1
	getchar();
	return 0;
}

