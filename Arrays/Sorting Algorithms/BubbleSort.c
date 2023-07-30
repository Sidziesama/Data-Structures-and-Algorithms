#include <stdio.h>
#include <stdbool.h>
// Bubble Sort

/** Time-Complexities
 * Average case = O(n^2)
 * Worst case = O(n^2)
 * Best case = O(n)
 */

int bubbleSort(int array [], int array_size){
  for (int i=0; i < (array_size-1) ;i++)
  {
    // Swap check
    bool swapped = false;
    for(int j=0 ; j<( array_size -1 -i) ;j++)
    {
      if (array[j]>array[j+1]){
          int temp = array[j];
          array[j]=array[j+1];
          array[j+1]=temp ;
          swapped = true;
      }
    }
    // Break if no swaps made as the array is already sorted
    if(swapped == false){
    break ;
  }
  }
}

void main()
{
  // Declare Array
  int array[] = {22, 4, 234, 221, 65, 17, 11};
  // Array Size
  int size_of_array = sizeof(array)/sizeof(array[0]);

  // Print Array
  printf("Array Elements : \n");
  for(int i=0;i<size_of_array;i++){
    printf("%d  ",array[i]);
  }
  
  printf("\nArray size = %d \n", size_of_array);
  
  // Sort in ascending order using Bubble Sort
  bubbleSort(array,size_of_array) ;

  printf("Array after sorting :\n");
    for (int i = 0; i < size_of_array; i++) {
        printf("%d  ", array[i]);
    }
    printf("\n");



}