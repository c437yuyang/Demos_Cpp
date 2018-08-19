#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <climits>
#include <cassert>
using namespace std;

//采用位段结构既能够节省空间，又方便于操作。
//位段长度digits不能超过类型type对应的数据类型占用的大小，如若type为char，
//则digits不能超过8，为int则digits不能超过32
//位域可以无位域名，这时它只用来作填充或调整位置，无名的位域不能被访问
/*
不能对位段进行取地址操作
若位段占的二进制位数为0，则这个位段必须是无名位段，下一个位段从下一个位段存储单元开始存放
若位段出现在表达式中，则会自动进行整型升级，自动转换为int型或者unsigned int
对位段赋值时，最好不要超过位段所能表示的最大范围，否则可能会造成意想不到的结果
*/

/*
使用位域的主要目的是压缩存储，其大致规则为：

1) 如果相邻位域字段的类型相同，且其位宽之和小于类型的sizeof大小，则后面的字段将紧邻前一个字段存储，直到不能容纳为止；

2) 如果相邻位域字段的类型相同，但其位宽之和大于类型的sizeof大小，则后面的字段将从新的存储单元开始，其偏移量为其类型大小的整数倍；

3) 如果相邻的位域字段的类型不同，则各编译器的具体实现有差异，经实验VC采取不压缩方式，即即使前一个字段有空余位足够容纳后一个字段，后一个字段也当前一个字段           
	没有空余位，从前一个字段类型大小之后的新字节开始存储；

4) 如果位域字段之间穿插着非位域字段，则不进行压缩；

5) 整个结构体的总大小为最宽基本类型成员大小的整数倍。:
*/

//位域说白了就是，不超过

typedef struct bitstruct
{
	int b1 : 5;
	int : 2; //不命名相当于跳过两位
	int b2 : 2;
};


struct bitStruct3
{
	char a : 4; //a 4位，
	char b : 4;//b 8位，
};

struct bitStruct2
{
	int a : 4; //a 4位，最大1111:-1
	int b : 8;//b 8位，最大1111111:-1
};

int main()
{

	bitstruct b;
	cout << sizeof(b) << endl; //4,没有超过32位
	memcpy(&b, "ENC EXCAMINATION", sizeof(b)); //E:0x45 0100 0101 M:0x4e 0100 1110
	printf("%d,%d\n", b.b1, b.b2); //所以b1从低位到高位:10100 空两位(不会因为E只剩下1位了就直接从下一个字节开始，会用这个字节剩下的一位和下个字节开始的一位) 
									//b2:00 ,实际:b1:00101,b2:00
								   //因此是5和0

	bitStruct3 b3;
	memcpy(&b3, "E", 1);
	printf("%d,%d\n", b3.a, b3.b); 

	cout << sizeof(bitStruct2) << endl;
	bitStruct2 b2;
	b2.a = 15;
	b2.b = 255;
	printf("%d\n", b2.a);
	printf("%d\n", b2.b);
	memcpy(&b2, "EMEM",4);
	printf("%d\n", b2.a); //0x5
	printf("%d\n", b2.b);//0xd4

	system("pause");
	return 0;
}