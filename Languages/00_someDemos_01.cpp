#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
//void f(int n);
int main()
{
#pragma region �ؼ������
	//ifelse��֧����
	{
		int k1, k2, k3, x;
		k1 = 1;
		k2 = 2;
		k3 = 3;
		x = 15;
		if (!k1) //��֧���ÿһ����ͬ�ȵģ�����һ���Ͳ����ٽ�ͬһ���ķ�֧������������ֱ���ߵ�else if��û������else��
			x--;
		else if (k2)
			x = 4;
		else
			x = 3;
	}

	//switch,default����ǰ��Ҳ�����ִ��
	{
		int n = 'c';
		switch (n++)
		{
		default:
			printf("error");
			break; //��������ǲ���ִ�е��ˡ���
		case 'a':
		case 'A':
		case 'b':
			printf("ab");
			break;
		case 'c':
		case 'C':
			printf("c");
		case 'd':
		case 'D':
			printf("D");
		}
		printf("\n");
	}

	{
		if (4 > 3 > 2) //���������ã����������ң�4>3 = true trueת��1 > 2 ->false ���Բ��ܽ�if
		{
			cout << "aa" << endl;
		}
	}

	//break��for������ִ��i++
	{
		//int i;
		//for (i=0;i!=8;++i)
		//{
		//	if(i==1) break;
		//}
	}

	{ //ȡ�������ŷ���λһ��ȡ����
		int i = 1;
		int j = ~i; //����λҲ���ˣ�����˸���
	}

	//��λ�����:
	{
		//1.�������������λ��1
		//2.���������������λ����ַ���(��������ΰ����˺ܶ࣬����long,short��Щ���ǣ���ʵ���ǳ���double����ǰ��λ�Ǳ�ʾָ���������ʾʵ�ʵ����ֱ�ʾ�������ǿ�����λ�������)
		//3.��λȡ��ֻ��Ҫһ��������������λ�����������������
		char a = 'a';
		a << 1;
		unsigned short b = 1;
		b << 1;
	}

	{ //�߼���ֵ��ֻҪ�Ƿ�0ֵ�Ϳ��ԣ�double,float���У�����Ҫ������
		double d = 1.1;
		if (d)
			cout << "not zero" << endl;
	}

	//�޷��������з�����
	{
		cout << endl;
		unsigned int i = -2147483647 - 1;
		float a = 0.0;
		//a-1
		unsigned int c = 1u - 2u; //�����޷�������������С��0�����������������ͳ��˻������������޷�������
		bool b = 1u - 2u < 0;	 //false

		printf("%u\n", i);
	}

	//��������Ƕ�׶���
	{
		//void printInfo() { cout << " " << endl; } //����
	}

	//i++������δ������Ϊ:
	//û��ָ��ִ��˳����������˵��������ʽָ���޸���ͬһ�����󣬽��������󲢲���δ�������Ϊ��
	{
		int i = 0;
		i = i++;				  //������һ��δ����Ϊ ��ȡ���ڱ�������ִ��i++�����˵�ǰֵ֮����Լӻ���=��
		cout << i << ++i << endl; //Ҳ��δ������Ϊ����֪������++i������i
	}

	{//ָ�����ֱ����������ֵ
		int *i = (int *)1; //���ǲ�����������ֵ�����Ͳ�ͬ��ǿ��ת����(int *)�ǿ��Ե�
		*i = 10; //�������ܶ����ֽ��и�ֵ
	// int *i = 0; //����Ϊ0������NULL
	}

#pragma endregion

	{
		//�ַ������Է��ڳ����ַ�����֮������飿
		//�𰸿���

		class Widget
		{
		  public:
			Widget(const char *str) : _str(str) {}
			string _str;
		};

		Widget w[2] = {"a", "b"};
	}

	//f(5);

	{ //��C�����б������������ظ����������ǲ����ظ�����
		//�������ڲ������������ֻ���ڲ���������Ч
		void f(int n);
		f(5);
	}
	//f(5); //Ҳ���ܷ��ʵ��ڲ��������f

	//C++��������������͵���ʱ���������޸�
	{
		int *func();
		//int *p = --func(); // ����C++��������������͵���ʱ���������޸�
	}
	::system("pause");
	return 0;
}

void f(int n)
{
	printf("%d\n", n);
}
