/*
94. Binary Tree Inorder Traversal

Given a binary tree, return the inorder traversal of its nodes' values.

Example:

Input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [1,3,2]

给定一个二叉树，返回它的中序 遍历。

示例:

输入: [1,null,2,3]
   1
    \
     2
    /
   3

输出: [1,3,2]
进阶: 递归算法很简单，你可以通过迭代算法完成吗？
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/*
分析：输入二叉树，用中序遍历输出，不能递归。
	递归的本质就是用堆栈来实现的，通过堆栈来保存上一次的状态。
	所以我们可以使用一个堆栈来存储结点，到结点为空时，弹出上一次的结点，存储值，再继续调用右子树。
	循环遍历，就可以完成中序遍历。
*/
#include <vector>
#include <stack>
using namespace std;

class Solution {

	struct TreeNode {
		int val;
		TreeNode *left;
		TreeNode *right;
		TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	};
	
public:
    vector<int> inorderTraversal(TreeNode* root) {
		
		vector<int> res;
		//特殊判断
		if(!root)
			return res;

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
		return res;
    }
};