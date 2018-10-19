/*
036 第一个只出现一次的字符

题目描述
在一个字符串(0<=字符串长度<=10000，全部由字母组成)中找到第一个只出现一次的字符,
并返回它的位置, 如果没有则返回 -1（需要区分大小写）.
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        
		unordered_map<char, int> store;
		int len = str.size();
		for(int i = 0; i < len; i++)
		{
			store[str[i]]++;
		}
		for(int i = 0; i < len; i++)
		{
			if(store[str[i]] == 1)
				return i;
		}
		return -1;

    }
};