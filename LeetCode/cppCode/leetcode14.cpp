/*
14. Longest Common Prefix
*/
/*
保存strs[0]为初始共同首字符串prefix，接下来prefix与strs[1...n]进行比较，
每次比较调整prefix，使得prefix与strs[i]有相同共同首字符
*/
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		//特殊处理
		if (strs.size() == 0)
			return "";

		string prefix = strs[0];
		int len = strs.size();
		int j, prefixSize;
		//对strs数组进行比较，由prefix字符串与strs[i]比较，调整共同首字符
		for (int i = 1; i < len; i++)
		{
			prefixSize = prefix.size();
			for (j = 0; j < prefixSize; j++)
			{
				//取得头开始相同部分
				if (strs[i].compare(0, prefixSize - j, prefix, 0, prefixSize - j) == 0)
				{
					prefix = prefix.substr(0, prefixSize - j);
					break;
				}
			}
			//没有相同部分
			if (j == prefixSize)
			{
				prefix = "";
				break;
			}
		}
		return prefix;
	}
};