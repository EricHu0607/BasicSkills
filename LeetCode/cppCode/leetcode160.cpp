/*
160. Intersection of Two Linked Lists
*/

//1.先统计LA,LB的长度
//2.将长的链表先偏移|LA-LB|的距离，为curNew
//3.再次遍历curNew和另一个链表head，当相同时，即为入口
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};
class Solution {
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		if (!headA || !headB)
			return nullptr;

		//计算LA，LB长度
		ListNode* curA = headA, *curB = headB;
		int lenA = 1, lenB = 1;
		while (curA->next)
		{
			++lenA;
			curA = curA->next;
		}
		while (curB->next)
		{
			++lenB;
			curB = curB->next;
		}

		//最后一个节点不同，则不相交
		if (curA != curB)
			return nullptr;

		//偏移较长的链表
		curA = headA;
		curB = headB;
		if (lenA < lenB)
		{
			int offset = lenB - lenA;
			while ((offset--) > 0)
				curB = curB->next;
		}
		else
		{
			int offset = lenA - lenB;
			while ((offset--) > 0)
				curA = curA->next;
		}

		//找到两链表入口
		while (curA && curB)
		{
			if (curA == curB)
				return curA;
			curA = curA->next;
			curB = curB->next;
		}

		return nullptr;
	}
};