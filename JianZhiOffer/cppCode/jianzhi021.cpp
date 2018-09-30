/*
021 顺时针打印矩阵
题目描述

输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字，
例如，如果输入如下4 X 4矩阵： 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 
则依次打印出数字1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10.
*/

/*
分析：通过一个dir方向数组来控制右下左上的移动打印。通过status[][]二维数组
	  来控制访问状态，0未访问，1以访问。循环打印数组即可。
*/
#include <iostream>
#include <vector>
using namespace std;

int dir[4][2] = {
		{0,1},
		{1,0},
		{0,-1},
		{-1,0}
};
class Solution {

public:
   	vector<int> printMatrix(vector<vector<int> > matrix) {
		vector<int> res;
		if(matrix.empty())
			return res;
		int row = matrix.size(), col = matrix[0].size();
		vector<vector<int> > status(row, vector<int>(col));
	
		//cur用来顺时针移动
		int cur = 0, x=0, y=0, len = row * col;
		for(int i = 0; i < len; )
		{
			int tmpX = x + dir[cur][0];
			int tmpY = y + dir[cur][1];
			if(tmpY < col && tmpY >= 0 && tmpX < row && tmpX >= 0)
			{
				if(status[tmpX][tmpY] == 0)
				{
					status[x][y] = 1;
					res.push_back(matrix[x][y]);
					x = x + dir[cur][0];
					y = y + dir[cur][1];
					i++;
				}
				else
				{
					status[x][y] = 1;
					res.push_back(matrix[x][y]);
					cur = (cur + 1) % 4;
					x = x + dir[cur][0];
					y = y + dir[cur][1];
					i++;
				}
			}
			else
			{
				status[x][y] = 1;
				res.push_back(matrix[x][y]);
				cur =(cur + 1) % 4;
				x = x + dir[cur][0];
				y = y + dir[cur][1];
				i++;
			}
		}
		return res;
    }
};