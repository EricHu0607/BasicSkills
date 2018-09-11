/*
从尾到头打印链表
题目描述
输入一个链表，按链表值从尾到头的顺序返回一个ArrayList。
*/

/*
分析：用空间换时间，保证时间复杂度为O(n),可以利用栈，实现倒序。
*/
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

 struct ListNode {
        int val;
        struct ListNode *next;
        ListNode(int x) :
              val(x), next(NULL) {
        }
  };

class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
		if(!head) return vector<int> ();

		stack<int> tmp_stack;
		for(ListNode* cur = head; cur != nullptr; )
		{
			tmp_stack.push(cur->val);
            cur = cur->next;
		}
		//静态开辟空间
		vector<int> res(tmp_stack.size());

		for(int i = 0;!tmp_stack.empty(); ++i)
		{
			res[i] = tmp_stack.top();
			tmp_stack.pop();
		}
		return res;
    }
};