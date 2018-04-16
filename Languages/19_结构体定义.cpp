// 19_结构体定义.cpp : 定义控制台应用程序的入口点。
//



#include "stdafx.h"
#include <iostream>
using namespace std;


struct student1
{
	int no;
	char name[10];
	float score;
};

//struct stud[20]  //错
//{
//	int no;
//char name[10];
//float score;
//};

struct student2
{
	int no;
	char name[10];
	float score;
} stud2[20];  //也对,定义结构体并声明一个[20]的数组


struct
{
	int no;
	char name[10];
	float score;
}stud3[100]; //也对，不能显示访问结构体，但是定义了[100]的数组


typedef struct student4
{

}stud4; //c++和C里面有了typedef，则stud4是一个类型别名，只是c++也可以不用struct，直接访问类型，所以c++里面typedef不是那么有用

//http://blog.csdn.net/itguangit/article/details/50117295

int main()
{

	//对于第一种定义，struct student1和student都可以，C里面必须指明struct student1 xxx
	student1 stu1;
	student2 stu2;
	stud2[1].name;  //访问前面声明的数组
	stud3[1].no; //访问前面声明的数组

	system("pause");
	return 0;
}
