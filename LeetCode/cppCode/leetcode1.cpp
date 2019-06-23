#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:

	vector<int> twoSum(vector<int>& nums, int target) {

		vector<int> res;
		unordered_map<int, int> hash;//<elements,index>
		int len = nums.size();
		for (int i = 0; i < len; ++i)
		{
			//在hash中没有找到target-nums[0]元素
			if (hash.find(target - nums[i]) == hash.end())
			{
				hash[nums[i]] = i;
			}
			else
			{
				res.push_back(hash[target - nums[i]]);
				res.push_back(i);
				break;
			}
		}
		return res;
	}
};