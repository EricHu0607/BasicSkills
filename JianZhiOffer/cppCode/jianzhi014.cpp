/*
014 数值的整数次方

题目描述
给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方。
*/

/*
分析：1、exponent < 0，取倒数；2、exponent == 0，返回1；3、exponent > 0，正常取值
	  思路一：可以通过 n：目前指数，初始=1，每次*2,res *= res,直到>exponent，此时再对剩下
			  的exponent-n，求值，即：1~exponent-n，求res *= base。
	  思路二：可以通过指数的二进制来进行求值。如base = 10, exponent = 5（101） 最高位1，代表
	          权重10^4，在res = res * 权重。为0的位不用乘。
				
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    double Power(double base, int exponent) {
		//指数<0，则取倒数
		if(exponent < 0) return 1/Power(base, -exponent);
		if(exponent == 0) return 1;
		if(exponent == 1) return base;

		double res = 1.0, tmp = base;
		
		while( exponent != 0)
		{
			if( (exponent & 1) == 1)
				res *= tmp;
			tmp *= tmp;
			exponent >>= 1;
		}
		return res;
    }
};
