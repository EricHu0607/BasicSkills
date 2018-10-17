/*
034 把数组排成最小的数

题目描述
输入一个正整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。
例如输入数组{3，32，321}，则打印出这三个数字能排成的最小数字为321323。
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string PrintMinNumber(vector<int> numbers) {
		int len = numbers.size();
		string sTmp,sMin;
		sort(numbers.begin(), numbers.end());

		for(int i = 0; i < len; i++)
			sTmp.push_back(numbers[i]);
		sMin = sTmp;
		next_permutation(numbers.begin(), numbers.end());
		do
		{
			sTmp.clear();
			for(int i = 0; i < len; i++)
				sTmp.push_back(numbers[i]);
			if(sTmp < sMin)
				sMin = sTmp;
		}
		while(next_permutation(numbers.begin(), numbers.end()));
		return sMin;

    }

private:
	int lenInt(int n)
	{
		int len = 0;
		while(n)
		{
			len++;
			n /= 10;
		}
		return n;
	}
};