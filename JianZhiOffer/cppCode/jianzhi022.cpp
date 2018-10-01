/*
022 包含min函数的栈

题目描述
定义栈的数据结构，请在该类型中实现一个能够得到栈中所含最小元素的min函数
（时间复杂度应为O（1））。
*/

/*
分析： 方法一：可以通过一个最小值栈和一个数据栈来控制实现。
	   方法二：通过最小值索引栈一个vector来存放数据，此种方法存储空间更小。
*/
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    void push(int value) {

		store.push_back(value);
		if(stMin.empty())
			stMin.push(0);
		else
		{
			if(value < store[stMin.top()])
				stMin.push(store.size() - 1);
		}
    }
    void pop() {
		//若弹出元素索引为最小值栈存放索引，则将最小值栈索引更新
		if((store.size() - 1) == stMin.top())
			stMin.pop();

		store.pop_back();
    }
    int top() {
		return *(store.end() - 1);
    }
    int min() {
		return store[stMin.top()];
    }

private:
	//存放最小值栈索引
	stack<int> stMin;
	//原始栈
	vector<int> store;
};