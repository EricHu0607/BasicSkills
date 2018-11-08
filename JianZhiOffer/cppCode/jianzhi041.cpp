/*
041 平衡二叉树

题目描述
输入一棵二叉树，判断该二叉树是否是平衡二叉树。
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};

class Solution {
public:
    bool IsBalanced_Solution(TreeNode* pRoot) {
		
		
    }

	bool isBalancedTree(TreeNode* pRoot, int& depth)
	{
		if(!pRoot)
		{
			depth = 0;
			return true;
		}
		int tmpDepth1,tmpDepth2;
		isBalancedTree(pRoot->left, tmpDepth1);
		isBalancedTree(pRoot->right, tmpDepth2);
		if(abs(tmpDepth1 - tmpDepth2) <= 1)
		{
			depth = max(tmpDepth1, tmpDepth2) + 1;
			return 
		}
		return false;

	}
};