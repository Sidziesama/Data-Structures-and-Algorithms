#include <stdio.h>
#include <stdbool.h>
// Quick Sort

/** Time-Complexities and theory :
 * Average case = O(n.logn)
 * Worst case = O(n^2)
 * Best case = O(n.logn)
 * Quick Sort is a sorting algorithm based on the Divide and Conquer Approach.
 * Reference https://www.programiz.com/dsa/quick-sort
 */

// Swap Function
void swap(int *element_1, int *element_2)
{
  int c = *element_1;
  *element_1 = *element_2;
  *element_2 = c;
}

// Partition Fuction. Returns Pivot index
int partition(int array[], int low, int high)
{
  // Select the rightmost element as the pivot
  int pivot = array[high];

  // Index of the smaller element
  int i = low - 1; 

  for (int j = low; j < high; j++)
  {
    // If the current element is smaller than or equal to the pivot
    // then swap it with the element at index i and shift i to the right.
    if (array[j] <= pivot)
    {
      i++;
      swap(&array[i], &array[j]);
    }
  }
  // Finally, swap the pivot element with the element at index i+1
  swap(&array[i + 1], &array[high]);

  // Return the index of the pivot element
  return i + 1;
}

int quickSort(int array[], int low, int high)
{
  if (low < high)
  {

    int pivot = partition(array, low, high);
    // Recursively sort the left and right sub-arrays
    quickSort(array, low, pivot - 1);
    quickSort(array, pivot + 1, high);
  }
}

void main()
{
  // Declare Array
  int array[] = {45, 3, 444, 65, 95, 9, 15};
  // Array Size
  int size_of_array = sizeof(array) / sizeof(array[0]);

  // Print Array
  printf("Array Elements : \n");
  for (int i = 0; i < size_of_array; i++)
  {
    printf("%d  ", array[i]);
  }

  printf("\nArray size = %d \n", size_of_array);

  // Perform Quick Sort
  quickSort(array, 0, (size_of_array - 1));

  printf("Array after sorting:\n");
  for (int i = 0; i < size_of_array; i++)
  {
    printf("%d ", array[i]);
  }
  printf("\n");
}