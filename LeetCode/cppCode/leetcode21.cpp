/*
21. Merge Two Sorted Lists
*/

using namespace std;

  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(nullptr) {}
  };
 
class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

		ListNode* dummyHead = new ListNode(0);
		ListNode* curNode = dummyHead;
		//对l1与l2合并，直到其中一个为空
		while (l1 != nullptr && l2 != nullptr)
		{
			if (l1->val <= l2->val)
			{
				curNode->next = l1;
				l1 = l1->next;
			}
			else
			{
				curNode->next = l2;
				l2 = l2->next;
			}
			curNode = curNode->next;
		}
		//对剩下来的l1或l2结点进行连接
		if (l1 != nullptr)
			curNode->next = l1;
		if (l2 != nullptr)
			curNode->next = l2;

		return dummyHead->next;
	}
};