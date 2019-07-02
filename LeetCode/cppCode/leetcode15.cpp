/*
15. 3Sum
*/

/*
a+b+c = 0 <=> a+b=-c，所以只需要对原数组排序，由小到大，对不大于0的部分先选为c，
接着将c之后的数组视为a+b=-c，可以通过left，right索引来判断。
注意：需要去掉重复数字
*/
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		//将数字排序
		sort(nums.begin(), nums.end());

		//左右index
		int left, right;
		vector<vector<int>> res;

		if (nums.size() < 3)
			return res;

		//将不大于0的部分作为后两数和的相反数 a + b = -c (c小于0)
		for (int i = 0; i < (nums.size() - 2) && nums[i] <= 0; i++)
		{
			left = i + 1;
			right = nums.size() - 1;
			//移动左右index
			while (left < right)
			{
				//对三个数字之和进行判断
				if (-nums[i] == nums[left] + nums[right])
				{
					res.push_back(vector<int> {nums[i], nums[left], nums[right]});
					//去重复
					while (left < right && nums[left] == nums[left + 1])
						left++;
					while (right > i && nums[right] == nums[right - 1])
						right--;
					left++;
					right--;
				}
				else if (-nums[i] < nums[left] + nums[right])
					right--;
				else
					left++;
			}
			//去重复
			while (i < nums.size() - 1 && nums[i] == nums[i + 1])
				i++;
		}
		return res;
	}
};