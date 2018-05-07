// 32_set容器.cpp : 定义控制台应用程序的入口点。
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_set>



using namespace std;


// TEMPLATE STRUCT less（系统的定义拷贝出来的）
template<class _Ty = void>
struct less1
{	// functor for operator<
	typedef _Ty first_argument_type;
	typedef _Ty second_argument_type;
	typedef bool result_type;

	constexpr bool operator()(const _Ty& _Left, const _Ty& _Right) const
	{	// apply operator< to operands
		return (_Left < _Right);
	}
};

template<class _Ty = void>
struct more
{	// functor for operator<
	//typedef _Ty first_argument_type;
	//typedef _Ty second_argument_type;
	//typedef bool result_type;

	constexpr bool operator()(const _Ty& _Left, const _Ty& _Right) const
	{	// apply operator< to operands
		return (_Left > _Right);
	}
};

template<class _Ty = void>
struct NoOrder
{
	constexpr bool operator()(const _Ty& _Left, const _Ty& _Right) const
	{	// apply operator< to operands
		return (true);
	}
};

int main()
{

	set<int> iset = { 1,2,3,4 };
	iset.insert({ 0, 5,6 ,4,3 });//可以直接添加一个initializer_list,重复的不会再添加
	iset.insert(10);//可以Initial_list和value方式添加

	auto it1 = iset.lower_bound(6); //lower_bound，如果存在，则返回第一个在的位置，如果不存在，返回将被插入的位置(第一个大于val的位置)
	it1 = iset.lower_bound(7); //lower_bound，这里7就会返回10的位置，因为插入7后就会在10的位置
	it1 = iset.upper_bound(5); //lower_bound，返回第一个大于val的位置（第一个在期望值之后的位置），这里就是返回6
	it1 = iset.upper_bound(7); //lower_bound，不存在，返回100


	for (auto it = iset.begin(); it != iset.end(); ++it)
		cout << *it << endl; //是自动排序了的，可以传lambda表达式改变排序方式

							 //cout << (iset.find(1) - iset.begin()) << endl;

	bool b = iset.find(1) == iset.end();
	bool b1 = iset.find(11) == iset.end();
	//iset[1];


	set<int, less1<int>> iset1 = { 3,2,1,3,4 };
	for_each(iset1.begin(), iset1.end(), [](int i) { cout << i << " "; });

	set<int, more<int>> iset2 = { 3,2,1,3,4 };
	for_each(iset2.begin(), iset2.end(), [](int i) { cout << i << " "; });
	cout << endl;

	multiset<int> ms1 = { 1,2,3 };
	ms1.insert(1);
	ms1.insert(2);
	//multiset仍然是排序的，只是可以重复而已
	for_each(ms1.begin(), ms1.end(), [](int i) { cout << i << " "; });  //1 1 2 2 3


//set<int, NoOrder<int>> iset3 = { 3,2,1,3,4 }; //debug会直接报invalid comparator
//cout << endl;
////重新定义一个始终返回true的比较器就行了，就可以实现无序的set了，但是相同的却不会被去除,所以也就没有意义了
////并且自己判断!=的时候才返回true也不行，不知道为什么
//for_each(iset3.begin(), iset3.end(), [](int i) {cout << i << " "; });

	cout << endl;
	unordered_set<int> iset4 = { 1,3,2,19,21,5 };//可以看到，模板列表还有hashfunction,compareFunction和allocator,默认的是hash<T>,equal_to<T>,allocator<T>
	for_each(iset4.begin(), iset4.end(), [](int i) { cout << i << " "; }); //unordered_set也不是按照插入顺序排序的，是按照hash函数来进行排序的
	iset4.insert(21);
	cout << endl;
	for_each(iset4.begin(), iset4.end(), [](int i) { cout << i << " "; });
	iset4.insert(22);
	iset4.insert(100);

	iset4.insert(1021);

	cout << endl;
	for_each(iset4.begin(), iset4.end(), [](int i) { cout << i << " "; });

	//hash<T>
	hash<int> haser;
	auto hash_val = haser.operator()(10); //返回的是size_t类型
	hash_val = haser.operator()(11);
	hash_val = haser.operator()(12);
	hash<string> haser1;
	hash_val = haser1.operator()("a"); //返回的是size_t类型
	hash_val = haser1.operator()("b");
	hash_val = haser1.operator()("c");

	//hash_set已经被抛弃了，用前面的unordered_set
	//hash_set<int> iset5 = { 1,2,3,211,321,231 };
	//cout << endl;
	//for_each(iset5.begin(), iset5.end(), [](int i) {cout << i << " "; });

	//bucket_count()得到桶的数量
	//bucket_size(i)可以访问每个桶的元素数量


	system("pause");
	return 0;
}