/*
12. Integer to Roman
*/

/*
通过字符串数组存储符号,辗转相减，并拼接对应罗马数字
*/

#include <string>
using namespace std;

class Solution {
public:
	string intToRoman(int num) {
		//罗马输出string映射数组
		string numeralMap[13] = { "M", "CM", "D", "CD", "C", "XC",
			                    "L", "XL", "X", "IX", "V", "IV", "I"};
		//数字进制映射数组
		int numerals[13] = { 1000, 900, 500, 400, 100, 90,
						50, 40, 10, 9, 5, 4, 1 };

		string res;
		//辗转相减，并凭借罗马输出
		for (int i = 0; i < 13;)
		{
			//num能够正常减去numerals[i]对应的进制数字
			if ((num - numerals[i]) >= 0)
			{
				res += numeralMap[i];
				num -= numerals[i];
				continue;
			}
			i++;
		}
		return res;
	}
};