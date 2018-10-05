/*
026 二叉树中和为某一值的路径

题目描述
输入一颗二叉树的跟节点和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。
路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。
(注意: 在返回值的list中，数组长度大的数组靠前)
*/

/*
分析：可以用递归的方法来实现，每次传入该次的路径与当前值，进行适当的剪枝进行优化。
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
class Solution {
public:
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
		if(root == nullptr)
        {
            return res;
        }
		vector<int> path;
		recurFindPath(root, expectNumber, 0, path);
		return res;
    }

	bool recurFindPath(TreeNode* root,int expectNumber, int curVal, vector<int> path)
	{
		curVal += root->val;
		path.push_back(root->val);

		if((curVal == expectNumber) 
			&& ((root->left == nullptr) && (root->right == nullptr)) )
		{
			res.push_back(path);
			return true;
		}
		else if(curVal > expectNumber)
		{
			return false;
		}
		else
		{
			if(root->left)
				recurFindPath(root->left, expectNumber, curVal, path);
			if(root->right)
				recurFindPath(root->right, expectNumber, curVal, path);
			return true;
		}

	}
private:
	vector<vector<int> > res;
};