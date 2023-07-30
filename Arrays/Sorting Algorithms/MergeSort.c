#include <stdio.h>

// Merge Sort

/** Time Complexities and Theory :
 * Merge sort best case = O(nLogn)
 * Merge sort average case = O(nLogn)
 * Merge sort worst case = O(nLogn)
 * This algorithm is also based on the divide and conquer approach, just as Quick Sort.
 */

void merge(int arr[], int left, int mid, int right)
{
  int i, j, k;
  int number_of_elements_left_array = mid - left + 1;
  int number_of_elements_right_array = right - mid;

  // Create temporary arrays to store the left and right sub-arrays
  int leftArr[number_of_elements_left_array], rightArr[number_of_elements_right_array];

  // Copy data to the temporary arrays
  for (i = 0; i < number_of_elements_left_array; i++)
    leftArr[i] = arr[left + i];
  for (j = 0; j < number_of_elements_right_array; j++)
    rightArr[j] = arr[mid + 1 + j];

  i = 0; 
  j = 0;  

  // Initial index of merged sub-array
  k = left; 

  // Merge the temporary arrays back into arr[left..right]
  while (i < number_of_elements_left_array && j < number_of_elements_right_array)
  {
    if (leftArr[i] <= rightArr[j])
    {
      arr[k] = leftArr[i];
      i++;
    }
    else
    {
      arr[k] = rightArr[j];
      j++;
    }
    k++;
  }

  // Copy the remaining elements of leftArr, if any
  while (i < number_of_elements_left_array)
  {
    arr[k] = leftArr[i];
    i++;
    k++;
  }

  // Copy the remaining elements of rightArr, if any
  while (j < number_of_elements_right_array)
  {
    arr[k] = rightArr[j];
    j++;
    k++;
  }
}

int mergeSort(int array[], int left, int right)
{
  if (left < right)
  {
    // Calculate the middle index to divide the array into two halves
    int mid = left + (right - left) / 2;

    // Recursively sort the left and right halves
    mergeSort(array, left, mid);
    mergeSort(array, mid + 1, right);

    // Merge the two sorted halves
    merge(array, left, mid, right);
  }
}

void main()
{
  int array[] = {33, 73, 65, 33, 1, 0, 23};
  int size_of_array = sizeof(array) / sizeof(array[0]);

  printf("Array Elements :\n");
  for (int i = 0; i < size_of_array; i++)
  {
    printf("%d ", array[i]);
  }
  printf("\n");

  // Perform Merge Sort
  mergeSort(array, 0, size_of_array - 1);

  // Print Array after sort
  printf("Array values after sorting:\n");
  for (int i = 0; i < size_of_array; i++)
  {
    printf("%d ", array[i]);
  }
  printf("\n");
}