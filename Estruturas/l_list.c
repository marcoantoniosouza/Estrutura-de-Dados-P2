#include <stdlib.h>

typedef struct _node node;

struct _node{
	int item;
	node* tail;
	node* next;
};

node* createList(){
	return NULL;
}

int isEmpty(node *head){
	return (head==NULL);
}

node* clearList(node *head){
	node* aux = NULL;
	while (head->next != NULL){
		aux = head;
		head = head->next;
		aux->next = NULL;
		free(aux);
	}

	return NULL;
}

node* addToHead(node *head, int item){
	node *newNode;
	newNode = malloc(sizeof(node));
	newNode->item = item;
	newNode->next = head;
	if (isEmpty(head)) newNode->tail = newNode;
	else newNode->tail = head->tail;
	return newNode;
}

node* addToTail(node *head, int item){
	node *newNode;
	newNode = malloc(sizeof(node));
	newNode->item = item;
	newNode->next = NULL;

	if (isEmpty(head)) return (addToHead(head, item));

	node* tail = head->tail;
	tail->next = newNode;
	head->tail = newNode;
	return head;
}

node* removeByPointer(node *head, node *prev, node *current){
	prev->next = current->next;
	free(current);
	return head;
}

node* search(node *head, int item){
	while(head!=NULL){
		if (head->item==item) return head;
		else head = head->next;
	}
	return NULL;
}

node* invertList(node *head){
	int x;
	node *prev, *current;
	prev = head;
	current = head->next;
	while (current!=NULL){
		x = current->item;
		head = removeByPointer(head, prev, current);
		head = addToHead(head, x);
		current = prev->next;
	}
	return head;
}

void printList(node *head){
	if (isEmpty(head)) printf("List Underflow");
	else while (!isEmpty(head)){
		printf("%d ", head->item);
		head = head->next;
	}
	printf("\n");
	return;
}

node* tailOfList(node *head){
	if (isEmpty(head)) return NULL;
	return head->tail;
}

node* removeFromHead(node *head){
	node *aux = malloc(sizeof(node));
	aux = head;
	head = head->next;
	free(aux);
	return head;
}