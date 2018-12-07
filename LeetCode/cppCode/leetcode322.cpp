
/*
给定不同面额的硬币 coins 和一个总金额 amount。编写一个函数来计算可以凑成总金额所需的最少的硬币个数。如果没有任何一种硬币组合能组成总金额，返回 -1。

示例 1:

输入: coins = [1, 2, 5], amount = 11
输出: 3 
解释: 11 = 5 + 5 + 1
示例 2:

输入: coins = [2], amount = 3
输出: -1
说明:
你可以认为每种硬币的数量是无限的。
*/
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        
			if(amount < 0 )
				return -1;

			vector<int> dp(amount);
			return search(coins, amount,dp);
		}

		int search(vector<int>& coins, int rem, vector<int>& dp )
		{
		//如果剩下的钱小与0；返回-1
			if(rem < 0)
				return -1;
		//剩下的钱刚好为0，,说明刚刚好可以找完。
			if(rem == 0)
				return 0;

			//备忘录来存储
			if(dp[rem-1] != 0 )
				return dp[rem-1];

		//用最大值来存，表示最小，排除返回-1带来的求值干扰
			int min = numeric_limits<int> :: max();
			for(int i=0; i< coins.size(); ++i)
			{
				int res = search(coins, rem-coins[i],dp);
				if(res >=0 && res <min)
					min = 1+res;


			}
			return dp[rem-1] =(min == numeric_limits<int> :: max() ? -1: min);
	}
};

