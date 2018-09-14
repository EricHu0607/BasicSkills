/*
004 替换空格
请实现一个函数，将一个字符串中的每个空格替换成“%20”。
例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。
*/

/*
分析：使用一个buffer_string 来存新字符串，若遇到空格，则插入%20，反之插入原数。
*/
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
	void replaceSpace(char *str,int length) {
		if(!str) return;
		string s;
		for(int i = 0; i < length; i++)
		{
			if(str[i] == ' ')
			{
				s.insert(s.end(), '%');
				s.insert(s.end(), '2');
				s.insert(s.end(), '0');

			}
			else
				s.insert(s.end(), str[i]);

		}
		strcpy(str, s.data());
		cout<< s;
	}
};