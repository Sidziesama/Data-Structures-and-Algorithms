#include <stdio.h>
#include <stdbool.h>
#define MAX_SIZE 30

// Queues

/** Queue Operations and Theory
 * Queue is a data structure that follows the first-in-first-out principle (fifo)
 * Queue Operations :
 * 1) Enqueue
 * 2) Dequeue
 */

// Initialize Queue Structure
typedef struct
{
  int arr[MAX_SIZE];
  int front;
  int rear;
} Queue;

// Function to initialize queue
void initializeQueue(Queue *queue)
{
  // Initialize to -1 to indicate empty queue
  queue->front = -1;
  queue->rear = -1;
}

// Function to check if queue is empty
bool isEmpty(Queue *queue)
{
  return (queue->front == -1);
}

// Function to check if queue is full
bool isFull(Queue *queue)
{
  return (queue->rear + 1) % MAX_SIZE == queue->front;
}

// Function to enqueue an element into the queue
void enqueue(Queue *queue, int value)
{
  if (isFull(queue))
  {
    printf("Queue overflow. Cannot enqueue %d.\n", value);
  }
  else
  {
    if (isEmpty(queue))
    {
      queue->front = 0;
    }
    printf("Enqueue element  %d\n ", value);
    queue->rear = (queue->rear + 1) % MAX_SIZE;
    queue->arr[queue->rear] = value;
  }
}

// Function to dequeue an element from the queue
int dequeue(Queue *queue)
{
  if (isEmpty(queue))
  {
    printf("Queue underflow. Cannot dequeue from an empty queue.\n");
    return -1;
  }
  else
  {
    int value = queue->arr[queue->front];
    if (queue->front == queue->rear)
    {
      // Queue is becoming empty, so reset front and rear to -1
      queue->front = -1;
      queue->rear = -1;
    }
    else
    {
      queue->front = (queue->front + 1) % MAX_SIZE;
    }
    return value;
  }
}

// Function to get the value of the front element without removing it
int front(Queue *queue)
{
  if (isEmpty(queue))
  {
    printf("Queue is empty. Cannot get front element.\n");
    return -1;
  }
  else
  {
    return queue->arr[queue->front];
  }
}

void main()
{
  Queue queue;
  initializeQueue(&queue);

  enqueue(&queue, 20);
  enqueue(&queue, 40);
  enqueue(&queue, 60);

  printf("Front element: %d\n", front(&queue));

  printf("Dequeued element: %d\n", dequeue(&queue));
  printf("Dequeued element: %d\n", dequeue(&queue));
}