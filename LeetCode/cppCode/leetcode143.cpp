/*
143. Reorder List
*/

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
	void reorderList(ListNode* head) {
		//0、1、2 nodes processing
		if (!head || !head->next || !head->next->next)
			return;

		ListNode* slow = head, *fast = head;
		while (fast->next && fast->next->next)
		{
			slow = slow->next;
			fast = fast->next->next;
		}

		//reverse L2 then compose L1 with L2
		ListNode* curL1, *curL2, *nextL1, *nextL2;
		curL2 = slow->next;
		slow->next = nullptr;
		curL2 = reverseList(curL2);
		curL1 = head;

		while (curL2)
		{
			nextL1 = curL1->next;
			nextL2 = curL2->next;
			curL1->next = curL2;
			curL2->next = nextL1;
			curL1 = nextL1;
			curL2 = nextL2;
		}
	}

	//head：链表头节点
	//返回值：倒置链表的头节点
	ListNode* reverseList(ListNode* head)
	{
		if (!head)
			return nullptr;

		ListNode* cur = head, *next;
		ListNode* fakeHead = new ListNode(-1);
		//倒置链表
		while (cur)
		{
			next = cur->next;
			cur->next = fakeHead->next;
			fakeHead->next = cur;
			cur = next;
		}
		cur = fakeHead->next;
		delete fakeHead;
		return cur;
	}
};