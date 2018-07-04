#include <memory>
#include <iostream>
class Widget
{
  public:
    Widget(int data):data_(data){}
    ~Widget() { std::cout << "~Widget()" << std::endl; }
    int data_;
};

int main()
{
    {
        std::shared_ptr<Widget> s1(new Widget(10));
        std::cout << (s1->data_) << std::endl;
        s1 = nullptr; //可以看到，置为null的同时，就析构了
        std::shared_ptr<Widget> s2 = s1;
    }
    return 0;
}