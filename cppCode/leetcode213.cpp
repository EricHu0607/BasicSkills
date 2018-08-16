/*
213. House Robber II

You are a professional robber planning to rob houses along a street.
Each house has a certain amount of money stashed. All houses at this 
place are arranged in a circle. That means the first house is the neighbor 
of the last one. Meanwhile, adjacent houses have security system connected 
and it will automatically contact the police if two adjacent houses were 
broken into on the same night.

Given a list of non-negative integers representing the amount of money of 
each house, determine the maximum amount of money you can rob tonight without 
alerting the police.

你是一个专业的小偷，计划偷窃沿街的房屋，每间房内都藏有一定的现金。
这个地方所有的房屋都围成一圈，这意味着第一个房屋和最后一个房屋是紧挨着的。
同时，相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。

给定一个代表每个房屋存放金额的非负整数数组，计算你在不触动警报装置的情况下，能够偷窃到的最高金额。
Example 1:

Input: [2,3,2]
Output: 3
Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2),
             because they are adjacent houses.


*/

/*
分析： 该题是198的一个扩展。
	只需要在最后的n处进行一个特判，就可以解决。1）如果选择n，则序列应为 1...n
											   2）如果不选择n，则序列应为 0...n-1
	分别进行处理，取出两者最大即可。

例：
      1 2 3 1
1）dp   2 3 3   1...n序列
2）dp 1 2 4     0...n-1序列

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
			return max(getMaxMoney(nums,0, nums.size()-2), getMaxMoney(nums, 1, nums.size()-1));
		}
    }

	//start代表其实位置，为0、1，end为终点，对应n-1、n
	int getMaxMoney(const vector<int> &nums, int start, int end)
	{
		int len = nums.size();
		//虽然传入都是大于2的，但是正常的编程习惯需要加保护
		if(len < 3)
			return 0;

		vector<int> dp(end-start+1);

		dp[0] = nums[start];
		dp[1] = max(nums[start+1], nums[start]);

		//根据状态转移方程，填充动态规划数组，要根据start来进行偏移。
		for(int i=2; i<end-start+1; ++i)	
		{
			dp[i] = max(dp[i-1],dp[i-2]+nums[i+start]);
		}
		return dp[end-start];
	}
	
};