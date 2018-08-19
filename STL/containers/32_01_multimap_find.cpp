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
	multimap<string, int> m_map;//unordered�汾���µ�ʹ��Ҳ����ȫһ�µģ�Ҳ֧��lower_bound�Ⱥ���

	string s("�й�");
	string s1("����");

	m_map.insert(make_pair(s, 50));
	m_map.insert(make_pair(s, 55));
	m_map.insert(make_pair(s, 60));
	m_map.insert(make_pair(s1, 30));
	m_map.insert(make_pair(s1, 20));
	m_map.insert(make_pair(s1, 10));

	multimap<string, int>::iterator m; //���ص���Ȼ��һ������������ͬ��ֵ����һ������Լ�ȥ��������
	multimap<string, int>::iterator beg, end;

	//��ʽ1
	m = m_map.find(s);

	for (int k = 0; k != m_map.count(s); k++, m++) //����count
		cout << m->first << "--" << m->second << endl;


	//��ʽ2
	beg = m_map.lower_bound(s1);
	end = m_map.upper_bound(s1);

	for (m = beg; m != end; m++)
		cout << m->first << "--" << m->second << endl;


	//��ʽ3
	beg = m_map.equal_range(s).first;
	end = m_map.equal_range(s).second;

	for (m = beg; m != end; m++)
		cout << m->first << "--" << m->second << endl;

	return 0;

}

