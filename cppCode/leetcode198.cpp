/*
198. House Robber

You are a professional robber planning to rob houses along a street.
Each house has a certain amount of money stashed, the only constraint
stopping you from robbing each of them is that adjacent houses have 
security system connected and it will automatically contact the police 
if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money 
of each house, determine the maximum amount of money you can rob tonight 
without alerting the police.

你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，
影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，
如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。

给定一个代表每个房屋存放金额的非负整数数组，计算你在不触动警报装置的情况下，能够偷窃到的最高金额。

Example 1:

Input: [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
             Total amount you can rob = 1 + 3 = 4.
*/

/*
分析:此题可以用动态规划求解，拥有最优子结构，由n-1可以推导出n，且无后效性。
     第i位共有两种决策：
	 1）抢第i个房屋：则最高金额 = 抢第i-2户最高金额 + 当前房间金额。即 dp[i] = dp[i-2] + nums[i]
	 2）不抢第i个房屋：则最高金额 = 抢第i-1户最高金额。即 dp[i] = dp[i-1]

	 故有状态转移方程：			
			dp[i] = max(dp[i-1],dp[i-2]+nums[i]);
	
	dp[i]表示抢第i个房屋能够获得的最高金额

例：  2 7  9  3  1
   dp 2 7 11 11 12
*/


#include <vector>
#include <string>
#include <algorithm>
using namespace std;


class Solution {
public:
    int rob(vector<int>& nums) {
        
		switch(nums.size())
		{
		case 0:
			return 0;
		case 1:
			return nums[0];
		case 2:
			return max(nums[0],nums[1]);
		default:
			return getMaxMonoey(nums);
		}
    }

	int getMaxMonoey(const vector<int> &nums)
	{
		int len = nums.size();
		//虽然传入都是大于2的，但是正常的编程习惯需要加保护
		if(len < 3)
			return 0;

		vector<int> dp(len);

		dp[0] = nums[0];
		dp[1] = max(nums[0], nums[1]);
			
		//根据状态转移方程，填充动态规划数组。
		for(int i=2; i<len; ++i)
		{
			dp[i] = max(dp[i-1],dp[i-2]+nums[i]);
		}
		return dp[len-1];
	}
	
};