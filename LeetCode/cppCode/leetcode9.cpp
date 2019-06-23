/*
9. Palindrome Number
*/

#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
	bool isPalindrome(int x) {
		//转成字符串
		string palindStr = to_string(x);
		int left = 0, right = palindStr.size() - 1;
		//通过左右index移动判断
		while (left < right)
		{
			if (palindStr[left] != palindStr[right])
				return false;
			left++;
			right--;
		}
		return true;
	}
};