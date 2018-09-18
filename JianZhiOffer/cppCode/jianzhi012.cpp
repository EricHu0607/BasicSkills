/*
012 矩形覆盖
题目描述

我们可以用2*1的小矩形横着或者竖着去覆盖更大的矩形。
请问用n个2*1的小矩形无重叠地覆盖一个2*n的大矩形，总共有多少种方法？
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int rectCover(int number) {
		vector<int> dp(number);
		switch (number)
		{
		case 0: 
			return 0;
		case 1:
			return 1;
		case 2:
			return 2;
		default:
			dp[0] = 1;
			dp[1] = 2;
			for(int i = 2; i < number; i++)
				dp[i] = dp[i-1] + dp[i-2];
			return dp[number-1];
		}
    }
};