/*
24. Swap Nodes in Pairs
*/
/*
利用分治的思想，原链表的头结点，在reverse之后，需要指向(len-k)的头节点，
因此，求解len，只需要求解len-k的子问题，以此类推，直到len<k。
每个子问题中只需要倒置k个节点即可。此题为2
*/

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
 
class Solution {
public:
	ListNode* swapPairs(ListNode* head) {

		int len = 0;
		ListNode* cur = head;
		while (cur)
		{
			cur = cur->next;
			++len;
		}
		return reverseKGroup(head, 2, len);

	}

	//利用分治法处理
	ListNode* reverseKGroup(ListNode* head, int k, int len)
	{
		//剩余为空，或者结点不够
		if (!head || len < k)
		{
			return head;
		}

		ListNode* cur, *next, *pre = nullptr;
		ListNode* tail = head;//原始头节点为新链表的尾节点

		cur = head;
		int count = 0;
		while (count < k)
		{
			//倒置节点
			next = cur->next;
			cur->next = pre;
			pre = cur;
			cur = next;
			
			++count;
		}

		//最终的cur为剩余链表的头节点
		tail->next = reverseKGroup(cur, k, len - k);
		//最终的pre为新链表的头节点
		return pre;
	}
};