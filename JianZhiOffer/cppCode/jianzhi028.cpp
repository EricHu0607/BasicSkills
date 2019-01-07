/*
028 二叉搜索树与双向链表

题目描述
输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。
要求不能创建任何新的结点，只能调整树中结点指针的指向。
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
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
		if (pRootOfTree == NULL)
			return NULL;

		TreeNode* recRoot = ConvertRec(pRootOfTree);

		return getLeftNode(recRoot);
    }

	//递归左右子树，将子树变成双线链表，返回根节点
	TreeNode* ConvertRec(TreeNode* pRootOfTree)
	{
		//递归退出条件
		if (pRootOfTree == NULL)
			return NULL;

		TreeNode* tmpRoot, *tmpNode;
		//递归左子树
		if (pRootOfTree->left != nullptr)
		{
			tmpRoot = ConvertRec(pRootOfTree->left);
			//构建左链表，根节点的左孩子为返回双向链表的最右节点
			tmpNode = getRightNode(tmpRoot);
			pRootOfTree->left = tmpNode;
			tmpNode->right = pRootOfTree;
		}

		//递归右子树
		if (pRootOfTree->right != nullptr)
		{
			tmpRoot = ConvertRec(pRootOfTree->right);
			//构建右链表，根节点的右孩子为返回双向链表的最左节点
			tmpNode = getLeftNode(tmpRoot);
			pRootOfTree->right = tmpNode;
			tmpNode->left = pRootOfTree;
		}

		return pRootOfTree;
	}

private:
	TreeNode* getLeftNode(TreeNode* root)
	{
		while (root != NULL && root->left != NULL)
			root = root->left;

		return root;
	}

	TreeNode* getRightNode(TreeNode* root)
	{
		while (root != NULL && root->right != NULL)
			root = root->right;

		return root;
	}
};