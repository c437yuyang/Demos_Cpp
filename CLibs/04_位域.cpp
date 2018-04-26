// 06_多继承子类的指针指向第一个基类.cpp : 定义控制台应用程序的入口点。
//

#include <iostream>
#include <cstring> //memcpy
using namespace std;

typedef struct bitstruct
{
	int b1 : 5;
	int : 2; //不命名相当于跳过两位
	int b2 : 2;
};

int main()
{

	bitstruct b;
	cout << sizeof(b) << endl; //4,没有超过32位
	memcpy(&b, "EMC EXCAMINATION", sizeof(b)); //E:0x45 0100 0101 M:0x4d 0100 1101
	printf("%d,%d\n", b.b1, b.b2); //所以b1从低位到高位:10100 空两位 b2:01 ,实际:b1:00101,b2:10
	//因此是5和-2

    
    system("pause");
 
	return 0;
}

