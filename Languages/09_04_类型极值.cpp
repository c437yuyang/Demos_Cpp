// 25_0_���ͼ�ֵ.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
using namespace std;

constexpr int size1(int i) //
{
	return i*i;
}

int main()
{
	int arr[size1(3)];
	const int i = 3;
	int arr1[i*i];

	short s1 = 65537; //short����ʾ65535(2����ȫ��1),65536(2����ȫ��0,���)����0,65537����1
	cout << s1 << endl; //1
	s1 = 32767; //������������˷���λ��ȫ��1
	s1 = 32768; //��С����������λ1��ȫ��0��-32768

	short s2 = 65535; //65535������λȫ��Ϊ1������-1
	cout << s2 << endl; //�����ʱ�򣬱�����֪����Ϊ��signed���ͣ����Ե�һλ������λ�����-1

	unsigned short s3 = 65535;
	cout << s3 << endl; //65535

	system("pause");
    return 0;
}
