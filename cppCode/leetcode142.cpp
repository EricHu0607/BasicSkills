/*
142. Linked List Cycle II
Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

Note: Do not modify the linked list.

Follow up:
Can you solve it without using extra space?
*/

/*
分析：此题可以使用跑步的思想去解题。一个指针快，每次步长为2，另一个指针慢，每次步长为1。
      如果快追上慢的指针，表示有环，若快遇到null，表示无环。此时慢的指针与头刚好相聚一圈，
	  所以当从head开始的指针与slow的指针步长为1，再次相聚时，为入口点。
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
    ListNode *detectCycle(ListNode *head) {
		ListNode* slow = head;
		ListNode* quick = head;
		while(quick)
		{
			if(quick->next == nullptr || quick->next->next == nullptr)
				return nullptr;
            slow = slow->next;
			quick = quick->next->next;
			//有环
			if(quick == slow)
			{
				//找入环扣
				ListNode* tmp = head;
				while(tmp != slow)
				{
					slow = slow->next;
					tmp = tmp->next;
				}
				return slow;
			}
		}
		return nullptr;
    }
};