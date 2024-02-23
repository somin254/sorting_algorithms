#include "sort.h"

/**
 * custom_swap - swaps two integers in an array
 * @first_num: pointer to the first element
 * @second_num: pointer to the second element
 */
void custom_swap(int *first_num, int *second_num) {
    int temp = *first_num;
    *first_num = *second_num;
    *second_num = temp;
}

/**
 * custom_partition - partitions the array using Lomuto scheme
 * @arr: input array
 * @low: index of the first element
 * @high: index of the last element
 * @size: size of the array
 * Return: integer representing the pivot position
 */
int custom_partition(int *arr, int low, int high, size_t size) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high; j++) {
        if (arr[j] <= pivot) {
            i++;
            custom_swap(&arr[i], &arr[j]);
            if (i != j)
                print_array(arr, size);
        }
    }

    custom_swap(&arr[i + 1], &arr[high]);
    if (i != high)
        print_array(arr, size);

    return (i + 1);
}

/**
 * quick_sort_array - sorts the array using QuickSort algorithm
 * @arr: input array
 * @low: index of the first element
 * @high: index of the last element
 * @size: size of the array
 */
void quick_sort_array(int *arr, int low, int high, size_t size) {
    if (low < high) {
        int pivot = custom_partition(arr, low, high, size);
        quick_sort_array(arr, low, pivot - 1, size);
        quick_sort_array(arr, pivot + 1, high, size);
    }
}

/**
 * quick_sort - sorts an array using QuickSort algorithm
 * @array: input array
 * @size: size of the array
 */
void quick_sort(int *array, size_t size) {
    if (size < 2)
        return;

    quick_sort_array(array, 0, size - 1, size);
}
