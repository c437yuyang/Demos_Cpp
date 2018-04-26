// 06_多继承子类的指针指向第一个基类.cpp : 定义控制台应用程序的入口点。
//


#include <strings.h> //strcasecmp
#include <iostream>
#include <assert.h>
#include <string.h>
int main()
{



    printf("%d\n",strcasecmp("aa","Aa")); //0
    printf("%d\n",strcasecmp("ab","Aa")); //1
    assert(stricmp("aa","AA")==0);
    
    system("pause");
 
	return 0;
}

