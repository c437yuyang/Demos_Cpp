// 32_01_map容器.cpp : 定义控制台应用程序的入口点。
//
#include <map>
#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main()
{

	map<string, int> m1 = {//初值列表形式
						   map<string, int>::value_type("aa", 2),
						   map<string, int>::value_type("aaa", 3)};

	cout << m1["aa"] << endl;
	cout << m1.at("aa") << endl;

	pair<map<string, int>::iterator, bool> result =
		m1.insert(map<string, int>::value_type("aaaa", 4)); //map的insert返回的是一个pair类型
	//返回的是插入的位置，和插入是否成功

	cout << result.second << endl;		  //1，即true
	cout << result.first->first << endl;  //键值
	cout << result.first->second << endl; //value

	cout << m1["aaaaa"] << endl; //只要使用到了下标就会自行插入
	result = m1.insert({"aaaa",6});
	cout << m1["aaaa"] << endl; //insert是不会更新的!!!!，因此result.second是false
	cout << ((result.first)->first) << " " << (result.second) << endl; //insert是不会更新的!!!!

	auto it = m1.find("aaaa");
	cout << (it == m1.end() ? "没找到" : "找到了") << endl;

	it = m1.find("aaaaa");
	cout << (it == m1.end() ? "没找到" : "找到了") << endl;

	it = m1.find("aaaaa1");
	cout << (it == m1.end() ? "没找到" : "找到了") << endl;

	//unordered版本使用
	unordered_map<string, int> table = {
		unordered_map<string, int>::value_type("aa", 1),
		unordered_map<string, int>::value_type("bb", 2),
		unordered_map<string, int>::value_type("cc", 3),
		unordered_map<string, int>::value_type("dd", 4),
		std::make_pair("ee", 5),
		{"ff", 6} //C++11
		};
	//value_type就是pair类型，因此用make_pair也可以
	table.insert(make_pair("aaa", 111));
	table.insert({"aaa", 111}); //也可以这样，太牛逼了C++11
	std::cout << table["aaa"] << std::endl;
	table.insert({"aaa",222}); //insert是不会更新的
	std::cout << table["aaa"] << std::endl; //111

	for_each(table.begin(), table.end(), [](const unordered_map<string, int>::value_type &val) { cout << val.first << "-" << val.second << endl; });

	for (auto it = table.begin(); it != table.end();)
	{
		if (it->second == 2)
		{
			it = table.erase(it); //erase后返回下一个位置的迭代器
		}
		else
		{
			++it;
		}
	}

	for_each(table.begin(), table.end(), [](const unordered_map<string, int>::value_type &val) { cout << val.first << "-" << val.second << endl; });

	return 0;
}
