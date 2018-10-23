/*
039 数字在排序数组中出现的次数

题目描述
统计一个数字在排序数组中出现的次数。
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {
        
		vector<int>::iterator it = find(data.begin(), data.end(), k);
		
		if(it == data.end())
			return 0;
		else
		{
			vector<int>::iterator pre,next;
			pre = it++;
			next = it;
			int count = 0;
			while(*pre == k)
			{
				count++;
				--pre;
			}
			while(*next == k)
			{
				count++;
				++next;
			}
			return count;
		}

    }
};