/*

203. Remove Linked List Elements

Remove all elements from a linked list of integers that have value val.

Example:

Input:  1->2->6->3->4->5->6, val = 6
Output: 1->2->3->4->5
*/

/*
分析：构造一个头结点，进行遍历链表删除对应的val结点操作。
*/

#include <iostream>
using namespace std;

// Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
 ListNode* fakeHead = new ListNode(0);
		fakeHead->next = head;
		
		ListNode* tmp = fakeHead;
		while(tmp->next)
		{
			if(tmp->next->val == val)
			{
				ListNode* delNode = tmp->next;
				tmp->next = (tmp->next->next) == nullptr ? nullptr : tmp->next->next;
				delete delNode;
				continue;
			}

			tmp = tmp->next;
		}
		return fakeHead->next;
    }
};