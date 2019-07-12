/*
17. Letter Combinations of a Phone Number
*/

/*
计算出digits字符串所转换出的所以输出组合，根据
output[j] += input[i][j / segmentSize % strSize]来填充数组即可
时间复杂度O(3^N*4^N * len)
*/
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
	vector<string> letterCombinations(string digits) {
		if (digits.size() == 0) return vector<string>();
		unordered_map<char, string> digitMap{ {'2', "abc"}, {'3', "def"}, {'4',"ghi"},
											  {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"},
											  {'8', "tuv"}, {'9', "wxyz"} };
		
		vector<string> input;//数字输入转为的字母输入
		int count = 1;//共有多少组合
		int len = digits.size();

		//将数字输入，转换为对应的字母输入，存于input,并计算一共有多少组合
		for (int i = 0; i < len; i++)
		{
			input.push_back(digitMap[digits[i]]);
			count *= digitMap[digits[i]].size();
		}

		vector<string> output(count);
		int strSize, segmentSize = count; //数字字符对应的string长度，相同段的长度
		//控制总长度
		for (int i = 0; i < len; i++)
		{
			strSize = input[i].size();
			segmentSize /= input[i].size();
			//控制数组中对应一个字符拼接输出
			for (int j = 0; j < count; j++)
				output[j] += input[i][j / segmentSize % strSize];
		}
		return output;
	}
};