#include "QuickSort.h"

QuickSort::QuickSort(int* arr, int low, int high)
{
	if (low < high)
	{
		int partitionIndex = Partition(arr, low, high);
		QuickSort(arr, low, partitionIndex - 1);
		QuickSort(arr, partitionIndex + 1, high);
	}
}

int QuickSort::Partition(int* arr, int low, int high)
{
	int index = low - 1;
	int pivot = arr[high];

	for (int x = low; x <= high; x++)
	{
		if (arr[x] < pivot)
		{
			index++;
			Swap(arr[x], arr[index]);
		}
	}
	Swap(arr[high], arr[index + 1]);
	return(index + 1);
}

void QuickSort::Swap(int& num1, int& num2)
{
	int buffer = num1;
	num1 = num2;
	num2 = buffer;
}