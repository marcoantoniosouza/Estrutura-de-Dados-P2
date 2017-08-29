#include <stdio.h>

typedef struct{
	int item;
	struct node* next;
}node;

node* createList(){
	return NULL;
}

node* addToHead(node *head, int item){
	node *newNode;
	newNode = (node*) malloc(sizeof(node));
	newNode->item = item;
	newNode->next = head;
	return newNode;
}

node* addToTail(node *tail, int item){
	node *newNode;
	newNode = (node*) malloc(sizeof(node));
	newNode->item = item;
	newNode->next = NULL;
	tail->next = newNode;
	return newNode;
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
	while (head!=NULL){
		printf("%d ", head->item);	
		head = head->next;
	}
	printf("\n");
	return;
}

int main(){

	node *lista, *tail;

	lista = createList();

	int x, i;

	scanf("%d", &x);
	lista = addToHead(lista, x);
	tail = lista;

	while (scanf("%d", &x)!=EOF){
		tail = addToTail(tail, x);
	}

	lista = invertList(lista);
	
	printList(lista);
	return 0;
}