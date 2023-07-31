#include <stdio.h>

/** Iterations are faster and have a more efficient space complexity in comparision to Recursions. 
 * Recursion takes slightly more time due to the overhead function calls.
 * Nonetheless, Recursion is used to break down complex problems into simple recursive calls which makes it easier to code.
*/

int fibonacci(int number)
{
  // F(0)
  if (number == 0)
  {
    return 0;
  }
  // F(1)
  else if (number == 1)
  {
    return 1;
  }
  else
  {
    return fibonacci(number - 1) + fibonacci(number - 2);
  }
}

void main()
{
  int value = 8;

  // Call Fibonacci Function and Print output sequence
  printf("Fibanacci Series upto F(%d) \n",value);
  for (int i = 0; i < value; i++)
  {
    printf("%d  ", fibonacci(i));
  }
}

