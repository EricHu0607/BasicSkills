/*
206. Reverse Linked List
*/
using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
	ListNode* reverseList(ListNode* head) {

		ListNode* pre = nullptr, *cur, *next;
		cur = head;
		while (cur)
		{
			next = cur->next;
			cur->next = pre;
			pre = cur;
			cur = next;
		}
		return pre;
	}
};