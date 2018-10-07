/*
029 字符串的排列

题目描述
输入一个字符串,按字典序打印出该字符串中字符的所有排列。例如输入字符串abc,
则打印出由字符a,b,c所能排列出来的所有字符串abc,acb,bac,bca,cab和cba。
*/

/*
分析：方法一：可以利用递归，每一次都交换当前值和后一个值，形成的就是下一个排列
	  方法二：可以利用STL提供的next_permutation()，来求得全排列。
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<string> Permutation(string str) {
		vector<string> res;
		if(str.empty())
			return res;

		sort(str.begin(), str.end());

		do
		{
			res.push_back(str);
		}
		while(next_permutation(str.begin(), str.end()));

		return res;
    }
};