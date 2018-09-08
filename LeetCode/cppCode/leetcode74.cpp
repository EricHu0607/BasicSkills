/*
74. Search a 2D Matrix
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
Example 1:

Input:
matrix = [
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
target = 3
Output: true
Example 2:

Input:
matrix = [
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
target = 13
Output: false
*/

/*
分析： 以左下角为基准：若目标值大于该基准，列右移；若目标值小于该基准，列上移。
	   以右上角为基准也是同理。
*/
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
      	if(matrix.empty())
			return false;

		int row = matrix.size();        
		int column = matrix[0].size();

		int i,j;
		for( i = row - 1, j = 0; (i >= 0) && (j < column);)
		{
			//目标值大于左下角值，右移
			if(target > matrix[i][j])
				j++;
			else if(target == matrix[i][j])
				return true;
			//目标值小于左下角值，上移
			else
				i--;

		}
		return false;
	
    }
};