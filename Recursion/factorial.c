#include <stdio.h>

// Factorial Function
int factorial (int number){
  if (number == 0){
    return 1 ;
  }else{
    return number * factorial(number-1);
  }
}

void main(){
  int value = 6 ;

  // Call factorial function and print factorial
  printf("Factorial of %d = %d",value,factorial(value));
}