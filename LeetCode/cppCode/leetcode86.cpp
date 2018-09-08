/*
86. Partition List

Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

Example:

Input: head = 1->4->3->2->5->2, x = 3
Output: 1->2->2->4->3->5
*/

/*
分析： 构造两个链表：第一个链表小于x的所有节点，第二个链表大于等于x的所有结点
	   最后再合并成一个节点即可。
*/

#include <iostream> 
using namespace std;

//Definition for singly-linked list.
 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

 class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
		ListNode* tmp = new ListNode(0);
		tmp->next = head;
		ListNode* part1End = new ListNode(0);
		ListNode* part2End = new ListNode(0);
		ListNode* part1Head = part1End;
		ListNode* part2Head = part2End;
		while(tmp->next)
		{
			//小于x的构成一组链表
           if(tmp->next->val < x)
			{
				part1End->next = tmp->next;
				tmp->next = tmp->next->next;
				part1End->next->next = nullptr;
				part1End = part1End->next;
			}
		   //大于等于x的构成一组链表
			else
			{
				part2End->next = tmp->next;
				tmp->next = tmp->next->next;
				part2End->next->next = nullptr;
				part2End = part2End->next;

			}
		}
		//链表1的最后结点指向链表2的头结点
		part1End->next = part2Head->next;
		return part1Head->next;
    }
};