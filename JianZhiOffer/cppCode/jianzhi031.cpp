/*
031 最小的K个数

题目描述
输入n个整数，找出其中最小的K个数。例如输入4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4
*/

/*
分析：方法一：利用各种排序，从小到大排序，输出前K个数
	  方法二：维护topN的大根堆，存放最小值。
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        
		vector<int> res;

		if(input.size() == 0 || input.size() < k)
            return res;

		sort(input.begin(), input.end());

		for(int i=0; i < k; i++)
		{
			res.push_back(input[i]);
		}

		return res;
		//
		//vector<int> m_res;

		//if(input.size() == 0 || input.size() < k)
  //          return m_res;

		////使用大根堆的方式，用来存放最小值堆
		//vector<int> maxHeap(k);
		//int index = 0,i = 0;
		//int len = input.size();

		//for(; index < k; index++, i++)
		//{
		//	maxHeap[index] = input[i];
		//}

		//sort(maxHeap.begin(), maxHeap.end(), cmp);

		//for(;i < len; i++)
		//{
		//	if(input[i] < maxHeap[0])
		//	{
		//		//更新大根堆
		//		maxHeap[0] = input[i];
		//		sort(maxHeap.begin(), maxHeap.end(), cmp);
		//	}
		//}

		//vector<int> res(maxHeap.begin(), maxHeap.end());
		//return res;
		
    }

private:
	static bool cmp(int a, int b)
	{
		return (a < b ? false : true);
	}
};