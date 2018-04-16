// 08_编译器生成的默认构造函数.cpp : 定义控制台应用程序的入口点。
//

class Widget
{
  public:
	Widget(const Widget &other) {}
};

class Widget1
{
  public:
	Widget1() = default;
};

int
main()
{
	// Widget w; //报错,可以看到，就算只是定义了拷贝构造函数，默认构造函数也就不会合成了

	Widget1 w1;
	Widget1 w2 = w1; //但是  定义了默认构造函数的情况下，拷贝构造函数还是会自动生成。

	return 0;
}
