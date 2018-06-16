// 01_04_Ԥ����ķº���.cpp : �������̨Ӧ�ó������ڵ㡣
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
	bool operator==(const Widget &other) const //��Ա�汾һ��Ҫ����const,����equal_to������ò���
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
	//std::greater<int> my_gt; //����
	//std::greater_equal<int> my_gt; //>=
	//std::logical_and<int> my_gt; // &&
	//std::negate<int> my_gt; //-
	//std::minus<int> my_gt; //a-b
	//std::multiplies<int> my_gt; //a*b
	

	std::hash<int> int_hash;
	std::hash<std::string> string_hash;
	std::cout << int_hash(10) << std::endl; //���ص���size_t����
	std::cout << int_hash(11) << std::endl;
	std::cout << string_hash(std::string("11")) << std::endl;
	std::cout << string_hash(std::string("12")) << std::endl; //���е��õ��˹�ϣֵ������Ĭ�϶���ʹ��hash<T>��Ϊ��hash����

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
