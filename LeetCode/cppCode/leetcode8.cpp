/*
8. String to Integer (atoi)

*/
#include <string>
#include <iostream>
#include <sstream>
#include <limits> 
using namespace std;

class Solution {
public:
	int myAtoi(string str) {
		int flag = 1;//符合位,默认为1代表正，-1代表负
		long ans = 0;//数字部分
		int i = 0, len = str.size();

		while (i < len && str[i] == ' ')
			i++;

		//符号位处理
		if (str[i] == '-' || str[i] == '+')
		{
			flag = str[i] == '-' ? -1 : 1;
			i++;
		}


		//数字部分处理
		while (i < len && str[i] >= '0' && str[i] <= '9')
		{
			ans = ans * 10 + str[i] - '0';
			//正数部分越界
			if (flag == 1 && ans > numeric_limits<int>::max())
			{
				return numeric_limits<int>::max();
			}
			//负数部分越界
			if (flag == -1 && (-1 * ans) < numeric_limits<int>::min())
			{
				return numeric_limits<int>::min();
			}
			i++;
		}
		return flag * ans;
	}
};