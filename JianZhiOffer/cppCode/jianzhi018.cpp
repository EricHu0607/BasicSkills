/*
018 合并两个排序的链表
题目描述

输入两个单调递增的链表，输出两个链表合成后的链表，当然我们需要合成后的链表满足单调不减规则。
*/

/*
分析：list1，list2采用归并的算法，list1的当前结点<list2的当前结点，将list1的当前结点移动到
	  新链表，反之移动list2。直到某个链表为空，再插入另一个链表的剩余结点。

*/

#include <iostream>
#include <vector>
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
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
		ListNode* fakeNode = new ListNode(0);
		ListNode* cur = fakeNode;
		while(pHead1 != nullptr && pHead2 != nullptr)
		{
			if(pHead1->val < pHead2->val)
			{
				cur->next = pHead1;
				cur = pHead1;
				pHead1 = pHead1->next;
			}
			else
			{
				cur->next = pHead2;
				cur = pHead2;
				pHead2 = pHead2->next;
			}
		}
		if(pHead1)
			cur->next = pHead1;
		if(pHead2)
			cur->next = pHead2;
		return fakeNode->next;
    }
};