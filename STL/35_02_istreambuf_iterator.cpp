// 35_02_istreambuf_iterator.cpp : 定义控制台应用程序的入口点。
//


#include <iterator>
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;


int main()
{
	//ifstream ifs("test.txt");

	//if (!ifs.is_open())
		//return -1;
	//istreambuf_iterator可以读入空格，不忽略任何字符，注意，(istreambuf_iterator<char>(ifs))必须用括号括起来,原因参见Effective STL M6
	//string fileContent((istreambuf_iterator<char>(ifs)), istreambuf_iterator<char>());

	//string str;
	//copy(istreambuf_iterator<char>(cin), istreambuf_iterator<char>(),back_inserter(str) ); //不能这样，还是直接getline吧


	string strWithSpace("ab c d\nf g");

	copy(strWithSpace.begin(), strWithSpace.end(), ostream_iterator<char>(cout));//输出好像都能输出空格
	copy(strWithSpace.begin(), strWithSpace.end(), ostreambuf_iterator<char>(cout));

	system("pause");
	return 0;
}

