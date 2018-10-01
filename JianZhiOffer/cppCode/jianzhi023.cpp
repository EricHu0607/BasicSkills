/*
023 栈的压入、弹出序列
题目描述
输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否可能为该栈的弹出顺序。
假设压入栈的所有数字均不相等。例如序列1,2,3,4,5是某栈的压入顺序，序列4,5,3,2,1是该压栈
序列对应的一个弹出序列，但4,3,5,1,2就不可能是该压栈序列的弹出序列。
（注意：这两个序列的长度是相等的）
*/

/*
分析：通过一个栈来模拟栈的压入弹出。
*/
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
		
		if(pushV.empty())
			return true;

		int len = popV.size();
		stack<int> st;
		st.push(pushV[0]);
		//i控制pushV，j控制popV
		for(int i=1,j=0; j < len; )
		{
			//若st的栈顶和出栈元素不同，继续入栈/超过len返回失败
			if(st.top() != popV[j])
			{
				if( i< len)
				{
					st.push(pushV[i]);
					i++;
					continue;
				}
				else
					return false;
			}
			//若相同，则出栈/栈空返回失败	
			else
			{
				if(st.empty())
					return false;
				else
				{
					cout<< st.top() << " ";
					st.pop();
					j++;
				}
			}
		}
		return true;
    }

};