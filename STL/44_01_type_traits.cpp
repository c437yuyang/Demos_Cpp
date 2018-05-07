#include <typeinfo>
#include <iostream>
#include <complex>

template <typename T>
void type_traits_output(const T &x)
{
    std::cout << "type traits for type : " << typeid(T).name() << std::endl;
    std::cout << std::is_signed<T>::value << std::endl;
    std::cout << std::is_integral<T>::value << std::endl;
    std::cout << std::is_function<T>::value << std::endl;
    std::cout << std::is_pointer<T>::value << std::endl;
    std::cout << std::is_reference<T>::value << std::endl;
    std::cout << std::is_polymorphic<T>::value << std::endl;
    std::cout << std::is_trivial<T>::value << std::endl;
    std::cout << std::is_trivially_constructible<T>::value << std::endl;
    //还有很多很多,具体可以看https://en.cppreference.com/w/cpp/header/type_traits
}

int main()
{
    type_traits_output(int(1));
    type_traits_output(std::cout);
    type_traits_output(std::complex<double>());
    return 0;
}