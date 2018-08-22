/*
100. Same Tree

Given two binary trees, write a function to check if they are the same or not.

Two binary trees are considered the same if they are structurally identical and the nodes have the same value.

Example 1:

Input:     1         1
          / \       / \
         2   3     2   3

        [1,2,3],   [1,2,3]

Output: true
Example 2:

Input:     1         1
          /           \
         2             2

        [1,2],     [1,null,2]

Output: false
Example 3:

Input:     1         1
          / \       / \
         2   1     1   2

        [1,2,1],   [1,1,2]

Output: false

给定两个二叉树，编写一个函数来检验它们是否相同。

如果两个树在结构上相同，并且节点具有相同的值，则认为它们是相同的。

*/
/*
本题可以用多种方法来解:
	先序遍历，中序遍历，后序遍历，层次遍历。
*/

#include <iostream>
#include <queue>
using namespace std;

 // Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

class Solution {
	
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {

		queue<TreeNode* > queueP,queueQ;
		queueP.push(p),queueQ.push(q);

		TreeNode* cur1;
		TreeNode* cur2;

		while(!queueP.empty() && !queueQ.empty())
		{
			cur1 = queueP.front();
			cur2 = queueQ.front();

			queueP.pop(),queueQ.pop();
			//两个都为空，则继续
			if(!cur1 && !cur2)
				continue;
			//其中一个为空，另一个不为空，不成立
			if(!cur1 || !cur2)
				return false;
			//结点值不同，不成立
			if(cur1->val != cur2->val)
				return false;

			queueP.push(cur1->left);
			queueP.push(cur1->right);
			queueQ.push(cur2->left);
			queueQ.push(cur2->right);
		}
		return true;
    }
};