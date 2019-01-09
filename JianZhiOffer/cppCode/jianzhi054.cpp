/*
054 正则表达式匹配

题目描述
请实现一个函数用来匹配包括'.'和'*'的正则表达式。模式中的字符'.'表示任意一个字符，
而'*'表示它前面的字符可以出现任意次（包含0次）。 在本题中，匹配是指字符串的所有字符匹配整个模式。
例如，字符串"aaa"与模式"a.a"和"ab*ac*a"匹配，但是与"aa.a"和"ab*a"均不匹配
*/

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	bool match(char* str, char* pattern)
	{
		int sLen, pLen;
		sLen = strlen(str);
		pLen = strlen(pattern);

		//DP数组，列表示p，行表示s， dp[i][j] 表示 s[0..i-1] 与 p[0..j-1]的匹配情况
		vector<vector<bool>> dp(sLen + 1, vector<bool>(pLen + 1, false));

		//初始化部分：其中dp[0][0]为1，dp[0][j]要根据p[j-1]的状态决定，
		//可以参考一下s=""，p=".*"来进行初始化赋值
		dp[0][0] = true;

		for (int j = 1; j <= pLen; j++)
			dp[0][j] = (j > 1 && '*' == pattern[j - 1] && dp[0][j - 2]);

		for (int i = 1; i <= sLen; i++)
			for (int j = 1; j <= pLen; j++)
				if (pattern[j - 1] != '*')
					dp[i][j] = dp[i - 1][j - 1] && (str[i - 1] == pattern[j - 1] || '.' == pattern[j - 1]);
				else//若为*，则需要根据dp[][j-2]，以及当前值是否匹配，要判断dp[i-1][j]是否匹配
					dp[i][j] = dp[i][j - 2] || (str[i - 1] == pattern[j - 2] || '.' == pattern[j - 2]) && dp[i - 1][j];

		return dp[sLen][pLen];
	}
};