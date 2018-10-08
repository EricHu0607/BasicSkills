/*
030 数组中出现次数超过一半的数字

题目描述
数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。由于数字2在数组中出现了5次，
超过数组长度的一半，因此输出2。如果不存在则输出0。
*/

/*
分析：利用map来存放每个数字的出现频率，遍历map，返回大于数组长度一半的值即可。
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
		
		unordered_map<int, int> fMap;
		int len = numbers.size();

		for(int i = 0; i < len; i++)
		{
			fMap[ numbers[i] ]++;
		}

		int half = len / 2;
		for(unordered_map<int, int>::iterator it = fMap.begin(); it != fMap.end(); it++)
		{
			if(it->second > half)
				return it->first;
		}
		return 0;
    }
};