/*
61. Rotate List

Given a linked list, rotate the list to the right by k places, where k is non-negative.

Example 1:

Input: 1->2->3->4->5->NULL, k = 2
Output: 4->5->1->2->3->NULL
Explanation:
rotate 1 steps to the right: 5->1->2->3->4->NULL
rotate 2 steps to the right: 4->5->1->2->3->NULL
Example 2:

Input: 0->1->2->NULL, k = 4
Output: 2->0->1->NULL
Explanation:
rotate 1 steps to the right: 2->0->1->NULL
rotate 2 steps to the right: 1->2->0->NULL
rotate 3 steps to the right: 0->1->2->NULL
rotate 4 steps to the right: 2->0->1->NULL

给定一个链表，旋转链表，将链表每个节点向右移动 k 个位置，其中 k 是非负数。

示例 1:

输入: 1->2->3->4->5->NULL, k = 2
输出: 4->5->1->2->3->NULL
解释:
向右旋转 1 步: 5->1->2->3->4->NULL
向右旋转 2 步: 4->5->1->2->3->NULL
示例 2:

输入: 0->1->2->NULL, k = 4
输出: 2->0->1->NULL
解释:
向右旋转 1 步: 2->0->1->NULL
向右旋转 2 步: 1->2->0->NULL
向右旋转 3 步: 0->1->2->NULL
向右旋转 4 步: 2->0->1->NULL
*/

/*
分析：k（k<链表的长度）roate，即从倒数第k个结点开始为头结点，形成的循环链表。
	 所以找到倒数第k个结点，以及取到k % len，为余下一圈的结点。
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
    ListNode* rotateRight(ListNode* head, int k) {
		//空字符串特殊处理
		if(!head)
			return nullptr;
		//求链表长度，防止k过大，超过rotate一圈的长度。
        int len = 1;
		for(ListNode* tmp = head; tmp->next != nullptr; tmp = tmp->next)
			len++;
		int rotate = k % len;
		
		ListNode* retHead;
		ListNode* fir;
		ListNode* sec;
		fir = sec = head;

		//找到倒数第rotate循环点
		for(int i=0; i<rotate; ++i)
			sec = sec->next;

		while(sec->next)
		{
			fir = fir->next;
			sec = sec->next;
		}
		sec->next = head;
		retHead = fir->next;
		fir->next = nullptr;
			
		return retHead;
    }
};