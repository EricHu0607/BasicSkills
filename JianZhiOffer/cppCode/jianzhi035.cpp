/*
035 丑数

题目描述
把只包含质因子2、3和5的数称作丑数（Ugly Number）。例如6、8都是丑数，但14不是，
因为它包含质因子7。 习惯上我们把1当做是第一个丑数。求按从小到大的顺序的第N个丑数。
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int GetUglyNumber_Solution(int index) {
		//异常情况处理
		if(index <= 0)
			return 0;

		vector<int> arr(index);
		arr[0] = 1;

		int index2 = 0, index3 = 0, index5 = 0;
		int cur = 1;
		int minVal;
		//求下一个最小的丑数。
		while(cur < index)
		{
			minVal = minOfThree(arr[index2] * 2, arr[index3] * 3, arr[index5] * 5);
			if(minVal == arr[index2] * 2)
			{
				index2++;
			}
			if(minVal == arr[index3] * 3)
			{
				index3++;
			}
			if(minVal == arr[index5] * 5)
			{
				index5++;
			}
			arr[cur++] = minVal;
		}
		return arr[index - 1];
    }

private:
	int minOfThree(int a, int b, int c)
	{
		int tmp = (a < b ? a:b);
		return (tmp < c ? tmp : c);
	}
};