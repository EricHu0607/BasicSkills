/*
20. Valid Parentheses
*/
/*
通过stack来控制匹配，'(', '{', '['直接存入stack，
遇到‘)’，‘}’，‘]’，对stack的顶部元素进行匹配
*/
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
	bool isValid(string s) {
		stack<char> matchSt;
		for (int i = 0; i < s.size(); i++)
		{
			switch (s[i])
			{
			case '(':
			case '{':
			case '[':
				matchSt.push(s[i]);
				break;
			case ')':
				if (!matchSt.empty() && matchSt.top() == '(')
				{
					matchSt.pop();
					break;
				}
				else
					return false;
			case '}':
				if (!matchSt.empty() && matchSt.top() == '{')
				{
					matchSt.pop();
					break;
				}
				else
					return false;
			case ']':
				if (!matchSt.empty() && matchSt.top() == '[')
				{
					matchSt.pop();
					break;
				}
				else
					return false;
			default:
				break;
			}
		}
		if (matchSt.empty())
			return true;
		else
			return false;
	}
};