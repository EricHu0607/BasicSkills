/*
A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Given a non-empty string containing only digits, determine the total number of ways to decode it.

Example 1:

Input: "12"
Output: 2
Explanation: It could be decoded as "AB" (1 2) or "L" (12).
*/

/*
分析：可以用动态规划的思想来做，当前n位总共有多少编码方式，取决于n-1位共有多少种。
	第i位共有2种决策：
	1）若i-1位与i位组成的数属于[1,26],则第i位编码总数=第i-1位编码总数+第i-2为编码总数
	2）若i-1位与i位组成的数>26,则第i位编码总数=第i-1位编码总数

	可以写出对应的状态转移方程。
		1<=s[i-1]s[i]<=26:dp[i] = dp[i-1] + dp[i-2]
		s[i-1]s[i]>26:dp[i] = dp[i-1] 
例：  1 2 1 2 1 2
   dp 1 2 3 5 8 13

注：需要考虑为i位为0的情况，虽然题目中没有明确表示，但是测试用例中有0的情况。
*/

#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int numDecodings(string s) {
    
		int len = s.size();

		//特殊情况处理
		if(!len || s[0] == '0')
			return 0;

		vector<int> dp(len);

		dp[0]=1;
		for(int i=1; i < len; ++i)
		{
			//如果s[i]=='0'则有两种情况1）s[i-1]为1和2，则dp[i] = dp[i-2] (要考虑i-2<0)
			//                           2) s[i-2]!= 1、2,则此次解码无效。 
			if (s[i] == '0')
			{
				if (s[i-1] == '1' || s[i-1] == '2')
					dp[i] = i-1 > 0 ? dp[i-2]:dp[i-1];
				else
					return 0;
			}
			//如果s[i]!='0'则有两种情况  1）s[i-1]s[i]属于[1,26],则dp[i] = dp[i-1] + dp[i-2]
			//                           2) s[i-1]s[i]>26,则dp[i] = dp[i-1] 
			else
			{
				if(s[i-1] == '1' && s[i] != '0')
					dp[i] = dp[i-1]+(i-1 > 0 ? dp[i-2]:1);
				else if (s[i-1] == '2' && ((s[i]-'0'>0) && (s[i]-'0')<7))
					dp[i] = dp[i-1]+(i-1 > 0 ? dp[i-2]:1);
				else 
					dp[i] = dp[i-1];
			}
		}
		return dp[len-1];
	}
};