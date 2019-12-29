/*
35. Search Insert Position
Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Example 1:

Input: [1,3,5,6], 5
Output: 2
Example 2:

Input: [1,3,5,6], 2
Output: 1
Example 3:

Input: [1,3,5,6], 7
Output: 4
Example 4:

Input: [1,3,5,6], 0
Output: 0
*/
/*
采用二分查找，找到index，再判断index + 1 与index 与 index-1直接的大小，输出
*/
#include <vector>

using namespace std;
class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {
		if (nums.empty() || target < nums[0])
			return 0;
		if (target > nums[nums.size()-1])
		{
			return nums.size();
		}

		//initialize variables
		int len = nums.size();
		int low = 0, high = len - 1;
		int mid = 0;
		
		while (low <= high)
		{
			mid = low + ((high - low) >> 1);
			//找到与target相等的值，返回index
			if (target == nums[mid])
			{
				return mid;
			}
			else if (target < nums[mid])
			{
				high = mid - 1;
			}
			else
			{
				low = mid + 1;
			}
		}

		int index = low;
		if ((index + 1) <= (len - 1) && (nums[index+1] > target && target > nums[index]))
		{
			return index + 1;
		}
		if ((index - 1) >= 0 && (nums[index-1] < target && target < nums[index]))
		{
			return index;
		}
		return len;
	}
};
