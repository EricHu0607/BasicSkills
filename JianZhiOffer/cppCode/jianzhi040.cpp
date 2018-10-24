/*
040 二叉树的深度

题目描述
输入一棵二叉树，求该树的深度。从根结点到叶结点依次经过的结点（含根、叶结点）
形成树的一条路径，最长路径的长度为树的深度。
*/

/*
分析：利用递归，树的深度= max（左子树深度，右子树深度） + 1，递归出口是空节点，此时深度为0。
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
    int TreeDepth(TreeNode* pRoot)
    {
		if(!pRoot)
			return 0;

		return max(TreeDepth(pRoot->left), TreeDepth(pRoot->right)) + 1;
    }
};