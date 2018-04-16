// 32_set����.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_set>



using namespace std;


// TEMPLATE STRUCT less��ϵͳ�Ķ��忽�������ģ�
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
	iset.insert({ 0, 5,6 ,4,3 });//����ֱ������һ��initializer_list,�ظ��Ĳ���������
	iset.insert(10);//����Initial_list��value��ʽ����

	auto it1 = iset.lower_bound(6); //lower_bound��������ڣ��򷵻ص�һ���ڵ�λ�ã���������ڣ����ؽ��������λ��(��һ������val��λ��)
	it1 = iset.lower_bound(7); //lower_bound������7�ͻ᷵��10��λ�ã���Ϊ����7��ͻ���10��λ��
	it1 = iset.upper_bound(5); //lower_bound�����ص�һ������val��λ�ã���һ��������ֵ֮���λ�ã���������Ƿ���6
	it1 = iset.upper_bound(7); //lower_bound�������ڣ�����10


	for (auto it = iset.begin(); it != iset.end(); ++it)
		cout << *it << endl; //���Զ������˵ģ����Դ�lambda����ʽ�ı�����ʽ

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
	//multiset��Ȼ������ģ�ֻ�ǿ����ظ�����
	for_each(ms1.begin(), ms1.end(), [](int i) { cout << i << " "; });  //1 1 2 2 3


//set<int, NoOrder<int>> iset3 = { 3,2,1,3,4 }; //debug��ֱ�ӱ�invalid comparator
//cout << endl;
////���¶���һ��ʼ�շ���true�ıȽ��������ˣ��Ϳ���ʵ�������set�ˣ�������ͬ��ȴ���ᱻȥ��,����Ҳ��û��������
////�����Լ��ж�!=��ʱ��ŷ���trueҲ���У���֪��Ϊʲô
//for_each(iset3.begin(), iset3.end(), [](int i) {cout << i << " "; });

	cout << endl;
	unordered_set<int> iset4 = { 1,3,2,19,21,5 };//���Կ�����ģ���б�����hashfunction,compareFunction��allocator,Ĭ�ϵ���hash<T>,equal_to<T>,allocator<T>
	for_each(iset4.begin(), iset4.end(), [](int i) { cout << i << " "; }); //unordered_setҲ���ǰ��ղ���˳������ģ��ǰ���hash���������������
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
	auto hash_val = haser.operator()(10); //���ص���size_t����
	hash_val = haser.operator()(11);
	hash_val = haser.operator()(12);
	hash<string> haser1;
	hash_val = haser1.operator()("a"); //���ص���size_t����
	hash_val = haser1.operator()("b");
	hash_val = haser1.operator()("c");

	//hash_set�Ѿ��������ˣ���ǰ���unordered_set
	//hash_set<int> iset5 = { 1,2,3,211,321,231 };
	//cout << endl;
	//for_each(iset5.begin(), iset5.end(), [](int i) {cout << i << " "; });

	//bucket_count()�õ�Ͱ������
	//bucket_size(i)���Է���ÿ��Ͱ��Ԫ������


	system("pause");
	return 0;
}