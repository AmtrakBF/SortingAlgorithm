#include "Sort.h"
#include <vector>

Sort::Sort(int* arr, unsigned int count) // O^2
{
	int biggestIndex = 0;
	int current = 0;

	std::vector<int> tempArr;
	tempArr.reserve(count);

	for (int x = 0; x < count; x++)
	{
		current = 0;
		for (int y = 0; y < count; y++)
		{
			if (arr[y] > current)
			{
				current = arr[y];
				biggestIndex = y;
			}
		}
		tempArr.push_back(current);
		arr[biggestIndex] = 0;
	}
}

void Sort::QuickSort(int* arr, unsigned int count) // I think this may be slower than sort
{
	std::vector<int> lows;
	int high = 0, low = 1; // init to first two in array -- possible memory error
	int index = 0;
	int highLow;

	SetHighLow(arr, high, low, 0); // init high and low values with start of array
	SetHighLow(arr, high, low, 1);

	lows.push_back(arr[low]);
	lows.push_back(arr[high]);

	int next = 0;

	for (int x = 2; x < count; x++)
	{
		if (x != count - 1)
			next = x + 1;

		highLow = SetHighLow(arr, high, low, x);
		if (highLow == 1) // high
		{
			lows.push_back(arr[x]);
		}
		else if (highLow == 2) // low
		{
			lows.insert(lows.begin(), arr[x]);
			index++;
		}
		else if (highLow == 0)
		{
			for (int y = lows.size() - 1; y > 0; y--)
			{
				if (arr[x] > lows[y])
				{
					lows.insert(lows.end() - (lows.size() - y - 1), arr[x]);
					break;
				}
			}
		}
	}
}

int Sort::SetHighLow(int* arr, int& high, int& low, const int& x)
{
	if (arr[x] > arr[high])
	{
		high = x;
		return 1;
	}
	else if (arr[x] < arr[low])
	{
		low = x;
		return 2;
	}
	return 0;
}