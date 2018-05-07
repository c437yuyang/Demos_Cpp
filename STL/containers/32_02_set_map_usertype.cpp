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
	Widget(int i) : data(i) {}
	Widget(const Widget &other) : data(other.data) { std::cout << "copy ctor" << std::endl; }
};

//auto i = std::hash<int>()(10);

//按照内存地址进行hash
class Widget_MemAddr_Hash
{
public:
	size_t operator()(const Widget &w) const
	{
		return std::hash<int>()((int)&w);
	}
};

class Widget_MemAddr_Equal : public std::binary_function<Widget, Widget, bool>
{
public:
	bool operator()(const Widget &left, const Widget &right) const
	{
		return &left == &right;
	}
};

//按照指针地址进行hash
class Widget_Ptr_Hash
{
public:
	size_t operator()(const Widget *w) const
	{
		return std::hash<int>()((int)w);
	}
};

class Widget_Ptr_Equal : public std::binary_function<Widget, Widget, bool>
{
public:
	bool operator()(const Widget *left, const Widget *right) const
	{
		return left == right;
	}
};

//按照内容进行hash
class Widget_Datum_Hash
{
public:
	size_t operator()(const Widget &w) const
	{
		return std::hash<int>()(w.data);
	}
};

class Widget_Datum_Equal : public std::binary_function<Widget, Widget, bool>
{
public:
	bool operator()(const Widget &left, const Widget &right) const
	{
		return left.data == right.data;
	}
};

//复杂类型hash示例:参考https://blog.csdn.net/zhangpiu/article/details/49837387
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
class Widget_Complex_Hash
{
public:
	size_t operator()(const Widget_Complex &w) const
	{
		return std::hash<int>()(w.data) ^
					 std::hash<int>()(w.data1) ^
					 std::hash<std::string>()(w.str_data_);
	}
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
class WidgetHasher
{
public:
	size_t operator()(const Widget_Complex &cw) const
	{
		return hash_val(cw.data, cw.data1, cw.str_data_); //这里传入每个成员即可
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
	std::cout << w_hash_set.bucket_count() << std::endl;
	std::cout << w_hash_set.size() << std::endl;
	std::cout << w_hash_set.load_factor() << std::endl;
	std::cout << w_hash_set.max_bucket_count() << std::endl;

	assert(w_hash_set.find(w1) == w_hash_set.end()); //找不到的，因为加进去的时候拷贝了

	//std::unordered_set<Widget&, Widget_MemAddr_Hash, Widget_MemAddr_Equal> w_hash_set_ref;
	//报错,不能用引用，因为里面的实现会有指向这个的指针的typedef，不能有指向引用的指针
	//因此C++里面是不能像java一样，按照内存地址来做hash的吧？

	//唯一的办法是用指针???
	//使用指针的例子
	std::unordered_set<Widget *, Widget_Ptr_Hash, Widget_Ptr_Equal> w_hash_set_ptr;
	w_hash_set_ptr.insert(&w1);
	w_hash_set_ptr.insert(&w2);
	w_hash_set_ptr.insert(&w3);
	assert(w_hash_set_ptr.find(&w1) != w_hash_set_ptr.end()); //现在就是找得到的了

	std::unordered_set<Widget, Widget_Datum_Hash, Widget_Datum_Equal> w_hash_set1;
	w_hash_set1.insert(w1);
	w_hash_set1.insert(w2);
	w_hash_set1.insert(w3);
	assert(w_hash_set1.find(w1) != w_hash_set1.end()); //找得到

	std::unordered_set<Widget_Complex, WidgetHasher> cw_hash_set;
	cw_hash_set.insert(Widget_Complex(1, 1, "2"));
	cw_hash_set.insert(Widget_Complex(1, 2, "3"));
	assert(cw_hash_set.find(Widget_Complex(1, 1, "2")) != cw_hash_set.end());

	return 0;
}