/*
23. Merge k Sorted Lists    
*/
/*
采用分治法的思想，合并K个链表，类似归并排序，两个链表合并的
时间复杂度为O(n)，并上递归的时间复杂度O(logk)，总的时间复杂度为
O(nlogk)。其中k为链表个数，n为节点个数。空间复杂度为0(1)
*/

#include <vector>
using namespace std;

  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(nullptr) {}
  };
 
class Solution {
public:
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		if (lists.size() < 1)
		{
			return nullptr;
		}
		return __mergeKLists(lists, 0, lists.size() - 1);
	}

	//合并两个链表
	ListNode* __mergeTwoLists(ListNode* fir, ListNode* sec)
	{
		//对空链表的处理
		if (!fir)
		{
			return sec;
		}
		if (!sec)
		{
			return fir;
		}

		ListNode* fake_head = new ListNode(0);
		ListNode* cur = fake_head;
		//两个链表均不为空，合并
		while (fir && sec)
		{
			if (fir->val <= sec->val)
			{
				cur->next = fir;
				fir = fir->next;
			}
			else
			{
				cur->next = sec;
				sec = sec->next;
			}
			cur = cur->next;
		}

		//对有空余的表合并。
		if (fir)
		{
			cur->next = fir;
		}
		if (sec)
		{
			cur->next = sec;
		}

		return fake_head->next;
	}

	//采用分治法，递归合并lists
	ListNode* __mergeKLists(vector<ListNode*>& lists, int left, int right)
	{
		if (left > right)
		{
			return nullptr;
		}
		else if (left == right)
		{
			return lists[left];
		}

		int mid = left + ((right - left) >> 1);

		return __mergeTwoLists(__mergeKLists(lists, left, mid),
				__mergeKLists(lists, mid+1, right));
	}
};