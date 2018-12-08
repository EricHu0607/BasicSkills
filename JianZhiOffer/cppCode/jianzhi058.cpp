/*
058 删除链表中重复的结点

题目描述
在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，重复的结点不保留，返回链表头指针。
例如，链表1->2->3->3->4->4->5 处理后为 1->2->5
*/

#include<iostream>
using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :val(x), next(NULL) {
	}
};
class Solution {
public:
	ListNode* deleteDuplication(ListNode* pHead)
	{
		ListNode* first = new ListNode(-1);
		first->next = pHead;
		ListNode* last, *cur, *tmp_Node;
		last = cur = first;
		int tmp_val;
		while (cur && cur->next)
		{
			//如有重复
			if (cur->val == cur->next->val)
			{
				tmp_val = cur->val;//暂存值
				while (cur && cur->val == tmp_val)
				{
					tmp_Node = cur;
					cur = cur->next;
					delete(tmp_Node);//删除重复值
				}
				last->next = cur;//跳过重复值部分
			}
			else
			{
				last = cur;
				cur = cur->next;
			}
		}
		return first->next;
	}
};