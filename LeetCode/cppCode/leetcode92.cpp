/*
92. Reverse Linked List II
*/
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
	ListNode* reverseBetween(ListNode* head, int m, int n) {
		//链表为空，或m >= n时，返回原始链表
		if (!head || m >= n)
		{
			return head;
		}

		ListNode* fake_head = new ListNode(0);
		fake_head->next = head;
		ListNode* cur = fake_head, *next, *pre = nullptr;
	
		//pre_start_pos指向第m-1节点，start_pos指向第m节点,end_pos,指向第n节点
		ListNode* pre_start_pos, *start_pos, *end_pos;
		for (int i = 0; i < m - 1; i++)
		{
			cur = cur->next;
		}

		pre_start_pos = cur;
		start_pos = cur->next;
		cur = start_pos;

		//倒置m到n之间的节点,退出循环时，cur指向n+1
		int count = n - m + 1;
		for (int i = 0; i < count; i++)
		{
			next = cur->next;
			cur->next = pre;
			pre = cur;
			cur = next;
		}
		end_pos = pre;

		//重新组装链表
		pre_start_pos->next = end_pos;
		start_pos->next = cur;

		return fake_head->next;
	}
};