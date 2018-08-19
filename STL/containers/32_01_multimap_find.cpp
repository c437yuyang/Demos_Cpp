#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <limits>
#include <stack>
#include <unordered_set>
#include <unordered_map>
#include <map>
using namespace std;


int main()
{
	multimap<string, int> m_map;//unordered版本地下的使用也是完全一致的，也支持lower_bound等函数

	string s("中国");
	string s1("美国");

	m_map.insert(make_pair(s, 50));
	m_map.insert(make_pair(s, 55));
	m_map.insert(make_pair(s, 60));
	m_map.insert(make_pair(s1, 30));
	m_map.insert(make_pair(s1, 20));
	m_map.insert(make_pair(s1, 10));

	multimap<string, int>::iterator m; //返回的仍然是一个迭代器，相同健值的在一起，因此自己去遍历即可
	multimap<string, int>::iterator beg, end;

	//方式1
	m = m_map.find(s);

	for (int k = 0; k != m_map.count(s); k++, m++) //集合count
		cout << m->first << "--" << m->second << endl;


	//方式2
	beg = m_map.lower_bound(s1);
	end = m_map.upper_bound(s1);

	for (m = beg; m != end; m++)
		cout << m->first << "--" << m->second << endl;


	//方式3
	beg = m_map.equal_range(s).first;
	end = m_map.equal_range(s).second;

	for (m = beg; m != end; m++)
		cout << m->first << "--" << m->second << endl;

	return 0;

}

