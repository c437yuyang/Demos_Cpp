#include <iostream>
#include <unordered_set>
#include <cassert>

//针对指针都能使用
template<class T>
struct Hasher {}; //必须有一个模板类才能有底下的特例化

template <class T>
struct Hasher<T *>
{
	size_t operator()(const T *ptr) const
	{
		return std::hash<int>()((int)ptr);
	}
};

class Widget
{
public:
	int data;
	Widget(int i) : data(i) {}
	Widget(const Widget &other) : data(other.data) { std::cout << "copy ctor" << std::endl; }
};


//一个万用的hash_function
template <typename T>
inline void hash_combine(size_t &seed, const T &val)
{
	seed ^= std::hash<T>()(val) +
		0x9e3779b9 + //这个数是来源于黄金分割
		(seed << 6) +
		(seed >> 2);
}

template <typename T>
inline void hash_val(size_t &seed, const T &val)
{
	hash_combine(seed, val);
}
//利用了C++11新特性的Variadic Templates
template <typename T, typename... Types>
inline void hash_val(size_t &seed, const T &val, const Types &... args)
{
	hash_combine(seed, val);
	hash_val(seed, args...);
}

template <typename... Types>
inline size_t hash_val(const Types &... args)
{
	size_t seed = 0;
	hash_val(seed, args...);
	return seed;
}


//使用的时候:
class Widget_Complex
{
public:
	Widget_Complex(int i, int i1, std::string str) : data(i), data1(i1), str_data_(str) {}
	bool operator==(const Widget_Complex &rhs) const
	{
		return rhs.data == data &&
			rhs.data1 == data1 &&
			rhs.str_data_ == str_data_;
	}
	int data;
	int data1;
	std::string str_data_;
};

class WidgetHasher
{
public:
	size_t operator()(const Widget_Complex &cw) const
	{
		return hash_val(cw.data, cw.data1, cw.str_data_); //这里传入每个成员即可
	}
};


//具体可以看YXPUtility里面
int main()
{
	Widget w1(10), w2(11),w3(12);
	std::unordered_set<Widget*, Hasher<Widget*>> set; //不用实现std::equal_to了，指针可以用std::equal_to<T*>
	set.insert(&w1);
	set.insert(&w2);
	assert(set.find(&w1) != set.end());
	assert(set.find(&w2) != set.end());
	assert(set.find(&w3) == set.end());
	return 0;
}