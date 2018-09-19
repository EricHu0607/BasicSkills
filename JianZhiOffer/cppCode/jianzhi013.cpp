/*
013 二进制中1的个数

题目描述
输入一个整数，输出该数二进制表示中1的个数。其中负数用补码表示。
*/

#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
//方法一：
     int  NumberOf1(int n) {
         
		 int count = 0;
		 unsigned int flag = 1;
		 while(flag != 0)
		 {
			if( (n & flag) != 0)
				count++;
			flag <<= 1;
		 }
		 return count;
     }
//方法二：一个二进制数，与自身-1取&，只会影响最右边的“1”位，计算其个数即可。
//       如1110  1110 & 1101 = 1100 只影响了“1110”最右边的1,因此，对此进行统计即可。
     int  NumberOf2(int n) {
         
		 int count = 0;
		 while(n)
		 {
			count++;
			n = n & (n-1);
		 }
		 return count;
     }
};