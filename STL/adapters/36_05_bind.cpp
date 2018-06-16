#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>
#include <cassert>
double my_divide(double x, double y)
{
    return x / y;
}

struct MyPair
{
    double a, b;
    double multiply() { return a * b; }
};

int main()
{
    //binding functions
    auto fn_five = std::bind(my_divide, 10, 2); //return 10/2
    std::cout << fn_five() << std::endl;        // 5

    auto fn_half = std::bind(my_divide, std::placeholders::_1, 2); //return x/2
    std::cout << fn_half(20) << std::endl;                         // 5

    auto fn_invert = std::bind(my_divide, std::placeholders::_2, std::placeholders::_1); //return y/x
    std::cout << fn_invert(10, 2) << std::endl;                                          // 0.2

    auto fn_rounding = std::bind<int>(my_divide, std::placeholders::_1, std::placeholders::_2); //return int(x/y) ,指定返回值类型
    std::cout << fn_rounding(10, 3) << std::endl;                                               // 3

    //binding members:
    MyPair ten_two{10, 2};

    auto bound_memfn = std::bind(&MyPair::multiply, std::placeholders::_1); //绑定对象的成员函数
    std::cout << bound_memfn(ten_two) << std::endl;                         //20,_1必须是某个object的地址,其实就是this指针的绑定

    auto bound_memdata = std::bind(&MyPair::a, ten_two); //return ten_two.a
    std::cout << bound_memdata() << std::endl;           //10

    auto bound_memdata2 = std::bind(&MyPair::b, ten_two); //return ten_two.b
    std::cout << bound_memdata2() << std::endl;           //2

    std::vector<int> v{15, 36, 121, 21321, 2121};
    int n = std::count_if(v.cbegin(),v.cend(),std::bind2nd(std::less<int>(),50));

    auto fn_ = std::bind(std::less<int>(),std::placeholders::_1,50);
    int n1 = std::count_if(v.cbegin(),v.cend(),fn_);

    assert(n1==n);
    return 0;
}