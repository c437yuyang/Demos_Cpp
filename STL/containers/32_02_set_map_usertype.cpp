#include <unordered_set>
#include <iostream>
#include <functional>
#include <assert.h>
#include <string>

//首先:C++里面哈希表也是拷贝的内容进去
//其次,默认是调用std::hash和std::equal_to，
//std::hash上面按F12可以看到只有有限类型是实现了求hash值的，因此自定义类型要自己来求
//总的来说就是结合std::hash进行异或组合

class Widget
{
public:
	int data;
	Widget(int i) :data(i) {}
	Widget(const Widget& other) :data(other.data) { std::cout << "copy ctor" << std::endl; }
};

//auto i = std::hash<int>()(10);

//按照内存地址进行hash
class Widget_MemAddr_Hash
{
public:
	size_t operator()(const Widget& w) const
	{
		return std::hash<int>()((int)&w);
	}
};

class Widget_MemAddr_Equal :public std::binary_function<Widget, Widget, bool>
{
public:
	bool operator()(const Widget&left, const Widget&right) const
	{
		return &left == &right;
	}
};


//按照内容进行hash
class Widget_Datum_Hash
{
public:
	size_t operator()(const Widget& w) const
	{
		return std::hash<int>()(w.data);
	}
};

class Widget_Datum_Equal :public std::binary_function<Widget, Widget, bool>
{
public:
	bool operator()(const Widget&left, const Widget&right) const
	{
		return left.data == right.data;
	}
};


//复杂类型hash示例:参考https://blog.csdn.net/zhangpiu/article/details/49837387
class Widget_Complex
{
public:
	int data;
	int data1;
	std::string str_data_;
};
class Widget_Complex_Hash
{
public:
	size_t operator()(const Widget_Complex& w) const
	{
		return std::hash<int>()(w.data) 
			^ std::hash<int>()(w.data1)
			^ std::hash<std::string>()(w.str_data_);
	}
};


int main()
{
	Widget w1(1);
	Widget w2(2);
	Widget w3(3);

	std::unordered_set<Widget, Widget_MemAddr_Hash, Widget_MemAddr_Equal> w_hash_set;
	w_hash_set.insert(w1);
	w_hash_set.insert(w2);
	w_hash_set.insert(w3);

	assert(w_hash_set.find(w1) == w_hash_set.end()); //找不到的，因为加进去的时候拷贝了

	std::unordered_set<Widget, Widget_Datum_Hash, Widget_Datum_Equal> w_hash_set1;
	w_hash_set1.insert(w1);
	w_hash_set1.insert(w2);
	w_hash_set1.insert(w3);
	assert(w_hash_set1.find(w1) != w_hash_set1.end()); //找得到


	return 0;
}