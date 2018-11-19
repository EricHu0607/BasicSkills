/*
049 求1+2+3+...+n

题目描述
求1+2+3+...+n，要求不能使用乘除法、for、while、if、else、switch、
case等关键字及条件判断语句（A?B:C）。
*/

/*
采用&&的短路思想，来实现递归的临界条件判断
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int Sum_Solution(int n) {
		int sum = n;
		(n > 0) && (sum += Sum_Solution(n - 1));
		return sum;
    }
};