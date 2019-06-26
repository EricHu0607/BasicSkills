/*
13. Roman to Integer
*/

/*
通过对第一个罗马字的判断，如果是IXC，则继续判断下一字符，将字符拼接成key，从映射表中
获得对应数值信息
*/
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
	int romanToInt(string s) {
		//罗马与数值映射表
		unordered_map<string, int> numeralsMap{ {"M", 1000}, {"CM", 900}, {"D", 500},
												{"CD", 400}, {"C", 100}, {"XC", 90},
												{"L", 50}, {"XL", 40}, {"X", 10},
												{"IX", 9}, {"V", 5}, {"IV", 4}, {"I", 1} };
		string specialFirstRoman("IXC");
		string specialSecondRoman[3]{ {"VX"},{"LC"},{"DM"} };
		string key;
		int len = s.size();
		int j, k;
		int res = 0;
		for (int i = 0; i < len;)
		{
			//拼接第一个罗马字
			key += s[i];
			//判断第一个罗马字是否属于IXC
			for (j = 0; j < specialFirstRoman.size(); j++)
			{
				//第一个罗马字属于IXC
				if (s[i] == specialFirstRoman[j])
				{
					//第一个罗马字属于IXC，需要对下一个罗马字进一步判断
					if ((i++) == len)
						break;
					for (k = 0; k < specialSecondRoman[j].size(); k++)
					{
						if (s[i] == specialSecondRoman[j][k])
						{
							key += s[i];
							i++;
							break;
						}
					}
					break;
				}
			}
			
			//第一个罗马字不属于IXC
			if (j == specialFirstRoman.size())
				i++;
			//根据key获取数值
			res += numeralsMap[key];
			//清空key
			key.clear();
		}
		return res;
	}
};