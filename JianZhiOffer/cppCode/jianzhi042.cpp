/*
042 数组中只出现一次的数字

题目描述
一个整型数组里除了两个数字之外，其他的数字都出现了偶数次。请写程序找出这两个只出现一次的数字。
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
		unordered_map<int, int> hash;
		unordered_map<int, int>::iterator it;
		int len = data.size();
		for(int i = 0; i < len; i++)
		{
			hash[data[i]]++;
		}
		for(it = hash.begin();it != hash.end(); it++)
		{
			if(it->second == 1)
			{
				if(*num1 == 0)
				{
					*num1 = it->first;
					continue;
				}
				if(*num2 == 0)
				{
					*num2 = it->first;
					continue;
				}
			}
		}
    }
};