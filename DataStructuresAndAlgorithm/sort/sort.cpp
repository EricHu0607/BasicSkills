#include <cstdio>
#include <algorithm>
using namespace std;
//冒泡排序 data[] 为输入数组，n为数组大小
void bubble_sort(int data[], int n)
{
	if (n < 2)
		return;
	
	for (int i = 0; i < n - 1 ; i++)
	{
		bool flag = false;
		for (int j = 0; j < n - i - 1; j++)
		{
			//相邻元素进行比较，前面大于后面元素时，交换元素，并标识交换
			if (data[j] > data[j+1]) 
			{
				flag = true;
				swap(data[j], data[j + 1]);
			}
		}
		if (!flag)
			break;
	}
}

//插入排序 data[] 为待排序数组，n为数组大小
void insertion_sort(int data[], int n)
{
	if (n < 2)
		return;

	//从未排序区间选择元素插入到已排序区间,[0,i)为已排序区间，[i,n)为未排序区间
	int value = 0;
	for (int i = 1; i < n; i++)
	{
		value = data[i];
		int j = i - 1;
		for (; j >= 0; j--)
		{
			//当待插入元素小于前面数据，移动数据
			if (value < data[j])
			{
				data[j + 1] = data[j];
			}
			//当不用交换时，退出循环			
			else
				break;
		}
		//插入value于已排序区间
		data[j + 1] = value;
	}
}

//选择排序，data[] 为待排序数组，n为数组大小
void selection_sort(int data[], int n)
{
	if (n < 2)
		return;

	//从未排序区间找出最小元素插入到已排序区间,[0,i)为已排序区间，[i,n)为未排序区间
	int min_index;
	for (int i = 0; i < n - 1; i++)
	{
		//找到[i,n)区间中最小的元素
		min_index = i;
		for (int j = i + 1; j < n; j++)
		{
			if (data[min_index] > data[j])
			{
				min_index = j;
			}
		}
		//将最小元素插入到已排序区间末尾
		swap(data[i], data[min_index]);
	}
}

//合并递归后的左右区间，[left,mid],[mid+1,right]
void merge(int data[], int left, int mid, int right)
{
	//临时数组，用来合并
	int len = right - left + 1;
	int* tmp = new int[len];

	//i为左区间index，j为右区间index，k为tmp数组index
	int i = left, j = mid + 1, k = 0;
	while (i <= mid && j <= right)
	{
		//左区间<右区间首元素，加入data[left]到tmp数组
		if (data[i] < data[j])
			tmp[k++] = data[i++];
		//反之，加入data[mid+1] 到tmp 数组
		else
			tmp[k++] = data[j++];
	}

	//若左区间剩余为空，将右区间剩余加入tmp数组
	if (i > mid)
	{
		while (j <= right)
			tmp[k++] = data[j++];
	}
	//若右区间剩余为空，将左区间剩余加入tmp数组
	else
	{
		while (i <= mid)
			tmp[k++] = data[i++];
	} 

	//将tmp数组copy到data[left，right]
	for (int i = 0; i < len; i++)
	{
		data[i + left] = tmp[i];
	}

	delete[] tmp;
}

//归并排序内部递归部分,[left,right]区间
void __merge_sort(int data[], int left, int right)
{
	//递归终止条件
	if (left >= right)
		return;
	
	int mid = left + ((right - left) >> 2);

	__merge_sort(data, left, mid);
	__merge_sort(data, mid + 1, right);

	merge(data, left, mid, right);
}

//data为待排序数组，n为数组大小
void merge_sort(int data[], int n)
{
	__merge_sort(data, 0, n - 1);
}

//分区函数，采用取最后一个元素为pivot，
//返回分区结点的下标
int partition(int data[], int left, int right)
{
	int pivot = data[right];

	//[left,r)为小于pivot部分，(r,right]为大于pivot部分
	int r = left;
	for (int i = left; i < right; i++)
	{
		//小于pivot加入到[left,r)最后
		if (data[i] <= pivot)
		{
			swap(data[i], data[r]);
			++r;
		}
	}

	swap(data[r], data[right]);
	return r;
}

//快速排序内部递归部分,[left,right]区间
void __quick_sort(int data[], int left, int right)
{
	if (left >=  right)
		return;
	
	//对原区间进行分区
	int pos = partition(data, left, right);

	__quick_sort(data, left, pos - 1);
	__quick_sort(data, pos + 1, right);
}

//data为待排序数组，n为数组大小
void quick_sort(int data[], int n)
{
	__quick_sort(data, 0, n - 1);
}