/*
26. Remove Duplicates from Sorted Array
Given a sorted array nums, remove the duplicates in-place such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.
*/
/*
解题思路：双下标遍历
将数组分为两个部分，一个部分为待处理数组，另一个部分为已处理数组，不断的将待处理数组放入已处理数组即可
*/

#include <vector>

using namespace std;
class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		if (nums.empty() || nums.size() == 1)
		{
			return nums.size();
		}
		//待处理数组下标，已处理数组下标
		int pendingIndex = 1, processedIndex = 0;
		while (pendingIndex < nums.size())
		{
			//nums[pendingIndex] 与 nums[processedIndex]相同，则pendingIndex+1，表示该数字已加入
			if (nums[pendingIndex] == nums[processedIndex])
			{
				pendingIndex++;
			}
			//将新数字加入已处理数组末尾
			else
			{
				processedIndex++;
				nums[processedIndex] = nums[pendingIndex];
				pendingIndex++;
			}
		}
		return processedIndex + 1;
	}
};