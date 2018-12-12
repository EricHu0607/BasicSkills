/*
062 把二叉树打印成多行

题目描述
从上到下按层打印二叉树，同一层结点从左至右输出。每一层输出一行。
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
	vector<vector<int> > Print(TreeNode* pRoot) {
		vector<queue<TreeNode*>> queue(2);
		vector<vector<int>> res;

		if (!pRoot) 
		{
			return res;
		}

		int flag = 0;//控制选择那个stack
		queue[flag].push(pRoot);
		TreeNode* tmpNode;
		vector<int> line;

		while (!queue[0].empty() || !queue[1].empty())
		{
			while (!queue[flag].empty())
			{
				tmpNode = queue[flag].front();
				queue[flag].pop();
				line.push_back(tmpNode->val);
				if (tmpNode->left)
					queue[(flag + 1) % 2].push(tmpNode->left);
				if (tmpNode->right)
					queue[(flag + 1) % 2].push(tmpNode->right);
			}

			if (!line.empty())
			{
				res.push_back(line);
				line.clear();
			}

			flag = (flag + 1) % 2;
		}
		return res;
	}
	
};