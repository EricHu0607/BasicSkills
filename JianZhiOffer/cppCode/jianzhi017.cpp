/*
017 反转链表
题目描述
输入一个链表，反转链表后，输出新链表的表头。
*/

/*
分析：curNode,nextNode两个结点，只需要将nextNode->next = curNode，遍历整个链表即可。 
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
    ListNode* ReverseList(ListNode* pHead) {

		ListNode* fakeHead = new ListNode(0);
		ListNode* tmp;
		while(pHead)
		{
			tmp = pHead;
			pHead = pHead->next;
			tmp ->next = fakeHead->next; 
			fakeHead->next = tmp;
		}
		return fakeHead->next;

    }
};