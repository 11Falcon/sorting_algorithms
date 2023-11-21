#include "sort.h"

/**
 * partition - the partition function for quicksort
 * @array: the array to be sorted
 * @low: to indicate the start of the partition
 * @high: to indicate the end of the partition
 * @size: the size of the array
 * Return: the index of the pivot
 */
int partition(int *array, int low, int high, int size)
{
	int pivot, start, end, temp;

	pivot = array[high];
	start = low - 1;
	for (end = low; end < high; end++)
	{
		if (array[end] < pivot)
		{
			start++;
			temp = array[start];
			array[start] = array[end];
			array[end] = temp;
			if (start != end)
				print_array(array, size);
		}
	}
	temp = array[start + 1];
	array[start + 1] = array[high];
	array[high] = temp;
	if (start + 1 != high)
		print_array(array, size);
	return (start + 1);
}

/**
 * sort - the recursive sort function
 * @array: the array to be sorted
 * @low: to indicate the start of the partition
 * @high: to indicate the end of the partition
 * @size: the size of the array
 */
void sort(int *array, int low, int high, int size)
{
	int pivot_index;

	if (low < high)
	{
		pivot_index = partition(array, low, high, size);
		sort(array, low, pivot_index - 1, size);
		sort(array, pivot_index + 1, high, size);
	}
}

/**
 * quick_sort - the quick sort algorithm
 * @array: the array to be sorted
 * @size: the size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	sort(array, 0, size - 1, size);
}

