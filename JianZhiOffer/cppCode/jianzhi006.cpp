/*
006 重建二叉树

输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。
假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，
则重建二叉树并返回。
*/
/*
分析：前序遍历序列{1,2,4,7,3,5,6,8} pre[]
	  中序遍历序列{4,7,2,1,5,3,8,6} vin[]
	  本题可以采用分治法：在pre中的left为最先遇到的根节点，以1为例，将中序序列分成左右子树两部分
		  再产生的两个中序子序列，例：pre{2,4,7}，{3,5,6,8}、vin{4,7,2}，{5,3,8,6}。
		  递归回溯构建树即可
	
*/
#include <iostream>
#include <vector>
using namespace std;

 // Definition for binary tree
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 
class Solution {
public:
	TreeNode* constructBinaryTree(vector<int> &pre,vector<int> &vin,int lp, int rp, int lv, int rv)
	{
		if(lv > rv || lp > rp)
			return nullptr;
		TreeNode* node = new TreeNode(pre[lp]);
		int i;
		for(i=lv; i<=rv; i++)
			if(pre[lp] == vin[i])
				break;

		node->left = constructBinaryTree(pre, vin, lp+1, lp+i-lv, lv, i-1);
		node->right = constructBinaryTree(pre, vin, lp+i-lv+1, rp, i+1, rv);
		return node;
	}
 
	TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
		if(pre.empty())
			return nullptr;
		return constructBinaryTree(pre, vin, 0, pre.size()-1, 0, vin.size()-1);
    }
};	