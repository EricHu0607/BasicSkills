/*
007 用两个栈实现队列

用两个栈来实现一个队列，完成队列的Push和Pop操作。 队列中的元素为int类型。
*/

/*
分析：第一个栈用来存值，用于存放输入数据；在模仿出队的时候，利用第二个将第一个栈倒置，
	  此时，栈顶元素就是出队的值。出队之后恢复栈一和栈二状态。可以根据栈的作用来优化
	  算法。例如：以入队为主的队，还是以出对为主的对。

思路2：始终维护s1作为输入栈，以s2作为输出栈

1.入队时，将元素压入s1。

2.出队时，判断s2是否为空，如不为空，则直接弹出顶元素；
如为空，则将s1的元素逐个“倒入”s2，把最后一个元素弹出并出队。
这个思路，避免了反复“倒”栈，仅在需要时才“倒”一次。
*/

#include <iostream>
#include <stack>
using namespace std;

class Solution
{
public:
    void push(int node) {
		stack1.push(node);        
    }

    int pop() {
		if(stack1.empty())
			return -1;
		//第一个栈用来存储数据，转存到第二个栈中，栈顶就是要出栈的值
		while(!stack1.empty())
		{
			stack2.push(stack1.top());
			stack1.pop();
		}
		int ret = stack2.top();
		stack2.pop();
		//恢复到第一个栈
		while(!stack2.empty())
		{
			stack1.push(stack2.top());
			stack2.pop();
		}
		return ret;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};