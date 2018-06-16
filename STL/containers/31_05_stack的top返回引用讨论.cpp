#include <iostream>
#include <stack>

class Widget
{
public:
	Widget(int age_, int sex_) :age(age_), sex(sex) { std::cout << "Widget(int age_,int sex_)" << std::endl; }
	Widget(const Widget& w) :age(w.age), sex(w.sex) { std::cout << "Widget(const Widget& w)" << std::endl; }
	~Widget() { std::cout << "~Widget()" << std::endl; }
public:
	int age;
	char sex;
};

Widget PopStack(std::stack<Widget>&w)
{
	Widget& rw = w.top();
	return rw;
}

int main()
{
	{
		std::stack<Widget> s;
		Widget w(1, 'f');
		s.push(w);
		Widget w1 = s.top(); //top返回的是引用，但是因为用的Widget w1接收返回值，所以还是会调用拷贝构造生成新对象
		Widget& rw1 = s.top();  //这样就不会生成新对象了
		Widget w3 = PopStack(s); //可以看到返回值还是产生了新对象，这是一定的
	}
	return 0;
}