// 34_02_ifstream_ofstream.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <fstream>
#include <string>
#include <iostream>
using namespace std;
int main()
{
	//二进制打开和文本方式打开的区别:
	//https://www.cnblogs.com/litaozijin/p/6582048.html
	//总结一下就是:linux下没有区别，windows下用文本模式的话，写入文件的\n会变成\r\n,读取到的\r\n会转换成\n,二进制模式则不会

	//总结:ofs.write或者read使指针发生变化
	//seekp是调整写指针，默认第二个参数是ios::beg,从开头往后偏移
	//tellp返回当前所在位置，最开始是0
	//ios::cur是个内部成员变量，值是1，代表当前位置
	//seekp是put就是写，seekg是get就是读
	//seek都有两种版本，一种是绝对位置，一种是相对位置

	ofstream ofs("../a.txt", ios::binary); //二进制方式打开
	cout << ofs.tellp() << endl;
	ofs.write("abc", 3);
	cout << ofs.tellp() << endl; //3
	ofs.seekp(10, ios::beg);
	cout << ofs.tellp() << endl; // 10
	ofs.write("defg", 4);
	cout << ofs.tellp() << endl;
	ofs.seekp(20);
	cout << ofs.tellp() << endl;
	ofs.write("hijkl", 5);
	ofs.seekp(30);
	ofs.write("abc我们的", 9);
	ofs.close();


	ifstream ifs("../a.txt");
	char buf[CHAR_MAX];
	ifs.read(buf, 10);
	cout << buf << endl;
	cout << ifs.tellg() << endl; //10
	ifs.read(buf, 10);
	cout << buf << endl;
	cout << ifs.tellg() << endl; //20
	ifs.read(buf, 10);
	cout << buf << endl;
	ifs.read(buf, 10);
	cout << buf << endl;

	ifs.close();

	ifs.open("HA9F7220.JPG",ios::ate); //打开就定位到文件尾
	cout << ifs.tellg() << endl; //这样可以直接获取文件大小



    return 0;
}

