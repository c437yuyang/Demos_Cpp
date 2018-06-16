/*
emplace操作是C++11新特性，新引入的的三个成员emlace_front、empace 和 emplace_back
这些操作构造而不是拷贝元素到容器中，这些操作分别对应push_front、insert 和push_back，
允许我们将元素放在容器头部、一个指定的位置和容器尾部。

两者的区别 
当调用insert时，我们将元素类型的对象传递给insert，元素的对象被拷贝到容器中，
而当我们使用emplace时，我们将参数传递元素类型的构造函，emplace使用这些参数在容器管理的内存空间中直接构造元素。
*/

#include <vector>
#include <iostream>

class Widget
{
  public:
    Widget(int _id,char s):id(_id),sex(s) { std::cout << "Widget()" << std::endl; }
    Widget(const Widget &rhs):id(rhs.id),sex(rhs.sex) { std::cout << "Widget(const Widget&)" << std::endl; }
    Widget(Widget &&rhs):id(rhs.id),sex(rhs.sex) { std::cout << "Widget(Widget&&)" << std::endl; }
  private:
    int id;
    char sex;
};
void printLineSerpator(){
    std::cout << "============" << std::endl;
}
int main()
{
    std::vector<Widget> v;
    // v.push_back(10,'f'); // error
    v.emplace_back(10,'f'); //emplace back可以直接调用参数构造，从输出可以看到没有发生拷贝构造
    printLineSerpator();
    v.emplace_back(Widget(10,'f')); //emplace back也可以传递对象
    printLineSerpator();
    v.push_back(Widget(11,'m'));
    printLineSerpator();
    v.push_back(std::move(Widget(11,'m')));
    printLineSerpator();
    return 0;
}