/*
55 表示数值的字符串

题目描述
请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。
例如，字符串"+100","5e2","-123","3.1416"和"-1E-16"都表示数值。 
但是"12e","1a3.14","1.2.3","+-5"和"12e+4.3"都不是。
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	bool isNumeric(char* str)
	{
		//字符串为空返回false
		if (str == NULL)
			return false;

		//跳过开始的'+','-'
		if (*str == '+' || *str == '-')
			str++;

		//跳过连续的数值部分
		skipNumber(str);

		//代表为正数
		if (*str == '\0')
			return true;
		else if (*str == '.')
		{
			++str;
			skipNumber(str);
			if (*str == '\0')
				return true;
			else
			{
				return isExp(str);
			}
		}
		else if (*str == 'e' || *str == 'E')
		{
			return isExp(str);
		}
		else
			return false;

	}

	//判断e，E符合之后是否为指数式
	bool isExp(char* & str)
	{
		if (*str != 'e' && *str != 'E')
		{
			return false;
		}

		++str;

		//跳过e，E之后的+，-符号
		if (*str == '+' || *str == '-')
		{
			++str;
		}

		//+，-之后没有数值，返回false
		if (*str == '\0')
		{
			return false;
		}
		
		skipNumber(str);

		return (*str == '\0') ? true : false;
	}

	//跳过数字部分
	void skipNumber(char* & str)
	{
		while (*str != '\0' && *str >= '0' && *str <= '9')
		{
			str++;
		}
	}
};