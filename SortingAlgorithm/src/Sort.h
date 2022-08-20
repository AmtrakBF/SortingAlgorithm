#pragma once
class Sort
{

public:
	Sort(int* arr, unsigned int count);
	void QuickSort(int* arr, unsigned int count);

private:
	int SetHighLow(int* arr, int& high, int& low, const int& x);
};

