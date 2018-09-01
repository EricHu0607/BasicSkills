/*
141. Linked List Cycle

Given a linked list, determine if it has a cycle in it.

Follow up:
Can you solve it without using extra space?
*/
/*
分析：此题可以使用跑步的思想去解题。一个指针快，每次步长为2，另一个指针慢，每次步长为1。
      如果快追上慢的指针，表示有环，若快遇到null，表示无环。
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
    bool hasCycle(ListNode *head) {
   
		ListNode* slow = head;
		ListNode* quick = head;
		while(quick)
		{
			if(quick->next == nullptr || quick->next->next == nullptr)
				return false;
            slow = slow->next;
			quick = quick->next->next;
			//有环
			if(quick == slow)
				return true;
		}
		return false;
    }
};