/*
009 斐波那契数列
大家都知道斐波那契数列，现在要求输入一个整数n，请你输出斐波那契数列的第n项（从0开始，第0项为0）。
n<=39
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int Fibonacci(int n) {
		int ret;
		switch (n) 
		{
		case 0: 
			ret = 0;
			break;
		case 1:
			ret = 1;
			break;
		case 2:
			ret = 1;
			break;
		default:
			int fir = 1,sec = 1, cnt = 2, thr;
			while(cnt < n)
			{
				thr = fir + sec;
				fir = sec;
				sec = thr;
				cnt ++ ;
			}
            ret = thr;
			break;
		}
		return ret;
    }
};