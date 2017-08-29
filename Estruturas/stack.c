#include <stdio.h>
#include <stdlib.h>
#include "l_list.h"

#define INT_MAX 10

typedef struct _stack stack;

struct _stack {
	int size;
	int cap;
	node* top;
};

stack* createStack(){
	stack *s = malloc(sizeof(stack));
	s->size = 0;
	s->cap = INT_MAX;
	s->top = NULL;
	return s;
}

int stackIsEmpty(stack *s){
	return (!s->size);
}

int stackIsFull(stack *s){
	return (s->size==s->cap);
}

void push(stack *s, int item){
	if (stackIsEmpty(s)){
		node *list = malloc(sizeof(node));
		list = createList();
		list = addToHead(list, item);
		s->top = list;
		s->size++;
		return;
	}
	if (stackIsFull(s)) printf("STACK OVERFLOW\n");
	else {
		s->top = addToHead(s->top, item);
		s->size++;
	}
}

int pop (stack *s){

	if (stackIsEmpty(s)){
		printf("STACK UNDERFLOW\n");
		return -100;
	}
	
	int x = s->top->item;
	node *aux = s->top;
	s->top = s->top->next;
	s->size--;
	free(aux);
	return x;
}

int main(){
	int i;
	stack *s = createStack();

	printf("%d ", s->size);
	//printf("%d ", stackIsEmpty(s));
	//printf("%d ", stackIsFull(s));
	//printf("%d\n", s->size == s->cap);

	for (i = 0; i < 15; ++i){
		push(s, i);
		printf("%d ", s->size);
		/*printf("%d ", stackIsEmpty(s));
		printf("%d ", stackIsFull(s));
		printf("%d\n", s->size == s->cap);*/
	}

	printf("----------------------\n\n");

	printf("%d\n", pop(s));
	printf("%d\n", pop(s));
	printf("%d\n", pop(s));
	printf("%d\n", pop(s));
	printf("%d\n", pop(s));
	printf("%d\n", pop(s));
	printf("%d\n", pop(s));
	printf("%d\n", pop(s));
	printf("%d\n", pop(s));
	printf("%d\n", pop(s));
	printf("%d\n", pop(s));
	printf("%d\n", pop(s));
	printf("%d\n", pop(s));
	printf("%d\n", pop(s));


	return 0;
}