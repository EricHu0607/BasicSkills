
//二分查找有序非重复数组，返回下标，无则返回-1
int binary_search(int data[], int size, int search_data)
{
	int low = 0, high = size - 1;
	int mid = 0;

	//采用while循环进行二分查找
	while (low <= high)
	{
		mid = low + ((high - low) >> 1);
		//若data[mid] == search_data，则直接返回下标
		if (data[mid] == search_data)
		{
			return mid;
		}
		//若data[mid] < search_data，则查找数据处于mid右边
		else if (data[mid] < search_data)
		{
			low = mid + 1;
		}
		//若data[mid] > search_data，则查找数据处于mid左边
		else
		{
			high = mid - 1;
		}
	}

	return -1;
}

//二分查找有序有重复数组，返回查找元素第一次出现的下标，无则返回-1
int binary_search_first_data(int data[], int size, int search_data)
{
	int low = 0, high = size - 1;
	int mid = 0;

	//采用while循环进行二分查找
	while (low <= high)
	{
		mid = low + ((high - low) >> 1);
		//若data[mid] == search_data，则要判断mid是否为首个元素下标
		if (data[mid] == search_data)
		{
			//若mid为0，或mid的前一个不为search_data，则为首个元素下标
			if (mid == 0 || data[mid - 1] != search_data)
			{
				return mid;
			}
			else
			{
				high = mid - 1;
			}
		}
		//若data[mid] < search_data，则查找数据处于mid右边
		else if (data[mid] < search_data)
		{
			low = mid + 1;
		}
		//若data[mid] > search_data，则查找数据处于mid左边
		else
		{
			high = mid - 1;
		}
	}

	return -1;
}

//二分查找有序有重复数组，返回查找元素最后一次出现的下标，无则返回-1
int binary_search_last_data(int data[], int size, int search_data)
{
	int low = 0, high = size - 1;
	int mid = 0;

	//采用while循环进行二分查找
	while (low <= high)
	{
		mid = low + ((high - low) >> 1);
		//若data[mid] == search_data，则要判断mid是否为最后一个元素下标
		if (data[mid] == search_data)
		{
			//若mid为0，或mid的后一个不为search_data，则为最后一个元素下标
			if (mid == (size - 1) || data[mid + 1] != search_data)
			{
				return mid;
			}
			else
			{
				low = mid + 1;
			}
		}
		//若data[mid] < search_data，则查找数据处于mid右边
		else if (data[mid] < search_data)
		{
			low = mid + 1;
		}
		//若data[mid] > search_data，则查找数据处于mid左边
		else
		{
			high = mid - 1;
		}
	}

	return -1;
}

//二分查找有序有重复数组，查找第一个大于等于给定值的元素，无则返回-1
int binary_search_first_exceed(int data[], int size, int search_data)
{
	int low = 0, high = size - 1;
	int mid = 0;

	//采用while循环进行二分查找
	while (low <= high)
	{
		mid = low + ((high - low) >> 1);

		//若data[mid] < search_data，则查找数据处于mid右边
		if (data[mid] < search_data)
		{
			low = mid + 1;
		}
		//若data[mid] >= search_data，则对mid的前一位进行判断
		else
		{
			if (mid == 0 || data[mid - 1] < search_data)
			{
				return mid;
			}
			else
			{
				high = mid - 1;
			}
		}
	}

	return -1;
}

//二分查找有序有重复数组，查找最后一个小于等于给定值的元素，无则返回-1
int binary_search_last_below(int data[], int size, int search_data)
{
	int low = 0, high = size - 1;
	int mid = 0;

	//采用while循环进行二分查找
	while (low <= high)
	{
		mid = low + ((high - low) >> 1);

		//若data[mid] > search_data，则查找数据处于mid左边
		if (data[mid] > search_data)
		{
			high = mid - 1;
		}
		//若data[mid] >= search_data，则对mid的后一位进行判断
		else
		{
			if (mid == size - 1 || data[mid + 1] > search_data)
			{
				return mid;
			}
			else
			{
				low = mid + 1;
			}
		}
	}

	return -1;
}