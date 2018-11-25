/*
057 链表中环的入口结点

题目描述
给一个链表，若其中包含环，请找出该链表的环的入口结点，否则，输出null。
*/

#include <iostream>
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
	ListNode* EntryNodeOfLoop(ListNode* pHead)
	{
		ListNode* slow, *fast;
		
		slow = fast = pHead;
		//快指针后两个结点为空
		while (fast->next && fast->next->next)
		{
			slow = slow->next;
			fast = fast->next->next;
			if (slow == fast)
			{
				//表示有环
				break;
			}
		}

		//无环
		if (!fast->next || !fast->next->next)
		{
			return nullptr;
		}

		//求环长度
		int lenCir = 0;
		do
		{
			slow = slow->next;
			lenCir++;
		} while (fast != slow);

		//fast-slow为环长，当两者相遇时，就为环入口点。
		slow = fast = pHead;
		for (int i = 0; i < lenCir; i++)
			fast = fast->next;
		while (slow != fast)
		{
			slow = slow->next;
			fast = fast->next;
		}
		return slow;
	}
};