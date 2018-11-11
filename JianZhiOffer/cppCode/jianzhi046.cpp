/*
046 翻转单词顺序列
题目描述
牛客最近来了一个新员工Fish，每天早晨总是会拿着一本英文杂志，写些句子在本子上。
同事Cat对Fish写的内容颇感兴趣，有一天他向Fish借来翻看，但却读不懂它的意思。
例如，“student. a am I”。后来才意识到，这家伙原来把句子单词的顺序翻转了，
正确的句子应该是“I am a student.”。Cat对一一的翻转这些单词顺序可不在行，
你能帮助他么？
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string ReverseSentence(string str) {
             
		vector<string> strs(split(str, ' '));
		int len = strs.size();
		string res;
		for(int i = len - 1; i >= 0; i--)
		{
			res += strs[i];
			if(i != 0)
				res += " ";
		}
		return res;
    }

	const vector<string> split(string& str, char c)//split 方法，用来切割字符串
	{
		string buff;
		vector<string> res;
		int len = str.size();
		for(int i = 0; i < len; i++)
		{
			if(str[i] == c && buff != "")
			{
				res.push_back(buff);
				buff.clear();
			}
			else 
			{
				buff += str[i];
			}
		}
        res.push_back(buff);
		return res;
    }
};