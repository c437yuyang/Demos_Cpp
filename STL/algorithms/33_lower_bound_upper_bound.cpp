// alg_nth_elem.cpp
// compile with: /EHsc
#include <vector>
#include <algorithm>
#include <functional>      // For greater<int>( )
#include <iostream>

// Return whether first element is greater than the second
bool UDgreater(int elem1, int elem2)
{
	return elem1 > elem2;
}
//STL中的nth_element()方法的使用 
//通过调用nth_element(start, start+n, end) 方法可以"使第n大元素处于第n位置"（从0开始,其位置是下标为 n的元素）
//并且比这个元素小的元素都排在这个元素之前，比这个元素大的元素都排在这个元素之后，但不能保证他们是有序的
//VS里面的实现是直接数组全体排序了的，和标准STL定义的不一样
int main()
{
	using namespace std;
	vector <int> v1;
	vector <int>::iterator Iter1;

	int i;
	for (i = 0; i <= 5; i++)
		v1.push_back(3 * i);

	int ii;
	for (ii = 0; ii <= 5; ii++)
		v1.push_back(3 * ii + 1);

	int iii;
	for (iii = 0; iii <= 5; iii++)
		v1.push_back(3 * iii + 2);

	cout << "Original vector:\n v1 = ( ";
	for (Iter1 = v1.begin(); Iter1 != v1.end(); Iter1++)
		cout << *Iter1 << " ";
	cout << ")" << endl;

	nth_element(v1.begin(), v1.begin() + 3, v1.end());
	cout << "Position 3 partitioned vector:\n v1 = ( ";
	for (Iter1 = v1.begin(); Iter1 != v1.end(); Iter1++)
		cout << *Iter1 << " ";
	cout << ")" << endl;

	// To sort in descending order, specify binary predicate
	nth_element(v1.begin(), v1.begin() + 4, v1.end(),
		greater<int>());
	cout << "Position 4 partitioned (greater) vector:\n v1 = ( ";
	for (Iter1 = v1.begin(); Iter1 != v1.end(); Iter1++)
		cout << *Iter1 << " ";
	cout << ")" << endl;

	random_shuffle(v1.begin(), v1.end());
	cout << "Shuffled vector:\n v1 = ( ";
	for (Iter1 = v1.begin(); Iter1 != v1.end(); Iter1++)
		cout << *Iter1 << " ";
	cout << ")" << endl;

	// A user-defined (UD) binary predicate can also be used
	nth_element(v1.begin(), v1.begin() + 5, v1.end(), UDgreater);
	cout << "Position 5 partitioned (UDgreater) vector:\n v1 = ( ";
	for (Iter1 = v1.begin(); Iter1 != v1.end(); Iter1++)
		cout << *Iter1 << " ";
	cout << ")" << endl;
}