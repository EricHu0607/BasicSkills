/*
234. Palindrome Linked List
*/
//分为两个链表，倒置前半链表，然后一一判断是否相等即可。

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
	bool isPalindrome(ListNode* head) {
		//对链表长度0,1进行判断
		if (!head || !head->next)
			return true;
		//对链表长度2进行判断
		if (!head->next->next)
			return head->val == head->next->val ? true : false;

		//将链表分为两部分，使用快慢指针
		ListNode* slow = head, *fast = head;
		while (fast->next && fast->next->next)
		{
			slow = slow->next;
			fast = fast->next->next;
		}

		//对前半部分链表倒置，调整奇数节点链表
		ListNode *curL1, *curL2;
		curL2 = slow->next;
		slow->next = nullptr;
		curL1 = reverseList(head);
		//奇数节点
		if (!fast->next)
			curL1 = curL1->next;

		//判断两个链表是否对应相同，回文判断
		while (curL1 && curL2)
		{
			if (curL1->val != curL2->val)
				return false;
			curL1 = curL1->next;
			curL2 = curL2->next;
		}
		return true;
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
