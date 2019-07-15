/*
83. Remove Duplicates from Sorted List
*/
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		if (!head)
		{
			return head;
		}

		ListNode* cur, *next, *n_next;
		cur = head;
		while (cur)
		{
			next = cur->next;
			//去重
			while (next && cur->val == next->val)
			{
				n_next = next->next;
				delete next;
				next = n_next;
			}
			//去重过程中断开了链表，需要重新链接
			cur->next = next;
			cur = cur->next;
		}
		return head;
	}
};