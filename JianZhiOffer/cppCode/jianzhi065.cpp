/*
065 数据流中的中位数

题目描述
如何得到一个数据流中的中位数？如果从数据流中读出奇数个数值，
那么中位数就是所有数值排序之后位于中间的数值。
如果从数据流中读出偶数个数值，那么中位数就是所有数值排序之后中间两个数的平均值。
我们使用Insert()方法读取数据流，使用GetMedian()方法获取当前读取数据的中位数。
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {

private:
	vector<int> big_heap; //大根堆，奇数部分存
	vector<int> small_heap; //小根堆， 偶数部分存

public:
	void Insert(int num)
	{
		//若现在的n为偶数，则存入到大根堆，若小于堆顶元素，则将堆顶元素弹出到小根堆中
		//此时中位数为大根堆的堆顶元素
		if ( ((big_heap.size() + small_heap.size()) & 1) == 0)
		{
			if ( big_heap.size() > 0 && num < big_heap[0])
			{
				big_heap.push_back(num);
				push_heap(big_heap.begin(), big_heap.end(), less<int>());
				num = big_heap[0];
				pop_heap(big_heap.begin(), big_heap.end(), less<int>());
				big_heap.pop_back();
			}
			//将堆顶元素弹出到小根堆中
			small_heap.push_back(num);
			push_heap(small_heap.begin(), small_heap.end(), greater<int>());
		}
		//若现在的n为奇数，则存入到小根堆，若大于堆顶元素，则将堆顶元素弹出到大根堆中
		//此时中位数为小根堆的堆顶元素 与大根堆的堆顶元素的平均值
		else
		{
			if ( small_heap.size() > 0 && num > small_heap[0])
			{
				small_heap.push_back(num);
				push_heap(small_heap.begin(), small_heap.end(), greater<int>());
				num = small_heap[0];
				pop_heap(small_heap.begin(), small_heap.end(), greater<int>());
				small_heap.pop_back();
			}
			//将堆顶元素存到大根堆中
			big_heap.push_back(num);
			push_heap(big_heap.begin(), big_heap.end(), less<int>());
		}
	}

	double GetMedian()
	{
		int size = big_heap.size() + small_heap.size();
		//若是偶数
		if (size == 0)
		{
			return -1;
		}
		else if ((size & 1) == 0)
		{
			return (big_heap[0] + small_heap[0]) / 2.0;
		}
		else
		{
			return small_heap[0];
		}
	}

};