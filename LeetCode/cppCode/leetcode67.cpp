/*
67. Add Binary

Given two binary strings, return their sum (also a binary string).

The input strings are both non-empty and contains only characters 1 or 0.

Example 1:

Input: a = "11", b = "1"
Output: "100"
Example 2:

Input: a = "1010", b = "1011"
Output: "10101"

给定两个二进制字符串，返回他们的和（用二进制表示）。

输入为非空字符串且只包含数字 1 和 0。

示例 1:

输入: a = "11", b = "1"
输出: "100"
示例 2:

输入: a = "1010", b = "1011"
输出: "10101"
*/

/*
分析：二进制求和。可以利用10进制求和方法，利用一个进位来保存。
*/
#include <string>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        
		int carry = 0;
		int len1 = a.size();
		int len2 = b.size();
		string res;
		//求a+b
		while(len1 > 0 || len2 > 0)
		{
			int ab = len1 <= 0 ? 0 : a[len1-1] - '0';
			int bb = len2 <= 0 ? 0 : b[len2-1] - '0';
			res.insert(res.begin(), ((ab + bb + carry) % 2) + '0');
			carry = (ab + bb + carry) / 2;
			--len1,--len2;
		}
		//处理最后进位
		if(carry)
			res.insert(res.begin(), '1' );
		return res; 

    }
};