/*
347. Top K Frequent Elements
*/

#include <vector>
#include <queue>
#include <unordered_map>
#include <list>
using namespace std;
class Solution {
public:
	struct cmp
	{
		bool operator()(const pair<int, int> &a, const pair<int, int> &b)
		{
			return a.first > b.first;
		}
	};

	vector<int> topKFrequent(vector<int>& nums, int k) {
		unordered_map<int, int> hash;

		//统计每个整数的个数
		for (int i = 0; i < nums.size(); i++)
		{
			hash[nums[i]]++;
		}

		//获取最大的K个，采用小顶堆
		priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> min_heap;

		for (auto it = hash.begin(); it != hash.end(); ++it)
		{
			if (min_heap.size() == k)
			{
				if (it->second > min_heap.top().first)
				{
					min_heap.pop();
					min_heap.push(make_pair(it->second, it->first));
				}
			}
			else
			{
				min_heap.push(make_pair(it->second, it->first));
			}
		}

		//从min_heap复制到vector，从频率最高->最低
		vector<int> ret_vec(k);
		int size = min_heap.size();
		for (int i = 0; i < size; i++)
		{
			ret_vec[size - i - 1] = min_heap.top().second;
			min_heap.pop();
		}
		return ret_vec;

	}
};