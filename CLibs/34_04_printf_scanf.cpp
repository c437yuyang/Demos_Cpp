// 34_04_printf_��ʽ���ַ���.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include <iostream>
using namespace std;

int main()
{

	int i1 = printf("aaa"); //printf���ص��Ǵ�ӡ�ɹ����ַ���Ŀ,3,�������󷵻ظ�ֵ

	//  C:scanf("%f%3o", &a, &b); ����%f��Ӧ&a��ûɶ���ʣ��ؼ��� % 3o�� % 3o�ǽ���3λ�˽�����������˼����&bƥ�䣬������ȷ��
	//	A����scanf()������ָ�����ȣ������Ʒ�%6.2fΥ��������涨��
	//	B����%n������Ʒ���ɶ��˼��û��������Ʒ���
	//	D���ڰ��޷��ű����Ŀ��Ʒ�д��float�������Ʒ��ˡ�scanf()�������޷�����ʱֻ����%d��%ld�����Ʒ���
	//B�е�%n��ʾ������ַ��ĸ��������޷�������ʾ
	unsigned int n = -1;
	//scanf("%n", &n);
	cout << n << endl; //0

	int i;
	char c;
	//scanf("%d%c%n", &i, &c, &n); //����%n���÷���������ȷ�����������˼��������������������룬������argv���÷�
	cout << n << endl; //0

	printf("%5s", "abcdefg"); //%5s�ǲ���5λ��ǰ���ո񣬳���5λ��ʵ�ʴ�С���

	//demo
	{
		char ch = -1;
		printf(" % 02x, % 02x", ch, (unsigned char)ch); //ffffffff,ff.%x���ǰ������������ģ����������Ȳ�λ������
	}

	//��������ʽ��������������������Ӱ��
	{
		char ch = 'a';
		int k = 12;
		printf("%x,%o,", ch, ch, k); //����kֱ�ӱ����ԣ�����Ӱ�����
		printf("k=%%d\n", k);
	}

	{ //printf�����ʱ��%x��%d���ǰ���int�������������������char���ͣ��������������
		// unsigned int a = 0xFFFFFFF7;
		unsigned int a = 0xFFFFFFF7;
		unsigned char i = (unsigned char)a; //������С�˴洢��i��ֵ��f7
		char *b = (char *)&a;				//bָ��a,������Ϊ��char���ͣ�*�����õ�ʱ��Ҳֻ��һ���ֽڵ�����
		printf("%08x,%08x\n", i, *b);		//a��unsigned�Ჹ��,b���з������ͣ����շ���λ���䣬���0x000000f7��0xfffffff7
		printf("%x,%x\n", i, *b);
		printf("%d,%d\n", i, *b);
	}


	//��ʽ��ƥ������
	{
		printf("\n");
		printf("%f\n", 5);   //���0.0000��ע��%f�Ǵ���double����
		printf("%d\n", 5.1); //���һ���ܴ����
	}

	system("pause");
	return 0;
}
