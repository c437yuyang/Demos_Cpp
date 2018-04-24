// 06_多继承子类的指针指向第一个基类.cpp : 定义控制台应用程序的入口点。
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

	std::cout << pD << std::endl; //前两个相等可以看到
	std::cout << pA << std::endl;//所以是和第一个父类的地址相同（VS里面是和第一个相同，第二个不同，MingW是都是相同的）
	std::cout << pB << std::endl; 
	std::cout << (pD==pB) << std::endl;
	std::cout << (pD==pA) << std::endl;


	//所以多重继承这个东西，很取决于编译器
    return 0;
}

