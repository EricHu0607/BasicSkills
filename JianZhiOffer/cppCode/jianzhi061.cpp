/*
061 按之字形顺序打印二叉树

题目描述
请实现一个函数按照之字形打印二叉树，即第一行按照从左到右的顺序打印，
第二层按照从右至左的顺序打印，第三行按照从左到右的顺序打印，其他行以此类推。
*/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};

/*
构造一个栈，奇数次按左右结点存入，偶数次按右左结点存入
*/
class Solution {
public:
	vector<vector<int> > Print(TreeNode* pRoot) {

		vector<vector<int> > res;
		stack<TreeNode* > stOdd,stEven;

		if (!pRoot)
		{
			return res;
		}

		stOdd.push(pRoot);
		TreeNode* tmpNode;
		vector<int> line;

		while (!stOdd.empty() || !stEven.empty())//若奇数次或偶数次栈不为空
		{
			while (!stOdd.empty()) //奇数栈按左右结点存入偶数栈
			{
				tmpNode = stOdd.top();
				line.push_back(tmpNode->val);
				stOdd.pop();
				if (tmpNode->left)
				{
					stEven.push(tmpNode->left);
				}
				if (tmpNode->right)
				{
					stEven.push(tmpNode->right);
				}
			}

			if (!line.empty())
			{
				res.push_back(line);
				line.clear();
			}

			while (!stEven.empty()) //偶数栈按右左结点存入偶数栈
			{
				tmpNode = stEven.top();
				line.push_back(tmpNode->val);
				stEven.pop();
				if (tmpNode->right)
				{
					stOdd.push(tmpNode->right);
				}
				if (tmpNode->left)
				{
					stOdd.push(tmpNode->left);
				}
			}

			if (!line.empty())
			{
				res.push_back(line);
				line.clear();
			}
		}
		return res;
	}
};