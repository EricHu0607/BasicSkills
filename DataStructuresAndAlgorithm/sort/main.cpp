#include <cstdio>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <time.h>
#include "sort.h"
using namespace std;
int main()
{
	//string testname = "/root/projects/smalldata.txt";
	string testname = "/root/projects/test1.txt";
	vector<int> data;
	clock_t start, end;

	//打开测试文件
	ifstream fin;
	fin.open(testname.c_str(), ios::ios_base::in);
	if (!fin) //打开失败
	{
		cerr << "Open test file failed" << endl;
		fin.clear();
	}
	
	int input = 0;
	while (fin >> input)
	{
		data.push_back(input);
	}

	//排序之前
	//for (size_t i = 0; i < 100; i++)
	//{
	//	cout << data[i] << " ";
	//}
	//cout << endl;

	//nop
	start = clock();
	cout << "before sort:" << endl;
	//bubble_sort(&data[0], data.size());
	//insertion_sort(&data[0], data.size());
	//selection_sort(&data[0], data.size());
	//merge_sort(&data[0], data.size());
	//quick_sort(&data[0], data.size());

	end = clock();

	cout << "runtime: " << double(end - start) / 1000<< "ms" << endl;
	cout << "after sort:" << endl;
	//for (size_t i = 0; i < data.size(); i++)
	//{
	//	cout << data[i] << " ";
	//}
	cout << endl;
	//排序之后
	//关闭文件
	fin.close();
    return 0;
}