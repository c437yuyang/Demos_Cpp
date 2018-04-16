// 15_静态成员.cpp : 定义控制台应用程序的入口点。
//

#include <iostream>
using namespace std;

class TestStatic {
	//static const int memCount = 0; //如果要在类内进行初始化的话，必须设为常量值,且是整形(ints,chars,bools)的变量才行
	//其实这里还是声明式，并不是定义式，如果要取它的地址的话，就还必须提供定义式(可以不给值了，声明的时候给了)，详情请看effective C++ M2
	//const static double salary = 0.0; //错误，不是整形
	const static char a = 'a'; //const char 类型也可以类内初始化

	static int memCount; //静态成员同样遵循访问修饰控制符的权限控制

public:
	
	TestStatic() { memCount++; }
	~TestStatic() { memCount--; }

	//int GetMemCount() { return memCount; } //非静态的成员可以访问常量成员（必须先有实例）
	static int GetMemCount() { return memCount; } //静态成员不能访问非静态成员（因为静态成员先于非静态成员初始化）

};

int TestStatic::memCount = 0; //静态成员必须(必须)在外部声明(全局范围)

int main()
{
	//int TestStatic::memCount = 0; //静态成员必须在外部声明(函数内部不行)

	TestStatic ts1;
	TestStatic ts2;
	TestStatic *pTs = new TestStatic;

	//cout << ts1.GetMemCount() << endl; //有实例了依然可以访问静态成员，（非静态的成员可以访问静态成员（必须先有实例））
	cout << TestStatic::GetMemCount() << endl;
	delete pTs;
	cout << TestStatic::GetMemCount() << endl;
	system("pause");
	return 0;
}

