// 08_���������ɵ�Ĭ�Ϲ��캯��.cpp : �������̨Ӧ�ó������ڵ㡣
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
	// Widget w; //����,���Կ���������ֻ�Ƕ����˿������캯����Ĭ�Ϲ��캯��Ҳ�Ͳ���ϳ���

	Widget1 w1;
	Widget1 w2 = w1; //����  ������Ĭ�Ϲ��캯��������£��������캯�����ǻ��Զ����ɡ�

	return 0;
}
