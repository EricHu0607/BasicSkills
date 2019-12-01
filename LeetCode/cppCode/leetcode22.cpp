/*
22. Generate Parentheses
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]
*/
/*
解题思路：回溯法
控制传入的string cur， 左括号数 left < n，右括号数 right < left，进行回溯
*/
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	vector<string> generateParenthesis(int n) {
		vector<string> res;
		string cur = "";
		backtrace(res, cur, 0, 0, n);
		return res;
	}
	/*
	In params:
				res:返回满足条件的括号序列
				cur:当前回溯时的括号序列
				left:当前左括号个数
				right:当前右括号个数
				max:总的括号对个数
	*/
	void backtrace(vector<string>& res, string cur, int left, int right, int max)
	{
		//找到满足条件的括号序列
		if (cur.size() == (max << 1))
		{
			res.push_back(cur);
			return;
		}
		//左括号个数小于总括号个数，添加左括号
		if (left < max)
		{
			backtrace(res, cur+"(", left + 1, right, max);
		}
		//右括号个数小于左括号个数时，添加右括号
		if (right < left)
		{
			backtrace(res, cur+")", left, right + 1, max);
		}
	}
};