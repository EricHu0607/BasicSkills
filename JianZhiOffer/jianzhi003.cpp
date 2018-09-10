/*
003 二维数组中的查找

在一个二维数组中（每个一维数组的长度相同），每一行都按照从左到右递增的顺序排序，
每一列都按照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个整数
，判断数组中是否含有该整数。
*/

/*
分析：可以从左下角或者右上角开始，此时每次都可以移动一列
*/
#include <vector>
using namespace std;

class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
		
		if(array.empty())
			return false;

		int row = array.size();        
		int column = array[0].size();

		int i,j;
		for( i = row - 1, j = 0; (i >= 0) && (j < column);)
		{
			//目标值大于左下角值，右移
			if(target > array[i][j])
				j++;
			else if(target == array[i][j])
				return true;
			else
				i--;

		}
		return false;
	
    }
};