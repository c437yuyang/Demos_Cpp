#include <iostream>
#include <vector>
using namespace std;


class  A
{
public:
	virtual void  printInfo() { cout << "Baseed" << endl; }
private:

};

class B:public A
{
public:
	void  printInfo() { cout << "Extented" << endl; }
private:

};



int main()
{
	A a;
	B b;
	A &refA = b;
	A *pA = &b; //���Կ���ָ������ö��������̬Ч��
	//vector
	refA.printInfo();
	pA->printInfo();
	(*pA).printInfo(); //��������Ҳ�ǿ��Զ�̬��

	system("pause");
    return 0;
}
