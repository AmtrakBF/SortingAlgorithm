#pragma once
static class QuickSort
{
public:
	QuickSort(int* arr, int low, int high);
private:
	int Partition(int* arr, int low, int high);
	void Swap(int& num1, int& num2);
};

