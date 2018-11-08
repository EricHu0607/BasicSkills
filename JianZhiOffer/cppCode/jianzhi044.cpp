/*
044 和为S的两个数字
题目描述
输入一个递增排序的数组和一个数字S，在数组中查找两个数，使得他们的和正好是S，
如果有多对数字的和等于S，输出两个数的乘积最小的。

输出描述:
对应每个测试案例，输出两个数，小的先输出。
*/

#include <iostream>
#include <vector>
#include <limits>
using namespace std;

class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> arr,int sum) {
        
		vector<int> res;
		int len = arr.size();
		if(len < 2)
			return res;

		int begin = 0, end = len - 1, curSum;
		int min = numeric_limits<int>::max();
		while(begin != end)
		{
			curSum = arr[begin] + arr[end];
			if(curSum == sum)
			{
				if(min > arr[begin] * arr[end])
				{
					min = arr[begin] * arr[end];
					res.clear();
					res.push_back(arr[begin]);
					res.push_back(arr[end]);
				}
				begin++;
			}
			else if(curSum > sum)
			{
				end--;
			}
			else
			{
				begin++;
			}
		}
		return res;
    }
};