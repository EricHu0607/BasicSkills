/*
027 复杂链表的复制

题目描述
输入一个复杂链表（每个节点中有节点值，以及两个指针，一个指向下一个节点，
另一个特殊指针指向任意一个节点），返回结果为复制后复杂链表的head。
（注意，输出结果中请不要返回参数中的节点引用，否则判题程序会直接返回空）
*/
/*
分析：构造*random，传统暴力方法时间发杂度为O(n2)。可以利用map<旧结点地址，新结点地址>
		来维护映射表，以空间换时间。
*/
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};

class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        if(!pHead)
			return nullptr;

		RandomListNode* curNode = pHead;
		RandomListNode* newListHead = nullptr,*curNewNode = nullptr,*preNewNode = nullptr;
		//利用map，空间换时间。
		unordered_map<RandomListNode*, RandomListNode*> nodeMap;

		//第一次遍历，只复制链表next，不构造random
		while(curNode)
		{
			curNewNode = new RandomListNode(curNode->label);
			nodeMap[curNode] = curNewNode;
			curNode = curNode->next;
			if(!preNewNode)
			{
				newListHead = curNewNode;
			}
			else
			{
				preNewNode->next = curNewNode;
			}
			preNewNode = curNewNode;
		}

		curNewNode = newListHead;
		curNode = pHead;

		//更新RandomListNode*
		while(curNode && curNewNode)
		{
			curNewNode->random = nodeMap[curNode->random];
			curNode = curNode->next;
			curNewNode = curNewNode->next;
		}
		return newListHead;
    }
};