#include <iostream>
#include <vector>

#include <chrono>
#include <thread>

#include "LinkedList.h"
#include "QuickSort.h"

int main()
{
	using namespace std::literals::chrono_literals;

	auto start = std::chrono::high_resolution_clock::now();

	int arr[] = {2, 8, 9, 5, 18, 3, 4, 20};
	int count = sizeof(arr) / sizeof(int);

	QuickSort::QuickSort(arr, 0, count-1);

	auto end = std::chrono::high_resolution_clock::now();

	std::chrono::duration<long double> duration = end - start;
	std::cout << duration.count() << "s" << std::endl;	
}


