/*
053 构建乘积数组

题目描述
给定一个数组A[0,1,...,n-1],请构建一个数组B[0,1,...,n-1],
其中B中的元素B[i]=A[0]*A[1]*...*A[i-1]*A[i+1]*...*A[n-1]。
不能使用除法。
*/

/*
构造两个dp数组，一个代表左边乘积数组，一个代表右边乘积数组
最后的结果就是： C[i] = A[i-1] * B[i+1]
*/
#include <vector>
#include <iostream>;
using namespace std;
class Solution {
public:
	vector<int> multiply(const vector<int>& A) {
		int len = A.size();
		vector<int> leftMulArr(len), rightMulArr(len), res(len);

		leftMulArr[0] = A[0];
		for (int i = 1; i < len; i++)
			leftMulArr[i] = leftMulArr[i - 1] * A[i];

		rightMulArr[len - 1] = A[len - 1];
		for (int i = len - 2; i >= 0; i--)
			rightMulArr[i] = rightMulArr[i + 1] * A[i];

		res[0] = rightMulArr[1];
		res[len - 1] = leftMulArr[len - 2];
		for (int i = 1; i < len - 1; i++)
		{
			res[i] = leftMulArr[i - 1] * rightMulArr[i + 1];
		}
		return res;
	}
};