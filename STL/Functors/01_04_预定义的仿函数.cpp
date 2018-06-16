// 01_04_预定义的仿函数.cpp : 定义控制台应用程序的入口点。
//

#include <functional>

#include <iostream>
#include <string>

class Widget
{
  public:
	Widget(int a, std::string b) : age(a), name(b) {}
	int age;
	std::string name;
	bool operator==(const Widget &other) const //成员版本一定要加上const,否则equal_to里面调用不了
	{
		return this->age == other.age && this->name == other.name;
	}
};

//bool operator==(const Widget&left, const Widget&right)
//{
//	return left.age == right.age && left.name == right.name;
//}

int main()
{
	//std::greater<int> my_gt; //大于
	//std::greater_equal<int> my_gt; //>=
	//std::logical_and<int> my_gt; // &&
	//std::negate<int> my_gt; //-
	//std::minus<int> my_gt; //a-b
	//std::multiplies<int> my_gt; //a*b
	

	std::hash<int> int_hash;
	std::hash<std::string> string_hash;
	std::cout << int_hash(10) << std::endl; //返回的是size_t类型
	std::cout << int_hash(11) << std::endl;
	std::cout << string_hash(std::string("11")) << std::endl;
	std::cout << string_hash(std::string("12")) << std::endl; //所有的用到了哈希值的容器默认都是使用hash<T>作为其hash函数

	std::equal_to<int> int_equal;
	std::cout << int_equal(1, 2) << std::endl; //0
	std::cout << int_equal(1, 1) << std::endl; //1
	std::equal_to<Widget> w_equal;
	Widget w1(1, "a");
	Widget w2(1, "a");
	Widget w3(2, "a");
	std::cout << w_equal(w1, w2) << std::endl; //
	std::cout << w_equal(w2, w3) << std::endl; //
	std::cout << (w1 == w2) << std::endl;	  //

	system("pause");
	return 0;
}
