/*
060 对称的二叉树

题目描述
请实现一个函数，用来判断一颗二叉树是不是对称的。注意，如果一个二叉树同此二叉树的镜像是同样的，
定义其为对称的。
*/

#include <iostream>
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
	bool isSymmetrical(TreeNode* pRoot)
	{
		if (!pRoot)//若为空树，返回tree
		{
			return true;
		}
		return isSymmetricalRec(pRoot->left, pRoot->right);
	}

	bool isSymmetricalRec(TreeNode* pLeft, TreeNode* pRight)
	{
		if (!pLeft && !pRight) //左右对称结点都为空，则返回true
		{
			return true;
		}
		
		if (!pLeft || !pRight) //左右对称有一个结点为空，则返回false
		{
			return false;
		}

		if (pLeft->val != pRight->val)
		{
			return false;
		}

		//  镜像结点取值
		return (isSymmetricalRec(pLeft->left, pRight->right)
			&& isSymmetricalRec(pLeft->right, pRight->left));
	}

};