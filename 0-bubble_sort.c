#include "sort.h"

/**
 * bubble_sort - sorting an array using the method bubble
 * @array: the list to sort
 * @size: size of the array
 */

void bubble_sort(int *array, size_t size)
{
	size_t i = 0;
	int changed = 1;
	int temp = 0;
	int ash = 0;

	while (changed)
	{
		changed = 0;
		for (i = 0; i < size - 1; i++)
		{
			ash = 0;
			if (array[i] > array[i + 1])
			{
				ash = 1;
				changed = 1;
				temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;
			}
			if (ash)
				print_array(array, size);
		}
	}
}
