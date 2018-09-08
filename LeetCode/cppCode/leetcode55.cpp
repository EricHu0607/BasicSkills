/*
55. Jump Game

Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

Example 1:

Input: [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:

Input: [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum
             jump length is 0, which makes it impossible to reach the last index.
*/

/*
分析：本题可以采用动态规划来解，也可以用树的思想去解，看能不能蔓延到最后一个节点。
	  本次采用贪心策略，i+nums[i]>=retPos表示能达到最后节点。
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    bool canJump(vector<int>& nums) {
		int retPos = nums.size() - 1;
        for (int i = nums.size() - 1; i >= 0; --i) {
            if (i + nums[i] >= retPos) {
                retPos = i;
            }
        }
        return (retPos == 0);
    }
};