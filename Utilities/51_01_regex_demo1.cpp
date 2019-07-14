// 51_02_Demos.cpp : 定义控制台应用程序的入口点。
//

#include <regex>
#include <string>
#include <assert.h>
#include <iostream>

int main()
{
	//正则匹配
	//自由函数regex_match()用来检查一个字符串是否"完全匹配"一个正则表达式，返回bool结果。
	{
		//匹配身份证号码
		// ^\d{6}(1|2)\d{3}(0|1)\d[0-3]\d\d{3}(X|\d)$
		std::string regex_str("^(\\d{6})((1|2)\\d{3})((0|1)\\d)([0-3]\\d)(\\d{3}(X|\\d))$");
		std::regex pattern(regex_str, std::regex::icase);//忽略字母大小写

		std::string id("61251719901212444X");
		assert(std::regex_match(id, pattern) == true);

		// [a-zA-Z0-9_-]+@[a-zA-Z0-9]+\.[a-zA-Z0-9]+  邮箱简单正则
		std::string mail_reg_str("^[a-zA-Z0-9_-]+@[a-zA-Z0-9]+\\.[a-zA-Z0-9]+$");
		std::regex mail_reg(mail_reg_str, std::regex::icase);

		assert(std::regex_match("chm--1989@163.com", mail_reg) == true);
	}

	//使用正则匹配结果
	//使用match_results来提取匹配结果。
	{
		//识别一个IP地址，并打印各个部分
		//输入exit退出程序
		bool isInputEnd = false;
		//(\d{1,3})\.(\d{1,3})\.(\d{1,3})\.(\d{1,3})
		//有四个子表达式，括号中的内容为一个子表达式
		std::regex ip_reg("(\\d{1,3})\\.(\\d{1,3})\\.(\\d{1,3})\\.(\\d{1,3})");
		std::smatch matchResult;
		const std::string exitStr("EXIT");
		while (!isInputEnd)
		{
			std::cout << "\nInput a IP address:";
			std::string inputStr;
			std::getline(std::cin, inputStr);
			if (inputStr.empty())
			{
				continue;
			}

			std::string tmpStr(inputStr);
			std::transform(tmpStr.begin(), tmpStr.end(), tmpStr.begin(), toupper);
			if (tmpStr == exitStr)
			{
				std::cout << "\nSYSTEM EXIT!";
				isInputEnd = true;
				continue;
			}
			//正则匹配
			if (std::regex_match(inputStr, matchResult, ip_reg))
			{
				std::cout << "Match: ";
				//打印子表达式结果
				for (size_t i = 1; i < matchResult.size(); ++i)
				{
					std::cout << matchResult[i] << " "; //和所有的其他正则一样，第0个是所有的匹配结果，第1个开始是第一个分组
				}
			}
			else
			{
				std::cout << "Not Match!";
			}

		}
	}

	//正则查找
	//regex_search() 与 regex_match的区别是：regex_match要求输入的字符串必须要与正则表达式完全匹配，
	//而regex_search则检测输入表达式中是否包含正则表达式，即存在一个匹配正则表达式的子串。
	{
		//搜索输入字符串中所有满足正则表达式 \d{3} 的子串
		std::regex reg2("\\d{3}");
		std::string test_str("abc12312a--1b234-7890abc567");
		std::string::const_iterator iter = test_str.begin();
		std::string::const_iterator iterEnd = test_str.end();
		std::smatch match_result;
		std::cout << "\n\n" << test_str;
		while (std::regex_search(iter, iterEnd, match_result, reg2))
		{
			std::cout << "\nMatch: " << match_result[0];
			iter = match_result[0].second; //更新搜索起始位置
		}
	}

	//正则替换
	//regex_replace 在整个字符序列中查找正则表达式e的所有匹配。这个算法每次成功匹配后，就根据参数fmt对匹配字符串进行格式化。
	{
		//使用regex_replace 实现trim功能，去掉字符串前后的空白字符
		std::regex reg1("^(\\s)*");
		std::regex reg2("\\s*$");

		std::string test_str("  abc  \t");
		std::string t("");
		test_str = std::regex_replace(test_str, reg1, t); //trim_left
		test_str = std::regex_replace(test_str, reg2, t); //trim_right
	}

    return 0;
}

