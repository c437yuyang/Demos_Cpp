#include <algorithm>
#include <iostream>
#include <vector>
#include <random>

int main()
{
	std::vector<char> v1{ 'a', 'b', 'c', 'd' };
	std::vector<char> v2{ 'a', 'b', 'c', 'd' };

	std::mt19937 g{ std::random_device{}() };
	while (!std::lexicographical_compare(v1.begin(), v1.end(),
		v2.begin(), v2.end()))
	{ //lexicographical_compare,当第一个区间<第二个区间，才会返回true,当然可以自己重新写predict
		for (auto c : v1) std::cout << c << ' ';
		std::cout << ">= ";
		for (auto c : v2) std::cout << c << ' ';
		std::cout << '\n';

		std::shuffle(v1.begin(), v1.end(), g);
		std::shuffle(v2.begin(), v2.end(), g);
	}

	for (auto c : v1) std::cout << c << ' ';
	std::cout << "< ";
	for (auto c : v2) std::cout << c << ' ';
	std::cout << '\n';
	return 0;
}