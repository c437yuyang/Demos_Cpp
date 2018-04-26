// 34_04_printf_格式化字符串.cpp : 定义控制台应用程序的入口点。
//

#include <iostream>
using namespace std;

int main()
{

	int i1 = printf("aaa"); //printf返回的是打印成功的字符数目,3,发生错误返回负值

	//  C:scanf("%f%3o", &a, &b); ——%f对应&a，没啥疑问，关键是 % 3o。 % 3o是接受3位八进制整数的意思，与&b匹配，所以正确。
	//	A错在scanf()不允许指定精度，而控制符%6.2f违反了这个规定；
	//	B错在%n这个控制符是啥意思？没有这个控制符！
	//	D错在把无符号变量的控制符写成float变量控制符了。scanf()在输入无符号数时只能用%d或%ld作控制符。
	//B中的%n表示输入的字符的个数，用无符号数表示
	unsigned int n = -1;
	//scanf("%n", &n);
	cout << n << endl; //0

	int i;
	char c;
	//scanf("%d%c%n", &i, &c, &n); //所以%n的用法就是用来确定到底输入了几个，并不真正接受输入，类似于argv的用法
	cout << n << endl; //0

	printf("%5s", "abcdefg"); //%5s是不足5位，前补空格，超过5位则按实际大小输出

	//demo
	{
		char ch = -1;
		printf(" % 02x, % 02x", ch, (unsigned char)ch); //ffffffff,ff.%x还是按照整形来看的，所以这里先补位成整形
	}

	//输出项与格式描述符个数不符，不会影响
	{
		char ch = 'a';
		int k = 12;
		printf("%x,%o,", ch, ch, k); //这里k直接被忽略，不会影响后面
		printf("k=%%d\n", k);
	}

	{ //printf输出的时候，%x，%d都是按照int进行输出，因此如果传递char类型，会进行整型提升
		// unsigned int a = 0xFFFFFFF7;
		unsigned int a = 0xFFFFFFF7;
		unsigned char i = (unsigned char)a; //由于是小端存储，i的值是f7
		char *b = (char *)&a;				//b指向a,但是因为是char类型，*解引用的时候也只有一个字节的数据
		printf("%08x,%08x\n", i, *b);		//a是unsigned会补零,b是有符号类型，按照符号位补充，输出0x000000f7和0xfffffff7
		printf("%x,%x\n", i, *b);
		printf("%d,%d\n", i, *b);
	}


	//格式不匹配的情况
	{
		printf("\n");
		printf("%f\n", 5);   //输出0.0000，注意%f是传入double的数
		printf("%d\n", 5.1); //输出一个很大的数
	}

	system("pause");
	return 0;
}
