/*
016 链表中倒数第k个结点
题目描述

输入一个链表，输出该链表中倒数第k个结点。
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
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
		
		ListNode* fast = pListHead;
		ListNode* slow = pListHead;

		while(k != 0)
		{
			if(fast == nullptr) return nullptr;
			fast = fast->next;
			k--;
		}

		while(fast != nullptr)
		{
			fast = fast->next;
			slow = slow->next;
		}
		return slow;
    }
};