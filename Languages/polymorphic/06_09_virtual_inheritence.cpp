/*
https://blog.csdn.net/qq_34992845/article/details/58300556
*/
#include <iostream>
using namespace std;
class A
{
  public:
    A() : a(1) { cout << "A()" << endl; };
    void printA() { cout << a << endl; }
    int a;
};

class B : virtual public A
// class B : public A
{
  public:
    B() { cout << "B()" << endl; }
};

class C : virtual public A
// class C : public A
{
  public:
    C() { cout << "C()" << endl; }
};

class D : public B, public C
{
  public:
    D() { cout << "D()" << endl; }
};

int main(int argc, char *argv[])
{
    D d;
    cout << sizeof(d) << endl;
    // d.a=10; //如果不是虚拟继承的话，这里会出现二义性访问，编译报错
    // d.printA();

    return 0;
}
