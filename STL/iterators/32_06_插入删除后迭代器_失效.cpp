// 32_06_����ɾ��������.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
//http://www.cnblogs.com/blueoverflow/p/4923523.html#_label2
#include <vector>
#include <list>
#include <unordered_set>
#include <iostream>

//vector:
//vector�ĵ��������ڴ����·���ʱ��ʧЧ������ָ���Ԫ���ڸò�����ǰ������ͬ����
//���ѳ���capacity()-size()��Ԫ�ز���vector��ʱ���ڴ�����·��䣬���еĵ���������ʧЧ��
//����ָ��ǰԪ���Ժ���κ�Ԫ�صĵ���������ʧЧ��
//��ɾ��Ԫ��ʱ��ָ��ɾ��Ԫ���Ժ���κ�Ԫ�صĵ���������ʧЧ��

//list:
//�����κ�Ԫ�ض�����ʹ������ʧЧ��ɾ��Ԫ��ʱ������ָ��ǰ��ɾ��Ԫ�صĵ������⣬����������������ʧЧ��

//deque:
//�����κ�Ԫ�ض���ʹdeque�ĵ�����ʧЧ����deque���м�ɾ��Ԫ�ؽ�ʹ������ʧЧ��
//��deque��ͷ��βɾ��Ԫ��ʱ��ֻ��ָ���Ԫ�صĵ�����ʧЧ��

//��������
//ɾ��Ԫ�أ�����ָ��ɾ��Ԫ����һ���ĵ�����
//����Ԫ�أ����ز����λ�õ�Ԫ�ص�����

//��������
//ɾ���Ͳ��룬�����ص�����


int main()
{
	std::vector<int> v1 = { 1,2,3,4,5,6 };

	std::list<int> l1 = { 1,2,3,4,5 };

	auto it = l1.erase(++(l1.begin())); //ɾ�����ر�ɾ��֮���Ԫ��
	it = l1.insert(++(l1.begin()), 2); //���뷵�ز���λ��Ԫ�صĵ�����

	std::unordered_set<int> us1 = { 3,2,1,4,33 };
	for (auto it = us1.begin(); it != us1.end(); ++it)
	{
		std::cout << *it << std::endl; //���Կ���˳�����ҵģ��ǰ���hash�������������
	}

	us1.insert(1);
	int i = us1.erase(33); //ɾ�����ڵķ���1
	int j = us1.erase(34); //�����ڵķ���0

  //��������ɾ���ض�ֵdemo
  {
      std::vector<int>array;
    array.push_back(100);
    array.push_back(300);
    array.push_back(300);
    array.push_back(500);
    std::vector<int>::iterator itor;
    for (itor = array.begin(); itor != array.end(); itor++)
    {
      if (*itor == 300)
      {
        itor = array.erase(itor); //erase�˹���ָ����һ��
      }
    }
    for (itor = array.begin(); itor != array.end(); itor++)
    {
      std::cout << *itor << " ";
    }
    //��ʵҲ������remove_if,Ȼ�����erase,���鿴effective stl
  }


	return 0;
}

