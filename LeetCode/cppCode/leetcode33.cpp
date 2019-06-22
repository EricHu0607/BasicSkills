/*
33. Search in Rotated Sorted Array
*/
/*
二分查找的变体，区间[low,mid],[mid,high]，必然有一个有序，利用二分查找对
nums[mid]比较，选择区间时，要对有序区间进行区分，对low和high索引进行处理。
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int search(vector<int>& nums, int target) {
		int low = 0, high = nums.size() - 1;
		int mid = 0;

		while (low <= high)
		{
			mid = low + ((high - low) >> 1);
			//若target == nums[mid]，则返回下标
			if (target == nums[mid])
			{
				return mid;
			}
			//target < nums[mid]时，对两种不同区间的处理
			else if (target < nums[mid])
			{
				//递增区间为[low,mid]
				if (nums[low] <= nums[mid])
				{
					if (target >= nums[low])
					{
						high = mid - 1;
					}
					else
					{
						low = mid + 1;
					}
				}
				//递增区间为[mid,high]
				else
				{
					high = mid - 1;
				}
			}
			//target > nums[mid]时，对两种不同区间的处理
			else
			{
				//递增区间为[low,mid]
				if (nums[low] <= nums[mid])
				{
					low = mid + 1;
				}
				//递增区间为[mid,high]
				else
				{
					if (target >= nums[low])
					{
						high = mid - 1;
					}
					else
					{
						low = mid + 1;
					}
				}
			}
		}

		return -1;
	}
};