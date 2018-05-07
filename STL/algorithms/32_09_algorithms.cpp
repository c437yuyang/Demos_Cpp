#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>  //accumulate
#include <iterator> //back_inserter
#include <deque>
using namespace std;
bool isBigger(int a, int b) { return a > b; }
int main()
{

#pragma region find
	vector<int> v = {1, 2, 3, 4, 556, 1, 1, 2, 1};

	//利用find找到所有指定元素Index
	auto it = v.cbegin();
	for (; it != v.cend();)
	{
		it = find(it, v.cend(), 1); //find返回第一个=1的迭代器
		cout << (it - v.cbegin()) << endl;
		it++;
	}
#pragma endregion
	//find_if
	it = v.cbegin();
	for (; it != v.cend();)
	{
		it = find_if(it, v.cend(), [](int i) { return i >= 2 && i <= 3; }); //find_if返回第一个满足条件的迭代器
		cout << (it - v.cbegin()) << endl;
		if (it == v.cend())
			break;
		it++;
	}

	//count
	cout << count(v.begin(), v.end(), 1) << endl; //4

	//accumulate
	cout << accumulate(v.begin(), v.end(), 0) << endl; //初始值0，对象必须可加
	vector<string> v1 = {"a", "b", "c"};
	cout << accumulate(v1.begin(), v1.end(), string("")) << endl; //初值一定要是对象不然字面值不能加

	//equal(用指定的pred检测两个容器的指定区间是否相等)
	vector<int> v2 = {1, 2, 3, 4, 556, 1, 1, 2, 1, 1, 1, 1};
	cout << equal(v.cbegin(), v.cend(), v2.cbegin(), [](int i1, int i2) { return i1 == i2; }) << endl; //输出1，在前一段是相等的

	//fill和fill_n
	fill(v2.begin(), v2.end(), 0); //断点查看
	fill_n(v2.begin(), 2, 1);	  //从begin()后面两个值设为1

	//generate,相当于是fill里的固定值换成了自己可控制的函数来生成
	{
		vector<int> ivec1(10);
		int i = 0;
		generate(ivec1.begin(), ivec1.end(), [&i]() { return ++i; });
		for_each(ivec1.begin(), ivec1.end(), [](int a) { cout << a << "|"; });
		generate_n(ivec1.begin(), 2, [&i]() { return (++i) * (++i); });
		cout << endl;
		for_each(ivec1.begin(), ivec1.end(), [](int a) { cout << a << "|"; });
	}

	//back_inserter
	vector<int> v3; //空容器
		//fill_n(v3.begin(), 10, 0); //直接fill会报错
	fill_n(back_inserter(v3), 10, 0); //

	//copy 和 copy_if
	vector<int> v4, v4_1;
	copy(v3.cbegin(), v3.cend(), back_inserter(v4)); //返回拷贝过去的最后一个元素的后面
	v3[1] = 5;
	v3[2] = 6;
	v3[7] = 10;
	copy_if(v3.begin(), v3.end(), back_inserter(v4_1), [](int i) { return i >= 5; });

	//transform 将一段数据移动到另一个容器去，期间可以进行变换，这是和copy不同的地方
	//比如实现字符串的大小写转换(标准库的string没有提供转换)
	string s1 = "AbC";
	string s2;
	transform(s1.begin(), s1.end(), back_inserter(s2), ::tolower); //注意string和vector一样，没分配就不能使用，也得使用inserter才行

	//replace
	vector<int> v5 = {1, 2, 3, 4, 556, 1, 1, 2, 1, 1, 1, 1};
	replace(v5.begin(), v5.end(), 1, 11); //替换所有1为11
	//replace_if(),replace_copy(),多一个out_iter参数

	//sort,unique
	vector<int> v6 = {3, 4, 1, 2, 5, 1, 3, 2, 5, 3};
	//sort(v6.begin(), v6.end());
	sort(v6.begin(), v6.end(), [](int a1, int a2) { return a1 > a2; }); //可以传递一个谓词，来调整比较方式，这里调整为降序
	auto firstRepeat = unique(v6.begin(), v6.end());					//unique把vector里面的重复的元素移到后面(先进行sort才行)，前面只保留不重复的元素
	cout << firstRepeat - v6.begin() << endl;							//返回的是第一个重复元素的iterator
	v6.erase(firstRepeat, v6.end());									//需要再跟erase进行删除
																		//unique的用法和remove,remove_if一样，都是只移动元素，并没有真正删除

	//sort使用谓词
	vector<int> v7 = {3, 4, 1, 2, 5, 1, 3, 2, 5, 3};
	sort(v7.begin(), v7.end(), isBigger);

	//reverse和reverse_copy,copy就是复制到指定位置（自身不会改变）
	{
		vector<int> v8 = {1, 2, 3, 4, 5};
		reverse(v8.begin(), v8.end());
		for_each(v8.begin(), v8.end(), [](int a) { cout << a << " "; });
		cout << endl;
		vector<int> v9(5); //目标位置必须足够大
		reverse_copy(v8.begin(), v8.end(), v9.begin());
		for_each(v8.begin(), v8.end(), [](int a) { cout << a << " "; });
		cout << endl;
		for_each(v9.begin(), v9.end(), [](int a) { cout << a << " "; });
		cout << endl;
	}

	//rotate和xx_if,rotate，把元素或者序列看做一个环，旋转这些元素到原来middle元素到达first位置
	{
		vector<int> v8 = {1, 2, 3, 4, 5};
		//reverse(v8.begin(), v8.end());
		rotate(v8.begin(), v8.begin() + 2, v8.end());
		for_each(v8.begin(), v8.end(), [](int a) { cout << a << " "; });
		cout << endl;
		//rotate_copy 类似
	}

	//lambda表达式
	vector<int> v8 = {3, 4, 1, 2, 5, 1, 3, 2, 5, 3};
	sort(v8.begin(), v8.end(), [](int a, int b) { return a > b; });

	vector<string> v9 = {"abc", "defg", "hdsaddas"};
	int sz = 3;
	auto it9 = find_if(v9.begin(), v9.end(), [sz](const string &a) { return a.size() > sz; }); //可以捕获同作用域的变量
	cout << it9 - v9.begin() << endl;

	//for_each结合lambda表达式实现各种功能（也可以实现修改,传递引用）
	vector<int> v10 = {3, 4, 1, 2, 5, 1, 3, 2, 5, 3};
	for_each(v10.begin(), v10.end(), [](int a) { if (a > 3) cout << a << "|"; });
	for_each(v10.begin(), v10.end(), [](int &a) { a++; });
	for_each(v10.begin(), v10.end(), [](int a) { cout << a << "|"; });
	cout << endl;

	//random_shuffle
	random_shuffle(v10.begin(), v10.end());
	for_each(v10.begin(), v10.end(), [](int a) { cout << a << "|"; });
	cout << endl;

	//排列,next_permutation,prev_permutation,next_permutation,是直接把原数组排列 ，所以原始数据必须有序才行
	{
		vector<int> v = {1, 2, 3};
		while (next_permutation(v.begin(), v.end()))
		{
			for_each(v.begin(), v.end(), [](int a) { cout << a << "|"; });
			cout << endl;
		}
		cout << endl;
		v = {3, 1, 2};
		while (next_permutation(v.begin(), v.end())) //这个时候输出就只有321了
		{
			for_each(v.begin(), v.end(), [](int a) { cout << a << "|"; });
			cout << endl;
		}

		v = {3, 2, 1};
		while (prev_permutation(v.begin(), v.end())) //可以看到prev_premutation是包含当前的，所以也是左开右闭的设计思路
		{
			for_each(v.begin(), v.end(), [](int a) { cout << a << "|"; });
			cout << endl;
		}
	}

	//partition找到所有满足条件的元素，移动到vector前端
	//和我们快排里面用到的，主元会最后在中间不一样，这里没有选主元，只是根据指定的谓词来移动而已
	//返回第一个不满足条件的元素,前面和后面的元素顺序都不一定,只看满不满足条件
	{
		vector<int> v = {1, 2, 3, 4, 9, 6, 7, 8, 5};
		for_each(v.begin(), v.end(), [](int a) { cout << a << "|"; });
		cout << endl;
		partition(v.begin(), v.end(), [](int v1) { return v1 > 5; });
		for_each(v.begin(), v.end(), [](int a) { cout << a << "|"; });
		cout << endl;
	}

	//count
	vector<int> v11 = {3, 4, 1, 2, 5, 1, 3, 2, 5, 3};
	auto it_11 = count(v11.begin(), v11.end(), 3); // 3个
	auto it_11_1 = count_if(v11.begin(), v11.end(), [](int i) { return i == 3; });

	//min_element
	auto it_11_2 = min_element(v11.begin(), v11.end()); //返回迭代器
	auto it_11_3 = max_element(v11.begin(), v11.end());

	//合并算法
	//merge用于两个已经有序的序列的合并,所以和mergesort里面用到的其实差不多,无需序列不能用
	{
		vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9};
		vector<int> v1 = {2, 3, 4, 5, 6, 7, 8, 9, 10};
		vector<int> v2(v.size() + v1.size());
		merge(v.begin(), v.end(), v1.begin(), v1.end(), v2.begin()); //把v和v1合并到v2
		for_each(v2.begin(), v2.end(), [](int a) { cout << a << "|"; });
		cout << endl;
	}
	//set_union，求并集(两个已经排序的)
	{
		vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9};
		vector<int> v1 = {2, 3, 4, 5, 6, 7, 8, 9, 10};
		vector<int> v2;
		set_union(v.begin(), v.end(), v1.begin(), v1.end(), back_inserter(v2));
		for_each(v2.begin(), v2.end(), [](int a) { cout << a << "|"; });
		cout << endl;
	}

	//set_intersection，求交集(两个已经排序的)
	{
		vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9};
		vector<int> v1 = {2, 3, 4, 5, 6, 7, 8, 9, 10};
		vector<int> v2;
		set_intersection(v.begin(), v.end(), v1.begin(), v1.end(), back_inserter(v2));
		for_each(v2.begin(), v2.end(), [](int a) { cout << a << "|"; });
		cout << endl;
	}

	//set_difference，求差集(两个已经排序的),结果是包含在1中不包含在2中的
	{
		vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9};
		vector<int> v1 = {2, 3, 4, 5, 6, 7, 8, 9, 10};
		vector<int> v2;
		set_difference(v.begin(), v.end(), v1.begin(), v1.end(), back_inserter(v2));
		for_each(v2.begin(), v2.end(), [](int a) { cout << a << "|"; });
		cout << endl;
	}

	//插入器
	{
		//front_inserter
		deque<int> d = {1, 2, 3};
		for_each(d.begin(), d.end(), [](int a) { cout << a << "|"; });
		cout << endl;
		front_inserter(d) = 22;
		for_each(d.begin(), d.end(), [](int a) { cout << a << "|"; });
		cout << endl;
		deque<int> d1 = {4, 5};
		copy(d1.begin(), d1.end(), front_inserter(d));
		for_each(d.begin(), d.end(), [](int a) { cout << a << "|"; });
		cout << endl;

		//inserter
		inserter(d, d.begin()) = 101; //插入到末尾
		for_each(d.begin(), d.end(), [](int a) { cout << a << "|"; });
		cout << endl;

		deque<int> d2 = {102, 103};
		copy(d2.begin(), d2.end(), inserter(d, d.begin()));
		for_each(d.begin(), d.end(), [](int a) { cout << a << "|"; });
		cout << endl;
	}

	//distance,求两个迭代器距离,advance,迭代器前进n步
	//iter_swap()交换两个迭代器
	//

	//数值计算部分:
	//accumulate
	//inner_product,对应元素相乘相加,按照第一个序列的范围来确定
	{
		vector<int> v1 = {1, 2, 4};
		vector<int> v2 = {2, 4, 8};

		cout << inner_product(v1.begin(), v1.end(), v2.begin(), 0) << endl;
		//也可以改写实现的方法，就是内积的做法
		//最终:val = op1(val,op2(elem1,elem2))
	}

	//partial_sum
	{
		vector<int> v1 = {1, 2, 3, 4, 5};
		vector<int> v2; // 1 3 6 10 15这样的
		partial_sum(v1.begin(), v1.end(), back_inserter(v2));
		for_each(v2.begin(), v2.end(), [](int a) { cout << a << "|"; });
		cout << endl;
	}

	//
	{
		vector<int> v1 = {1, 2, 3, 5, 9};
		vector<int> v2; // 1 1 1 2 4这样的
		adjacent_difference(v1.begin(), v1.end(), back_inserter(v2));
		for_each(v2.begin(), v2.end(), [](int a) { cout << a << "|"; });
		cout << endl;
	}

	system("pause");
	return 0;
}
