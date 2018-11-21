/*
052 把字符串转换成整数
题目描述
将一个字符串转换成一个整数(实现Integer.valueOf(string)的功能，但是string不符合数字要求时返回0)，
要求不能使用字符串转换整数的库函数。 数值为0或者字符串不是一个合法的数值则返回0。
输入描述:
输入一个字符串,包括数字字母符号,可以为空
输出描述:
如果是合法的数值表达则返回该数字，否则返回0
*/

#include<string>
#include<iostream>
using namespace std;

class Solution {
public:
	int StrToInt(string str) {

		int len = str.size();
		if (len == 0)
			return 0;

		bool flag = true;
		string cal_str;
		if (str[0] == '+' || str[0] == '-')
		{
			flag = str[0] == '+' ? true : false;
			cal_str = str.substr(1, len);
		}
		else
			cal_str = str;

		//取去掉符号位的部分，转化为int
		int length = cal_str.size();
		int res = 0;
		for(int i = 0; i < length; i++)
		{
			if (cal_str[i] >= '0' && cal_str[i] <= '9')
			{
				res = (cal_str[i] - '0') + res * 10;
			}
			else
				return 0;
		}
		return flag ? res : -res;
	}
};