#include <stdio.h>
#define MAX_SIZE 11
/** Create an Array and Perform Array Operations :
 * 1) Search
 * 2) Update
 * 3) Insertion
 * 4) Deletion
 */

/** Time-Complexities :
 * Array size = n ;
 * Time complexity for sequential search = O(n)
 * Time complexity for binary search = O(logn) ; [The array must be sorted to perform Binary Search] 
 * Insertion time-complexity = O(n) ; Worst case is when you have to insert the element at the beginning of the array. Requires right shift of all elements
 * Deletion time-complexity = O(n) ; Worst case is when you have to delete the element from the beginning of the array. Requires left shift of all elements
 * Access / Update time = O(1) 
*/

// Search an element in an Array
int searchElementInArray(int *arr, int search_value, int array_size)
{
  for (int i = 0; i < array_size; i++)
  {
    if (arr[i] == search_value)
    {
      printf("Search Result : True\n");
      return 1;
    }
  }
  printf("Search Result : False\n");
  return 0;
}

// Update an element in an Array
int updateElementsInArray(int *arr, int update_position, int update_value, int array_size)
{
  arr[update_position] = update_value;

  // Printing Updated Array Elements
  printf("Updated Batsman Scores : \n");
  for (int i = 0; i < array_size; i++)
  {
    printf("Batter %d Score : %d \n", (i + 1), arr[i]);
  }
}

// Insert an Element in an Array
int insertElementInrray(int insert_position, int insert_value)
{

  printf("INSERTION : \n");

  // Create a static array
  int array_of_scores[MAX_SIZE];

  // Return if insert_position exceeds array capacity
  if (insert_position >= MAX_SIZE || insert_position < 0)
  {
    printf("You have exceeded the Array Limit. Cannot Insert Element at %d position.", insert_position);
    return 1;
  }

  // Size of Array
  int size_of_array;
  printf("Enter Size of the array : \n");
  scanf("%d", &size_of_array);

  // Return if array size > Max Size
  if (size_of_array >= MAX_SIZE || size_of_array < 0)
  {
    printf("You have exceeded the Array Limit. Cannot declare array of size %d ", size_of_array);
    return 1;
  }

  printf(" Array Size = %d\n", size_of_array);

  // Take Array Inputs
  for (int i = 0; i < size_of_array; i++)
  {
    printf("Enter Batter %d Score : \n", (i + 1));
    scanf("%d", &array_of_scores[i]);
  }

  // Print New Array
  printf("Batsman Scores : \n");
  for (int i = 0; i < size_of_array; i++)
  {
    printf("Batter %d Score : %d \n", (i + 1), array_of_scores[i]);
  }

  // Insert position and Insert Value
  printf("Insertion position : %d \n Insertion Value : %d \n", insert_position, insert_value);

  for (int i = size_of_array - 1; i >= insert_position; i--)
  {
    array_of_scores[i + 1] = array_of_scores[i];
  }

  array_of_scores[insert_position] = insert_value;
  size_of_array += 1;

  // print array after Insertion
  printf("Batsman Scores after Insertion : \n");
  for (int i = 0; i < size_of_array; i++)
  {
    printf("Batter %d Score : %d \n", (i + 1), array_of_scores[i]);
  }
  printf("Updated Size of array = %d", size_of_array);
  return 0;
}

// Delete an Element from an Array
int deleteElementFromArray(int delete_position)
{

  printf("DELETION : \n");

  // Create a static array
  int array_of_scores[MAX_SIZE];

  // Return if insert_position exceeds array capacity
  if (delete_position >= MAX_SIZE || delete_position < 0)
  {
    printf("You have exceeded the Array Limit. Cannot Delete Element from %d position.", delete_position);
    return 1;
  }

  // Size of Array
  int size_of_array;
  printf("Enter Size of the array : \n");
  scanf("%d", &size_of_array);

  // Return if array size > Max Size
  if (size_of_array >= MAX_SIZE || size_of_array < 0)
  {
    printf("You have exceeded the Array Limit. Cannot declare array of size %d ", size_of_array);
    return 1;
  }

  printf(" Array Size = %d\n", size_of_array);

  // Take Array Inputs
  for (int i = 0; i < size_of_array; i++)
  {
    printf("Enter Batter %d Score : \n", (i + 1));
    scanf("%d", &array_of_scores[i]);
  }

  // Print New Array
  printf("Batsman Scores : \n");
  for (int i = 0; i < size_of_array; i++)
  {
    printf("Batter %d Score : %d \n", (i + 1), array_of_scores[i]);
  }

  printf("Delete Position = %d \n", delete_position);

  // Deleting Element
  for (int i = delete_position; i < size_of_array - 1; i++)
  {
    array_of_scores[i] = array_of_scores[i + 1];
  }
  size_of_array -= 1;

  // print array after Insertion
  printf("Batsman Scores after deletion : \n");
  for (int i = 0; i < size_of_array; i++)
  {
    printf("Batter %d Score : %d \n", (i + 1), array_of_scores[i]);
  }
  printf("Updated Size of array = %d", size_of_array);
  return 0;
}

void main()
{
  // Create a static array
  int array_of_scores[5] = {36, 44, 3, 102, 61};

  // Size of Array
  int size_of_array = sizeof(array_of_scores) / sizeof(array_of_scores[0]);

  // Printing Array Elements
  printf("Batsman Scores : \n");
  for (int i = 0; i < size_of_array; i++)
  {
    printf("Batter %d Score : %d \n", (i + 1), array_of_scores[i]);
  }
  // Printing Size of the Array
  printf("Size of the array : %d \n", size_of_array);

  // Call Search Function
  int search_score = 61;

  // printf("Searching for element %d in the array...\n", search_score);
  // int isScorePresent = searchElementInArray(array_of_scores, search_score, size_of_array);

  // Call Update Element Function
  int updatePosition = 2;
  int updateValue = 7;
  // updateElementsInArray(array_of_scores, updatePosition, updateValue,size_of_array);

  // Insertion
  int insertPosition = 3;
  int insertValue = 33;

  // Call Insetion function
  // insertElementInrray(insertPosition, insertValue);

  // Deletion
  int deletePosition = 2;
  // deleteElementFromArray(deletePosition);
}
