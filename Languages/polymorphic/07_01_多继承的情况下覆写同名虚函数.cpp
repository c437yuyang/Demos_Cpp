#include <iostream>

class Widget1
{
  public:
    virtual void printInfo() { std::cout << "Widget1::printInfo" << std::endl; }
    void func(int i){};
};

class Widget2
{
  public:
    virtual void printInfo() { std::cout << "Widget2::printInfo" << std::endl; }
    void func(int i){};
};

class Widget12 : public Widget1, public Widget2
{
  public:
    virtual void printInfo() override //不用指明覆写哪一个基类的虚函数
    {
        std::cout << "Widget12::printInfo" << std::endl;
    }
    void func1(int i)
    {
        // func(i); //这种情况下，必须指明调用哪个父类的
        Widget1::func(i);
    }
};

int main()
{

    Widget12 w12;
    Widget1 *w1 = &w12;
    Widget2 *w2 = &w12;

    w1->printInfo(); //Widget12::printInfo ,正常调用应该调用的
    w2->printInfo(); //Widget12::printInfo ,正常调用应该调用的

    return 0;
}