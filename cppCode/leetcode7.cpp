/*
7. Reverse Integer
Given a 32-bit signed integer, reverse digits of an integer.

Example 1:

Input: 123
Output: 321
Example 2:

Input: -123
Output: -321
Example 3:

Input: 120
Output: 21
*/

#include <limits>
using namespace std;
class Solution {
public:
    int reverse(int x) {
        long long res = 0;
		while(x)
		{
			res = res*10 + x%10;
			x /= 10;
		}
		return (res > numeric_limits<int>::max() || res < numeric_limits<int>::min()) ? 0 : res;
    }
};