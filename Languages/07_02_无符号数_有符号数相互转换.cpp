
#include <iostream>
using namespace std;

int main()
{
	//todo:不知道为啥
	signed char a = 0xe0;
	unsigned int b = a;
	unsigned char c = a;
	unsigned char d = 0xe0;

	//整型提升是C程序设计语言中的一项规定：在表达式计算时（包括比较运算和算术运算等），比int类型小的类型（char,
	//signed char, unsigned char, short, unsigned short等）首先要提升为int类型，然后再执行表达式的运算。

	cout << (c == a) << endl;//false,
	//这里之所以是false,是因为char类型在比较的时候，会转型成int,而在转型成Int的过程中，就出现了不一样了
	//下面就是例子
	unsigned int i1 = c;
	signed int i2 = a;

	cout << (b == a) << endl;//true

	cout << (a == d) << endl;//false
	unsigned char e = a;


	signed int a1 = 0xe0000000;
	unsigned int b1 = a1;
	cout << (b1 == a1) << endl; //true

	signed int a2 = 0x01;
	unsigned int b2 = a2;
	cout << (b2 == a2) << endl;//true


	system("pause");
	return 0;
}
