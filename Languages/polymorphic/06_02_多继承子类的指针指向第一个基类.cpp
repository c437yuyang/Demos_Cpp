// 06_��̳������ָ��ָ���һ������.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include <iostream>
using namespace std;

class Point3d
{
public:
	//virtual ~Point3d() {}
public:
	static Point3d origin;
	float x, y, z;
};

Point3d Point3d::origin;


int main()
{

	//�����Ǵ�ģ��������1
	std::cout << &Point3d::x << std::endl;
	std::cout << &Point3d::y << std::endl;
	std::cout << &Point3d::z << std::endl;


	//�����Ա�����ڵ�ƫ����
	//������������C++����ģ���е�P131ҳ
	printf("%p\n", &Point3d::x); //4
	printf("%p\n", &Point3d::y); //8
	printf("%p\n", &Point3d::z); //C


	//���ʵ�ʵ�ַ
	Point3d pt;
	printf("%p\n", &pt); //xxx0
	printf("%p\n", &pt.x); //xxx4
	//printf("%p\n", &pt.x - &Point3d::x); //�����������ܹ��õ��������ʼ��ַ��ʵ���ϱ���ᱨ��ģ���Ϊ&Point3d::x��������float Point3d *,����ǿ��ת������
	printf("%p\n", &pt.y); //xxx8
	printf("%p\n", &pt.z); //xxx12
	//���Կ���VC���棬�麯��ָ���Ƿ���ͷ���ģ�ע�͵�����������������֤
	//MingW���棬�麯��ָ���Ƿ���β����
	//GCCҲ����β����

	//���Զ��ؼ̳������������ȡ���ڱ�����
	return 0;
}

