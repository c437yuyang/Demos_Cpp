#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

/*
* lower_bound(),返回把新值安插进去不违背排序状态的**最下边界**，所以如果有的话就是第一个出现这个值的地方，如果没有的话，就是第一个大于这个值的位置
// 就是第一个大于等于当前数的位置
* upper_bound(),返回把新值安插进去不违背排序状态的**最上边界**，所以如果有的话，就是所有这个值出现后的下一个位置，如果不存在的话，就是最后一个小于这个值的位置+1
// 就是小于等于当前数的最后一个位置+1
*/


template<class ForwardIt, class T, class Compare = std::less<>>
ForwardIt binary_find(ForwardIt first, ForwardIt last, const T& value, Compare comp = {}) {
	// Note: BOTH type T and the type after ForwardIt is dereferenced 
	// must be implicitly convertible to BOTH Type1 and Type2, used in Compare. 
	// This is stricter than lower_bound requirement (see above)

	first = std::lower_bound(first, last, value, comp);
	return first != last && !comp(value, *first) ? first : last;
}

int main() {
	std::vector<int> data = { 1, 1, 2, 3, 3, 3, 3, 4, 4, 4, 5, 5, 6 };
	//std::vector<int> data = { 1, 1, 2, 3, 3, 3, 3};

	auto lower = std::lower_bound(data.begin(), data.end(), 4);
	auto upper = std::upper_bound(data.begin(), data.end(), 4);

	std::copy(lower, upper, std::ostream_iterator<int>(std::cout, " "));

	std::cout << '\n';

	// classic binary search, returning a value only if it is present

	data = { 1, 2, 4, 6, 9, 10 };

	auto it = binary_find(data.cbegin(), data.cend(), 4); //< choosing '5' will return end()

	if (it != data.cend())
		std::cout << *it << " found at index " << std::distance(data.cbegin(), it);

	return 0;
}