/*
024 从上往下打印二叉树

题目描述
从上往下打印出二叉树的每个节点，同层节点从左至右打印。
*/

/*
分析：树的层次遍历，通过一个队列来控制结点。
*/

#include <iostream>
#include <vector>
#include <queue>
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
    vector<int> PrintFromTopToBottom(TreeNode* root) {
		vector<int> res;

		if(!root)
			return res;

		queue<TreeNode*> qNode;
		qNode.push(root);
		TreeNode* cur;
		//层次遍历
		while(!qNode.empty())
		{
			cur = qNode.front();
			qNode.pop();
			res.push_back(cur->val);
			if(cur->left)
				qNode.push(cur->left);
			if(cur->right)
				qNode.push(cur->right);
		}
		return res;

    }
};