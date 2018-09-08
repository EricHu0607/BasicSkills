/*

19. Remove Nth Node From End of List

Given a linked list, remove the n-th node from the end of list and return its head.

Example:

Given linked list: 1->2->3->4->5, and n = 2.

After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:

Given n will always be valid.

Follow up:

Could you do this in one pass?
给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。

示例：

给定一个链表: 1->2->3->4->5, 和 n = 2.

当删除了倒数第二个节点后，链表变为 1->2->3->5.
说明：

给定的 n 保证是有效的。

进阶：

你能尝试使用一趟扫描实现吗？
*/
/*
分析：可以通过两个指针，来实现一次遍历。其中两个指针的步长为n，
	  当sec到达链表末尾，fir刚好到达倒数第n个点，删除结点即可。
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
		ListNode* fir;
		ListNode* sec;
		//构造头指针，用来指向第一个结点。
		ListNode tmp(0);
		tmp.next = head;
		head = &tmp;
		fir = sec = head;

		for(int i=0; i<n; ++i)
			sec = sec->next;

		while(sec->next)
		{
			fir = fir->next;
			sec = sec->next;
		}

		//删除倒数第N个结点
		fir->next = fir->next->next;
		return head;
    }
};