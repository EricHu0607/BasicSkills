/*
16. 3Sum Closest
*/

/*
和15题类似，关键是判断diff，保存最接近的元素
*/
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target) {
		//将数字排序
		sort(nums.begin(), nums.end());

		//左右index
		int left, right;

		if (nums.size() < 3)
			return 0;
		//diff存储这次最接近元素，lastDiff，存储之前所有最接近元素
		int diff = nums[0] + nums[1] + nums[nums.size() - 1] - target;
		int lastDiff = diff;

		for (int i = 0; i < (nums.size() - 2); i++)
		{
			left = i + 1;
			right = nums.size() - 1;
			//移动左右index
			while (left < right)
			{
				diff = nums[i] + nums[left] + nums[right] - target;
				//更新最小的diff，存于lastDiff
				if (abs(diff) < abs(lastDiff))
					lastDiff = diff;

				//对三个数字之和-target进行判断
				if (diff == 0)
					break;
				else if (diff > 0)
					right--;
				else
					left++;
			}

		}
		return lastDiff + target;
	}
};