/*
LeetCode6 ZigZag
将一个给定字符串根据给定的行数，以从上往下、从左到右进行 Z 字形排列。

比如输入字符串为 "LEETCODEISHIRING" 行数为 3 时，排列如下：

L   C   I   R
E T O E S I I G
E   D   H   N
之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如："LCIRETOESIIGEDHN"。

请你实现这个将字符串进行指定行数变换的函数：

string convert(string s, int numRows);
示例 1:

输入: s = "LEETCODEISHIRING", numRows = 3
	输出 : "LCIRETOESIIGEDHN"
	示例 2 :

	输入 : s = "LEETCODEISHIRING", numRows = 4
	输出 : "LDREOEIIECIHNTSG"
	解释 :

	L     D     R
	E   O E   I I
	E C   I H   N
	T     S     G
*/
/*
我们按层打印时，输出字符串每一层对应原字符串产生的偏移，在同一层，共有两种偏移方式
2 * (numRows - nowRows - 1),2 * (numRows - 1) - 2 * (numRows - nowRows - 1)
根据上述进行步长控制输出。
*/
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	string convert(string s, int numRows) {

		int step[2], len = s.size();
		string res;
		//单层的直接返回
		if (numRows == 1)
			return s;
		int maxStep = 2 * (numRows - 1);
		for (int nowRows = 0; nowRows < numRows; nowRows++)
		{
			int pos = nowRows;
			//控制每层的步进
			step[0] = 2 * (numRows - nowRows - 1);
			step[1] = maxStep - step[0];
			int control = 0, tmpPos;//控制两种步数的切换，临时位置存储
			while (true)
			{
				res += s[pos];
				//对跳跃步数进行控制
				while (true)
				{
					tmpPos = pos;
					pos += step[control % 2];
					control++;
					if (pos != tmpPos)
						break;
				}
				if (pos >= len)
					break;
			}
		}
		return res;
	}
};