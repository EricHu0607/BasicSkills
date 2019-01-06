/*
008 旋转数组的最小数字

把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。 
输入一个非减排序的数组的一个旋转，输出旋转数组的最小元素。
例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1。 
NOTE：给出的所有元素都大于0，若数组大小为0，请返回0。
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	//O(logn)
	int minNumberInRotateArray(vector<int> rotateArray) {

		int len = rotateArray.size();

		//空数组返回0
		if (len == 0)
			return 0;

		int left = 0, right = len - 1, mid;

		while (rotateArray[left] >= rotateArray[right])
		{
			//  如果前一个元素与后一个元素差一位,说明找到了最大最小的元素
			if (right - left == 1)
			{
				mid = right;
				break;
			}

			mid = (right + left) / 2;

			//  如果该中间元素位于前面的递增子数组，那么它应该大于或者等于第一个指针指向的元素
			if (rotateArray[mid] >= rotateArray[left])
			{
				left = mid;         
			}
			// 如果中间元素位于后面的递增子数组，那么它应该小于或者等于第二个指针指 向的元素
			else if (rotateArray[mid] <= rotateArray[right])
			{
				right = mid;        
			}
		}
		return rotateArray[mid];
	}


	/*
	//O(n)时间复杂度
    int minNumberInRotateArray(vector<int> rotateArray) {
     
		int len = rotateArray.size();

		//空数组返回0
		if (len == 0)
			return 0;

		int flag = rotateArray[0];

		for (int i = 1; i < len; i++)
		{
			if (rotateArray[i] < flag)
				return rotateArray[i];
		}

		return flag;
    }
	*/
};