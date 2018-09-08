/*
*Given two words word1 and word2, find the minimum number of operations required to convert word1 to word2.

You have the following 3 operations permitted on a word:

Insert a character
Delete a character
Replace a character
Example 1:

Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation: 
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')
*/

/*
动态规划的典型题：求最小步长，可以通过最优子结构n-1来推导n的情况

状态转移方程：
    dp二维数组，用来保存word1 第0...i个字符变化到word2 第0...j个字符的最小步长
    一共有三种策略：删，添，改。
	1）若 word1[i] == word2[j] ，则不用进行操作dp[i+1][j+1] = dp[i][j]
	2) 若 word1[i] != word2[j] , 则可以通过三种策略：删，添，改当前字母，
	使word1[0...i]->word2[0...j]字符串。三种策略对应如下：
		删：dp[i+1][j+1] = dp[i][j+1] + 1
		添：dp[i+1][j+1] = dp[i+1][j] + 1
		改：dp[i+1][j+1] = dp[i][j] +1

		取出最小更新到dp[i+1][j+1]就是状态转移方程，即dp[i+1][j+1] = min(dp[i+1][j],min(dp[i][j],dp[i][j+1]))+1;

例:
  word1="horse" word2="ros"
  dp[][]   ""r o s
        "" 0 1 2 3
		h  1 1 2 3 
		o  2 2 1 2
		r  3 2 2 2
		s  4 3 3 2
		e  5 4 4 3

注：由于本例dp数组只需要记录当前行以及上一行（i和i-1行），其他行数都不需要，可以通过3行的滚动数组来存储，
	用来降低空间复杂度。
*/

#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        
		int len1 = word1.size();
		int len2 = word2.size();

		//若为空，则特殊处理
		if(!len1) return len2; 
		if(!len2) return len1;

		//分配dp二维数组，用来保存word1 第0...i个字符变化到word2 第0...j个字符的最小步长
		vector<vector<int>> dp(len1+1,vector<int>(len2+1));
		for(int i=0; i <= len2; ++i)
			dp[0][i] = i;
		for(int i=0; i <= len1; ++i)
			dp[i][0] = i;
		
		//利用状态转移方程，填充数组
		for(int i=0; i<len1; ++i)
		{
			for(int j=0; j<len2; ++j)
			{
				if( word1[i] == word2[j])
					dp[i+1][j+1] = dp[i][j];
				else
				{
					dp[i+1][j+1] = min(dp[i+1][j],min(dp[i][j],dp[i][j+1]))+1;
				}
			}
		}
		return dp[len1][len2];
    }
};