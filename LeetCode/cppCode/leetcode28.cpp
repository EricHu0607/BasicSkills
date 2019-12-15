/*
28. Implement strStr()

Implement strStr().

Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Example 1:

Input: haystack = "hello", needle = "ll"
Output: 2
Example 2:

Input: haystack = "aaaaa", needle = "bba"
Output: -1
Clarification:

What should we return when needle is an empty string? This is a great question to ask during an interview.

For the purpose of this problem, we will return 0 when needle is an empty string. This is consistent to C's strstr() and Java's indexOf().
*/
/*
字符串匹配
方法一：直接暴力遍历，匹配字符串，BF算法
方法二：在方法一的基础上，改用hash值求解，若用26进制来表示，hash值不会有冲突，但是会溢出int long，
可以采用其他hashRK算法
方法三：采用BM算法，坏字符和好后缀原则
下面采用方法二求解。
*/

#include <string>
using namespace std;

class Solution {
public:
	int strStr(string haystack, string needle) {
		if (needle.size() == 0)
		{
			return 0;
		}
		if (haystack.size() < needle.size())
			return -1;
		
		//计算needle的hash值
		int hash_needle = 0, hash_match = 0;
		for (int i = 0; i < needle.size(); i++)
		{
			hash_needle += needle[i] - 'a';
			hash_match += haystack[i] - 'a';
		}
		
		//找到第一个匹配的下标，采用求和的方式来算hash值，若存在，比较原字符串
		int i = 0;
		do
		{
			//若hash值
			if ((hash_needle == hash_match) && !haystack.substr(i, needle.size()).compare(needle))
			{
				return i;
			}
			if (i + needle.size() == haystack.size())
			{
				break;
			}
			//下一个hash_match =（hash_match - 最高位的权重 * 值 ） * 26 + 下一位对应的值
			hash_match = hash_match - (haystack[i] - 'a') + (haystack[i + needle.size()] - 'a');
			i++;
		} while (i <= (haystack.size() - needle.size()));
		return -1;
	}
};