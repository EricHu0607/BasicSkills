/*
025 二叉搜索树的后序遍历序列

题目描述
输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。
如果是则输出Yes,否则输出No。假设输入的数组的任意两个数字都互不相同。
*/

/*
分析：sequence数组最右边的索引为根节点，
		1.可以通过该结点，往前遍历，第一个比root小的结点为左子树的root结点，记索引为newIndex
		  只需要判断 left到newIndex都小于root，说明此次满足二叉搜索树
		2.可以通过left结点开始，往右遍历，第一个比root大的结点索引-1，为左子树的root结点。
		  记索引为newIndex只需要判断，newIndex+1到right都大于root，说明此次满足二叉搜索树
*/
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {

		if(sequence.empty())
			return false;
		return checkSequenceOfBST(sequence, 0, sequence.size() - 1);

    }

	bool checkSequenceOfBST(vector<int> &sequence, int left, int right)
	{
		int root = sequence[right];
		int newIndex;
		if(left >= right)
			return true;

		for(int i = right - 1; i>= left; i--)
		{
			if(root > sequence[i])
			{
				newIndex = i;
				break;
			}
		}

		//左子树应当都小于root
		for(int i = left; i < newIndex; i++)
		{
			if(sequence[i] > root)
				return false;
		}
		//右子树应当都大于root,此段代码可以省略。
		/*for(int i = newIndex + 1; i < right; i++)
		{
			if(sequence[i] < root)
				return false;
		}*/

		return checkSequenceOfBST(sequence, left, newIndex) && 
			checkSequenceOfBST(sequence,newIndex + 1, right - 1);
	}
};