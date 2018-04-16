// 01_�º�������.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include <iostream>
#include <vector>
#include <algorithm>
//һ���������д��operator()�Ļ����Ƿº���
//�º����Ļ���������:unary_function �� binary_function
//�º������ŵ���Ҫ���ٶȸ���(����operator())������ָ��ĵ��÷����漰��ָ�������˺�����
//����ν�ʵĵط����������÷º�����������Ǵ��ݷº����ĵط���ν���ǲ��������


template<class T>
struct plus
{
	T operator()(const T&x, const T& y)
	{
		return x + y;
	}
};

//��һ������
struct minus
{
	template<class T>
	T operator()(const T&x, const T&y)
	{
		return x - y;
	}
};

struct PrintFunctor
{
	//���ֶ����ԣ�����Ҫ����boolֵ������
	
	//template<class T>
	//void operator()(const T& val)
	//{
	//	std::cout << val << " ";
	//}

	template<class T>
	bool operator()(const T& val)
	{
		std::cout << val << " ";
		return true;
	}

};

template<class T>
void PrintFunc(const T& val)
{
	std::cout << val << " ";
}


int main()
{
	plus<int> plusObj;
	std::cout << plusObj(1, 2) << std::endl;
	std::cout << plus<int>() (1, 2) << std::endl; //ʹ����ʱ����
	std::cout << minus()(3, 4) << std::endl;


	std::vector<int> v1 = { 1,2,3,4,5 };

	std::vector<int>::value_type i1 = 1;
	std::for_each(v1.begin(), v1.end(), PrintFunctor());
	std::cout << std::endl;
	std::for_each(v1.begin(), v1.end(), PrintFunc<int>); //Ҳ����



	system("pause");
	return 0;
}

