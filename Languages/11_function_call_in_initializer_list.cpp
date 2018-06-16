#include <iostream>

class Widget
{
  public:
    Widget()
        : printinfo() //总结:是不能直接调用的，但是如果可以调用函数来初始化某个成员，比如L
          ,
          age(retValue()) //这个是可以的
    {
    }

    void printinfo() { std::cout << "aa" << std::endl; }
    int retValue() { return 1; }

  private:
    int age;
};

int main()
{
    Widget w1;
    return 0;
}