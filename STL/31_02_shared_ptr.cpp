#include <memory>
#include <iostream>
#include <vector>
class Widget
{
  public:
    Widget(int data) : data_(data) {}
    ~Widget() { std::cout << "~Widget()" << std::endl; }
    int data_;
};

struct B
{
    virtual void bar() { std::cout << "B::bar\n"; }
    virtual ~B() = default;
};
struct D : B
{
    D() { std::cout << "D::D\n"; }
    ~D() { std::cout << "D::~D\n"; }
    void bar() override { std::cout << "D::bar\n"; }
};

void deleter(D *ptr)
{
    delete ptr;
    ptr = nullptr;
    std::clog << "delete the pointer." << std::endl;
}

struct deleterStruct
{
  public:
    void operator()(D *ptr) const
    {
        delete ptr;
        ptr = nullptr;
        std::clog << "delete the pointer." << std::endl;
    }
};

int main()
{
    {
        std::shared_ptr<Widget> s1(new Widget(10));
        std::cout << (s1->data_) << std::endl;
        s1 = nullptr; //可以看到，置为null的同时，就析构了
        std::shared_ptr<Widget> s2 = s1;
    }

    //多态验证
    std::cout << "Runtime polymorphism demo\n";
    {
        std::shared_ptr<D> p(new D); // p is shared_ptr that owns a D
                                     // as a pointer to base
        p->bar();                    // virtual dispatch

        std::shared_ptr<B> pB(new D);
        pB->bar(); //可以直接用多态

        std::vector<std::shared_ptr<B>> v; // unique_ptr can be stored in a container
        v.push_back(std::shared_ptr<D>(new D));
        v.push_back(std::move(p));
        v.emplace_back(new D);
        for (auto &p : v)
            p->bar(); // virtual dispatch
    }                 // ~D called 3 times

    //指定deleter
    {
        //传lambda表达式可以
        // std::shared_ptr<D> p(new D, [](D *pD) {std::cout << "deleting D object" << std::endl;delete pD; }); //
        // std::shared_ptr<D> p(new D, deleter);       //传递谓词即可，shared_ptr
        std::shared_ptr<D> p(new D, deleterStruct()); //传递仿函数也可以
    }

    return 0;
}