#include "queue.c"

typedef struct _queue queue;

queue* createQueue(); // initialize the queue

void enqueue(queue *queue, int item); // enqueue one number in the queue

int dequeue(queue *queue); // return the INT dequeued. If the queue is empty return -100

int queueIsEmpty(queue *queue); // return 1 when the queue is empty and 0 if not