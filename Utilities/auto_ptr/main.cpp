#include <iostream>
#include "auto_ptr.h"
#include <utility>
#include <algorithm>
using namespace yxp_utility;
class Widget
{

};

class SpecialWidget :public Widget
{

};

int main()
{

	{
		auto_ptr<int> pi(new int(10));
		auto_ptr<int> pi1 = pi;
		auto_ptr<int> pi2;
		pi2 = pi1;
		std::cout << *pi2 << std::endl;

		auto_ptr<SpecialWidget> psw1(new SpecialWidget);
		auto_ptr<Widget> pw1(psw1);
		auto_ptr<SpecialWidget> psw2(new SpecialWidget);
		auto_ptr<SpecialWidget> psw3;
		psw3 = psw2;
		auto_ptr<Widget> pw2;
		pw2 = psw3;
		pw2 = pw2;
	}

	system("pause");
	return 0;
}