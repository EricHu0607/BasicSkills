/*
050 不用加减乘除做加法

题目描述
写一个函数，求两个整数之和，要求在函数体内不得使用+、-、*、/四则运算符号。
*/

#include <iostream>
class Solution {
public:
	int Add(int num1, int num2)
	{
		int flag = 1, carry = 0;
		int res = 0;
		while (flag)
		{
			res |= (carry ^ (num1 & flag) ^ (num2 & flag))>>1;
		}
	}
};