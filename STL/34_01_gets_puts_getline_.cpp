// 34_01_io流.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>  //包含geiline(istream,string)
#include <stdio.h>
#include <cstring>
#include <vector>
#include <sstream>

using namespace std;

int main()
{

	////string的读入，两种:>>和getline()
	//{
	//	string temp;
	//	cin >> temp; //cin作为输入的话，不会接受空白字符
	//	cout << "输入的是" << temp << endl;
	//	getline(cin, temp); //可以包含空白字符，以回车结束

	//}
	//
	////get,put函数
	//{
	//	char arr[7];
	//	//遇到EOF(CTRL+Z)都会结束
	//	//cin.get(arr,6); //指定读入最大6个字符
	//	cin.get(arr, 6,'\n'); //指定读入最大6个字符或者遇到'\n'结束,默认也是遇到'\n'结束

	//	cout << arr << endl; 

	//}


	//char c[10];
	//cin.getline(&c[0], 5, 'g'); //指定接受5-1个字符，因为最后一个是\0

	//

	//{
	//	char str[20];
	//	//gets(str); //C++11中被删除了，用fgets替代
	//	char * str1 = fgets(str, 200, stdin); //gets相比于scanf的好处是到行末才会停止，因此可以接收空白字符

	//	//但是不是说scanf就完全没法接受空白字符，比如scanf("%s %s")，这样也是很可以接受两个字符串的，只是说单个%s中不能存在空白

	//	//fgets的话会添加新换行符在末尾，gets不会
	//	std::cout << str1 << std::endl;
	//}

	//读入1,-2,3,-4这种以逗号分隔字符串的内容
	string ss;
	cin >> ss; //先通过这个读入整个字符串，再用stringstream读才行，不知道为啥直接getline用分隔符不行

	stringstream sstr(ss);
	std::string tmp;
	std::vector<int> v;
	//while (!std::getline(std::cin, tmp, ',').eof())
	while (std::getline(sstr, tmp, ','))
	{
		v.push_back(stoi(tmp));
	}



	system("pause");
	return 0;
}

