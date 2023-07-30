#include <stdio.h>
#define MAX_SIZE 30
#include <stdbool.h>

// Stacks 

/** Stack theory and Operations :
 * It is a data structure that works on the last-in-first-out (lifo) principle.
 * Operations :
 * 1) Push 
 * 2) Pop
 * 3) Peek
*/

// define Stack Structure
typedef struct{
  int arr[MAX_SIZE];
  int top ;
} Stack ;

// Initialize Stack 
void initializeStack(Stack *stack){
  // Initialize stack to -1 to indicate an empty stack
  stack -> top = -1 ;
}

// Function to check is Stack is empty 
bool isEmpty(Stack *stack){
  return stack->top == -1 ;
}

// Function to check if Stack is full
bool isFull(Stack*stack){
  return stack->top == MAX_SIZE-1;
}

// Push function 
int push(Stack *stack ,int value ){
  if(isFull(stack)){
    printf("Stack overflow. Cannot push %d into stack\n",value);
  }else{
    printf("Pushing element %d into stack\n ",value);
    stack->top ++ ;
    stack->arr[stack->top] = value ;
  }
}

// Pop function 
int pop(Stack *stack){
  if(isEmpty(stack)){
    printf("Stack underflow. Cannot pop element from stack");
    return -1 ;
  }else{
    int value = stack->arr[stack->top] ;
    stack->top-- ;
    return value;
  }
}

// Function to get the value of the top element without removing it
int peek(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty. Cannot peek.\n");
        return -1; 
    } else {
        return stack->arr[stack->top];
    }
}

void main() {
    Stack stack;
    initializeStack(&stack);

    push(&stack, 110);
    push(&stack, 120);
    push(&stack, 130);

    printf("Top element: %d\n", peek(&stack));
    printf("Popped element: %d\n", pop(&stack));
    printf("Popped element: %d\n", pop(&stack));

}



