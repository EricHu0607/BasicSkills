/*
011 变态跳台阶
题目描述

一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。
求该青蛙跳上一个n级的台阶总共有多少种跳法。
*/

/*
分析：此题可以用动态规划求解。
	  第n个台阶决策： dp[n] = dp[n-1]+dp[n-2]+...+dp[0];

*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int jumpFloorII(int number) {
		vector<int> dp(number+1, 0);
		switch (number)
		{
		case 0: 
			return 0;
		case 1:
			return 1;
		case 2:
			return 2;
		default:
			dp[0] = 1;
			dp[1] = 1;
			dp[2] = 2; 
			for(int i = 3; i <= number; i++)
			{
				int j = 1;
				while(j <= i)
				{
					dp[i] += dp[i-j];
					j++;
				}
			}
			return dp[number];
		}
    }
};