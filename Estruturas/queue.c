#include <stdio.h>
#include <stdlib.h>
#include "l_list.h"

#define MAX_QUEUE_SIZE 10

typedef struct _queue queue;

struct _queue{
	int current_size;
	node* head;
	node* tail;
};

queue* createQueue(){
	queue *newQueue = malloc(sizeof(queue));
	newQueue->head = NULL;
	newQueue->tail = NULL;
	newQueue->current_size = 0;
	return newQueue;
}

int queueIsEmpty(queue *q){
	return (q->current_size==0);
}

void enqueue(queue *q, int item){
	if (queueIsEmpty(q)){
		node *list = createList();
		list = addToTail(list, item);
		q->head = list;
		q->tail = list;
		q->current_size++;
		return;
	}
	if (q->current_size==MAX_QUEUE_SIZE){
		printf("QUEUE OVERFLOW\n");
	}else{
		addToTail(q->head, item);
		q->current_size++;
		q->tail = tailOfList(q->head);
	}
}

int dequeue(queue *q){
	if (queueIsEmpty(q)){
		printf("Queue Underflow\n");
		return (-100);
	}
	int x;
	x = q->head->item;
	q->head = removeFromHead(q->head);
	q->current_size--;
	return x;
}