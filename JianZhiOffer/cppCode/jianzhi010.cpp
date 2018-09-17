/*
010 跳台阶
题目描述

一只青蛙一次可以跳上1级台阶，也可以跳上2级。
求该青蛙跳上一个n级的台阶总共有多少种跳法（先后次序不同算不同的结果）。
*/

/*
分析：此题可以用动态规划思想来做。第n阶的决策：
		第n个台阶的跳法 = 第n-1个台阶的跳法+第n-2个台阶的跳法。
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int jumpFloor(int number) {
		vector<int> dp(number);
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
			dp[1] = 2;
			for(int i = 2; i < number; i++)
				dp[i] = dp[i-1] + dp[i-2];
			return dp[number-1];
		}

    }
};