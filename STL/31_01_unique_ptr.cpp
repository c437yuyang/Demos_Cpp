#include <memory>
#include <iostream>
#include <cassert>
class Widget
{
  public:
    Widget(int _i) : i(_i) { std::cout << "Widget()" << i << std::endl; }
    ~Widget() { std::cout << "~Widget()" << i << std::endl; }
    int i;
};

std::unique_ptr<Widget> makePtr(int i)
{
    std::unique_ptr<Widget> pw (new Widget(i));
    return pw; //可以使用返回，其实是使用的move构造
}

int main()
{
    {
        std::unique_ptr<Widget> pw(new Widget(1));
        std::unique_ptr<Widget> pw2 = makePtr(2);
        // std::unique_ptr<Widget> pw3 = pw2; //error，no copy ctor and assignment
        // std::unique_ptr<Widget> pw3;pw3 = pw2; //error，no copy ctor and assignment
        std::unique_ptr<Widget> pw3 = std::move(pw2); //支持移动构造
        // std::cout << pw2->i << std::endl; //现在再解引用，报错
        assert(!pw2);
        std::cout << pw3->i << std::endl; //现在再解引用，报错
    }
    return 0;
}