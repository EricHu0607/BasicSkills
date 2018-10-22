/*
038 两个链表的第一个公共结点

题目描述
输入两个链表，找出它们的第一个公共结点。
*/

/*
分析: 右对齐两个链表，此时开始移动，判断第一个值相同的，就是第一个公共结点。
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
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        
		while(!pHead1 || !pHead2)
			return nullptr;
		
		int lenOne = lenList(pHead1), lenTwo = lenList(pHead2);

		//保持右对齐
		if(lenOne < lenTwo)
		{
			int dis = lenTwo - lenOne;
			while(dis)
			{
				dis--;
				pHead2 = pHead2->next;
			}
		}
		else
		{
			int dis = lenOne - lenTwo;
			while(dis)
			{
				dis--;
				pHead1 = pHead1->next;
			}
		}

		while(pHead1 && pHead2)
		{
			if(pHead1->val == pHead2->val)
				return pHead1;
			pHead1 = pHead1->next;
			pHead2 = pHead2->next;
		}
		return nullptr;
    }

private:
	int lenList(ListNode* pHead)
	{
		int len = 0;

		while(pHead)
		{
			len++;
			pHead = pHead->next;
		}

		return len;
	}
};