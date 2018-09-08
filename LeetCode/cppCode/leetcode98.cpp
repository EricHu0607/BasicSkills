/*
98. Validate Binary Search Tree

Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
Example 1:

Input:
    2
   / \
  1   3
Output: true
给定一个二叉树，判断其是否是一个有效的二叉搜索树。

假设一个二叉搜索树具有如下特征：

节点的左子树只包含小于当前节点的数。
节点的右子树只包含大于当前节点的数。
所有左子树和右子树自身必须也是二叉搜索树。
*/

/*
分析：首先中序遍历树，会得到一个有序序列，保存在vector中。
	  再对vector进行判断，如果不是递增，则表示不是BST。
	  当然这种方法时间复杂度、空间复杂度都比较大。
*/
#include <vector>
#include <stack>
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
    bool isValidBST(TreeNode* root) {
		
		if(!root)
			return true;

		vector<int> res;
		stack<TreeNode* > st;
		TreeNode* cur = root;

		while(cur != nullptr || !st.empty())
		{
			//找到左子树的叶子结点
			while(cur != nullptr)
			{
				st.push(cur);
				cur = cur->left;
			}

			//恢复到上一结点，存值，调用右子树。
			cur = st.top();
			st.pop();
			res.push_back(cur->val);
			cur = cur->right;
		}

		for(int i=0; i<res.size()-1; ++i)
		{
			if(res[i] >= res[i+1])
				return false;
		}
		return true;
    }
};