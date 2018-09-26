/*
019 树的子结构

题目描述
输入两棵二叉树A，B，判断B是不是A的子结构。（ps：我们约定空树不是任意一个树的子结构）
*/

/*
分析： 1.需要准备一个判断树子结构是否存在的函数。空结点是子结构，返回true，给定树是空树，
		需要返回false。循环判断pRoot1，,pRoot2左右子树结点值是否相同，不同返回false；反之
		返回true。
	   2.使用递归方法，找到根节点相同处，调用1的函数，若为true，表示B是A的结构
*/

#include <iostream>
#include <vector>
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
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
		if(!pRoot1 || !pRoot2)
			return false;

		bool res;
		if(pRoot1->val == pRoot2->val)
			res = judgeSubtree(pRoot1, pRoot2);
		if(res == true)
			return true;
		else
			return HasSubtree(pRoot1->left,pRoot2) || 
				HasSubtree(pRoot1->right,pRoot2);
    }

	//判断子结构是否相同
	bool judgeSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
	{
		if(pRoot2 == nullptr)
			return true;
		else if(pRoot1 == nullptr)
			return false;

		if(pRoot1->val == pRoot2->val)
		{
			return(judgeSubtree(pRoot1->left, pRoot2->left) && 
				judgeSubtree(pRoot1->right, pRoot2->right));
		}
		else
			return false;
	}
};