#include <iostream>

//程序员面试宝典 11.1 P137例子
class A
{
  protected:
    int m_data;

  public:
    A(int data = 0) { m_data = data; }
    int GetData() { return doGetData(); }
    virtual int doGetData() { return m_data; }
};

class B : public A
{
  protected:
    int m_data;

  public:
    B(int data = 1) { m_data = data; }
    int doGetData() { return m_data; }
};

class C : public B
{
  protected:
    int m_data;

  public:
    // int doGetData() { return m_data; } 
    C(int data = 2) { m_data = data; }
};

int main()
{
    C c(10);
    std::cout << c.GetData() << std::endl;      //1 C没有.GetData()，因此调用B类，B也没有，因此调用A类.GetData(),A中.GetData()调用doGetData()
    //因为doGetData是虚函数，发生多态（注意，这里不是引用也不是指针，也会发生多态），向下寻找，会找到B类的doGetData,因此返回B类的m_data 1
    //如果C类定义了doGetData,则最终会调用C类的doGetData()
    std::cout << c.A::GetData() << std::endl;   //1 和上面类似，最终返回B类的m_data
    std::cout << c.B::GetData() << std::endl;   //1 ...
    std::cout << c.C::GetData() << std::endl;   //1 ...
    std::cout << c.doGetData() << std::endl;    //1
    std::cout << c.A::doGetData() << std::endl; //0 显式调用A的doGetData()，因此返回的是A类的m_data
    std::cout << c.B::doGetData() << std::endl; //1 显式调B的doGetData()，因此返回的是B类的m_data
    std::cout << c.C::doGetData() << std::endl; //1 显式调C的doGetData()，不存在，调用B的(优先父类),因此返回的是B类的m_data

    //总结:
    //这里c不是指针也不是引用，确还是有多态的效果，参见:https://bbs.csdn.net/topics/370153620
    //说白了可以理解成调用的时候是this->func(),因此还是有多态的效果
    //一个函数在哪里(父类或子类)，输出的变量就是哪里的变量。

    B b(11);
    std::cout << b.GetData() << std::endl; //比如这里，输出11

    return 0;
}