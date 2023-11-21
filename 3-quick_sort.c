#include "sort.h"

/**
 * lomuto_partition - the Lomuto partition scheme
 * @array: the array to be sorted
 * @low: to indicate the start of the partition
 * @high: to indicate the end of the partition
 * @size: the size of the array
 * Return: the index of the pivot
 */
int lomuto_partition(int *array, int low, int high, int size)
{
	int pivot, i, temp, j;
	
	pivot = array[high];
	i = low - 1;
	
	for (j = low; j <= high - 1; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			if (i != j)
				print_array(array, size);
		}
	}
	temp = array[i + 1];
	array[i + 1] = array[high];
	array[high] = temp;
	if (i + 1 != high)
		print_array(array, size);
	return (i + 1);
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
		pivot_index = lomuto_partition(array, low, high, size);
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
