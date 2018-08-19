/*
42. Trapping Rain Water

Given n non-negative integers representing an elevation map where the width of each bar is 1, 
compute how much water it is able to trap after raining.

给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。
上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，
可以接 6 个单位的雨水（蓝色部分表示雨水）。 感谢 Marcos 贡献此图。

输入: [0,1,0,2,1,0,1,3,2,1,2,1]
输出: 6
*/

/*
分析:此题可以通过动态规划来处理，跟常规的模式有点不同。
	对一个i来说，蓄水是左边最高-当前i的高，或者是右边最高-当前i的高。
	由于蓄水是根据最低的长度为准，所以有min（左边最高，右边最高）-height[i];

	记：dpf[i]为i左边最大高度，dpe[i]为i右边最大高度
	故有i处的蓄水量=min(dpf[i-1], dpe[i+1])-height[i]（要为正，才代表能蓄水）

例：
height    0,1,0,2,1,0,1,3,2,1,2,1
dpf       0 1 1 2 2 2 2 3 3 3 3 3
dpe       3 3 3 3 3 3 3 3 2 2 2 1

i处蓄水值 0 0 1 0 1 2 1 0 0 1 0 0 = 6
*/

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {

		if(height.size() == 0 || height.size() == 1)
			return 0;

		int len = height.size();
		vector<int> dpf(len),dpe(len);

		//i的左部分最大
		dpf[0] = height[0];
		for(int i=1; i<len; ++i)
		{
			dpf[i] = max(height[i], dpf[i-1]);  
		}

		//i的右部分最大
		dpe[len-1] = height[len-1];
		for(int i=len-2; i>=0 ;--i)
		{
			dpe[i] = max(height[i], dpe[i+1]);
		}

		//求最大蓄水
		int maxPool=0;
		for(int i = 1; i<len-1; ++i)
		{
			int minTmp = min(dpf[i-1], dpe[i+1]);
			if( minTmp > height[i])
				maxPool += minTmp - height[i];
		}

		return maxPool;
    }
};