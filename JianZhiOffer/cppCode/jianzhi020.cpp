/*
020 二叉树的镜像
	
题目描述
操作给定的二叉树，将其变换为源二叉树的镜像
*/

/*
分析：可以使用递归，非递归的前、中、后序。使用前序的时候，只需要每一层交换左右结点即可。
		后续需要考虑交换后的结点对后续的影响，进行调整。
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
    void Mirror(TreeNode *pRoot) {
		if(!pRoot)
			return;
		TreeNode* tmp = pRoot->left;
		pRoot->left = pRoot->right;
		pRoot->right = tmp;
		Mirror(pRoot->left);
		Mirror(pRoot->right);
    }
};