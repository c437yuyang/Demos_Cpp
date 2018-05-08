// 32_01_map����.cpp : �������̨Ӧ�ó������ڵ㡣
//
#include <map>
#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main()
{

	map<string, int> m1 = {//��ֵ�б���ʽ
						   map<string, int>::value_type("aa", 2),
						   map<string, int>::value_type("aaa", 3)};

	cout << m1["aa"] << endl;
	cout << m1.at("aa") << endl;

	pair<map<string, int>::iterator, bool> result =
		m1.insert(map<string, int>::value_type("aaaa", 4)); //map��insert���ص���һ��pair����
	//���ص��ǲ����λ�ã��Ͳ����Ƿ�ɹ�

	cout << result.second << endl;		  //1����true
	cout << result.first->first << endl;  //��ֵ
	cout << result.first->second << endl; //value

	cout << m1["aaaaa"] << endl; //ֻҪʹ�õ����±�ͻ����в���
	result = m1.insert({"aaaa",6});
	cout << m1["aaaa"] << endl; //insert�ǲ�����µ�!!!!�����result.second��false
	cout << ((result.first)->first) << " " << (result.second) << endl; //insert�ǲ�����µ�!!!!

	auto it = m1.find("aaaa");
	cout << (it == m1.end() ? "û�ҵ�" : "�ҵ���") << endl;

	it = m1.find("aaaaa");
	cout << (it == m1.end() ? "û�ҵ�" : "�ҵ���") << endl;

	it = m1.find("aaaaa1");
	cout << (it == m1.end() ? "û�ҵ�" : "�ҵ���") << endl;

	//unordered�汾ʹ��
	unordered_map<string, int> table = {
		unordered_map<string, int>::value_type("aa", 1),
		unordered_map<string, int>::value_type("bb", 2),
		unordered_map<string, int>::value_type("cc", 3),
		unordered_map<string, int>::value_type("dd", 4),
		std::make_pair("ee", 5),
		{"ff", 6} //C++11
		};
	//value_type����pair���ͣ������make_pairҲ����
	table.insert(make_pair("aaa", 111));
	table.insert({"aaa", 111}); //Ҳ����������̫ţ����C++11
	std::cout << table["aaa"] << std::endl;
	table.insert({"aaa",222}); //insert�ǲ�����µ�
	std::cout << table["aaa"] << std::endl; //111

	for_each(table.begin(), table.end(), [](const unordered_map<string, int>::value_type &val) { cout << val.first << "-" << val.second << endl; });

	for (auto it = table.begin(); it != table.end();)
	{
		if (it->second == 2)
		{
			it = table.erase(it); //erase�󷵻���һ��λ�õĵ�����
		}
		else
		{
			++it;
		}
	}

	for_each(table.begin(), table.end(), [](const unordered_map<string, int>::value_type &val) { cout << val.first << "-" << val.second << endl; });

	return 0;
}
