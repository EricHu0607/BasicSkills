/*
015 调整数组顺序使奇数位于偶数前面

题目描述
输入一个整数数组，实现一个函数来调整该数组中数字的顺序，
使得所有的奇数位于数组的前半部分，所有的偶数位于数组的后半部分，
并保证奇数和奇数，偶数和偶数之间的相对位置不变。
*/

/*
分析：利用两个数组来保证稳定性，奇数数组和偶数数组，存完之后再恢复到原数组中。
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void reOrderArray(vector<int> &array) {
		if(array.empty()) return;

		vector<int> oddArr,evenArr;
		int len = array.size();
		for(int i = 0; i < len; i++)
		{
			if(array[i] & 1 == 1)
				oddArr.push_back(array[i]);
			else
				evenArr.push_back(array[i]);
		}
		int index = 0, lenOdd = oddArr.size(), lenEven = evenArr.size();
		for(int i = 0; index < len && i < lenOdd; i++,index++)
			array[index] = oddArr[i];
		for(int i = 0; index < len && i < lenEven; i++,index++)
			array[index] = evenArr[i];
    }
};