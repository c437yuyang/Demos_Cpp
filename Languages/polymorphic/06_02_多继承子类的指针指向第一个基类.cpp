// 06_��̳������ָ��ָ���һ������.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include <iostream>
using namespace std;

class ParentA {

};
class ParentB {

};

class Derived :public ParentA,public ParentB
{

};
int main()
{

	Derived *pD = new Derived();
	ParentA *pA = (ParentA*)pD;
	ParentB *pB = (ParentB*)pD;

	std::cout << pD << std::endl; //ǰ������ȿ��Կ���
	std::cout << pA << std::endl;//�����Ǻ͵�һ������ĵ�ַ��ͬ��VS�����Ǻ͵�һ����ͬ���ڶ�����ͬ��MingW�Ƕ�����ͬ�ģ�
	std::cout << pB << std::endl; 
	std::cout << (pD==pB) << std::endl;
	std::cout << (pD==pA) << std::endl;


	//���Զ��ؼ̳������������ȡ���ڱ�����
    return 0;
}

