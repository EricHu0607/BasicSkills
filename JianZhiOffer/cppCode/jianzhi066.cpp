/*
066 滑动窗口的最大值

题目描述
给定一个数组和滑动窗口的大小，找出所有滑动窗口里数值的最大值。
例如，如果输入数组{2,3,4,2,6,2,5,1}及滑动窗口的大小3，那么一共存在6个滑动窗口，
他们的最大值分别为{4,4,6,6,6,5}； 针对数组{2,3,4,2,6,2,5,1}的滑动窗口有以下6个：
{[2,3,4],2,6,2,5,1}， {2,[3,4,2],6,2,5,1}， {2,3,[4,2,6],2,5,1}， {2,3,4,[2,6,2],5,1}，
{2,3,4,2,[6,2,5],1}， {2,3,4,2,6,[2,5,1]}。
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
	vector<int> maxInWindows(const vector<int>& num, unsigned int size)
	{
		vector<int> res;
		//滑动窗口最大值队列 pair<值,下标>
		priority_queue<pair<int, int>> maxQue;//默认大值在前

		//特殊情况
		if (num.empty() || size <=0 )
		{
			return res;
		}

		//将size-1存入到优先队列中
		for (int i = 0; i < size - 1; i++)
		{
			maxQue.push(pair<int, int>(num[i], i));
		}

		int len = num.size();
		for (int i = size - 1; i < len; i++)
		{
			maxQue.push(pair<int, int>(num[i], i));
			pair<int, int> tmp = maxQue.top();

			//如果最大值已经不在滑动窗口内，重新调整最大优先队列
			while (tmp.second < i - (size - 1))
			{
				maxQue.pop();
				tmp = maxQue.top();
			}
			res.push_back(tmp.first);
		}
		return res;
	}
};