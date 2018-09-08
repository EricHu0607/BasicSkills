/*
96. Unique Binary Search Trees

Given n, how many structurally unique BST's (binary search trees) that store values 1 ... n?

Example:

Input: 3
Output: 5
Explanation:
Given n = 3, there are a total of 5 unique BST's:

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3


给定一个整数 n，求以 1 ... n 为节点组成的二叉搜索树有多少种？

示例:

输入: 3
输出: 5
解释:
给定 n = 3, 一共有 5 种不同结构的二叉搜索树:

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
*/

/*
分析：此题可以用动态规划来求解，假设F(i,n)代表以i为root，共n个数的BST，（1<=i<=n）
	  G(n)代表以 1 ... n 为节点组成的二叉搜索树有多少种。
	  则：G(n)=F(1,n)+F(2,n)+...+F(n,n)
	      而F(i,n) = G（i-1）*G（n-i）
*/

#include <vector>
using namespace std;

class Solution {
public:
    int numTrees(int n) {
        
		if(n == 0)
			return 0;

		vector<int> dp(n+1);
		dp[0] = 1;
		dp[1] = 1;

		//动态规划求G(i) i由1->n;
		for(int i=2; i <= n; ++i)
		{
			int count = 0;
			//G(i)累加求值,即F(1,i)+...+F(i,i)
			for(int j=1;j <= i; ++j)
			{
				count += dp[j-1] * dp[i-j]; 
			}
			dp[i] = count;
		}
		return dp[n];
    }
};